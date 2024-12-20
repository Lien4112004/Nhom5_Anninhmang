using DocumentFormat.OpenXml.Packaging;
using iText.Kernel.Pdf;
using iText.Kernel.Pdf.Canvas.Parser;
using Microsoft.Win32;
using System.IO;
using System.Numerics;
using System.Text;
using System.Windows;
using System.Windows.Controls;
namespace ElGamalSignature
{
    public partial class MainWindow : Window
    {

        private void CheckKey()
        {
            try
            {
                // Parse and auto-randomize invalid inputs
                BigInteger p = TryParseOrRandomize(txtP.Text, out bool isPValid, () => ElGamalSignature.FindPrime(), "p");
                BigInteger alpha = TryParseOrRandomize(txtAlpha.Text, out bool isAlphaValid, () => ElGamalSignature.GenAlpha(p), "alpha");
                BigInteger a = TryParseOrRandomize(txtA.Text, out bool isAValid, () => ElGamalSignature.GenA(p), "a");
                BigInteger beta = TryParseOrRandomize(txtBeta.Text, out bool isBetaValid, () => ElGamalSignature.PowMod(alpha, a, p), "beta");
                BigInteger k = TryParseOrRandomize(txtK.Text, out bool isKValid, () => ElGamalSignature.GenK(p), "k");
                BigInteger gamal = TryParseOrRandomize(txtY.Text, out bool isYValid, () => ElGamalSignature.PowMod(alpha, k, p), "gamal");

                // Validate p
                if (!ElGamalSignature.CheckPrime((int)p))
                {
                    txtP.Text = ElGamalSignature.FindPrime().ToString();
                    CheckKey();
                    return;
                }

                // Validate a
                if (a < 2 || a > p - 2)
                {
                    txtA.Text = ElGamalSignature.GenA(p).ToString();
                    CheckKey();
                    return;
                }

                // Validate alpha
                if (alpha < 2 || alpha > p - 2)
                {
                    txtAlpha.Text = ElGamalSignature.GenAlpha(p).ToString();
                    CheckKey();
                    return;
                }

                // Validate k
                if (ElGamalSignature.FindGcd((int)k, (int)(p - 1)) != 1 || k < 1 || k > p - 2)
                {
                    txtK.Text = ElGamalSignature.GenK(p).ToString();
                    CheckKey();
                    return;
                }

                // Validate beta
                if (beta != ElGamalSignature.PowMod(alpha, a, p))
                {
                    txtBeta.Text = ElGamalSignature.PowMod(alpha, a, p).ToString();
                    CheckKey();
                    return;
                }

                // Validate gamal
                if (gamal != ElGamalSignature.PowMod(alpha, k, p))
                {
                    txtY.Text = ElGamalSignature.PowMod(alpha, k, p).ToString();
                    CheckKey();
                    return;
                }

                // All checks passed
            }
            catch (Exception ex)
            {
                MessageBox.Show("Lỗi kiểm tra khóa: " + ex.Message, "Lỗi!");
            }
        }


        private void SaveValuesToFile()
        {
            try
            {

                string output = txtHashResult.Text;
                if (string.IsNullOrEmpty(output))
                {
                    MessageBox.Show("Không có dữ liệu để lưu!", "Lỗi!");
                    return;
                }
                string rootPath = AppDomain.CurrentDomain.BaseDirectory;
                string filePath = Path.Combine(rootPath, "output.txt");


                File.WriteAllText(filePath, output);

                // Notify the user
                MessageBox.Show($"Values saved successfully to {filePath}!", "Success");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error saving values to file: " + ex.Message, "Error");
            }
        }

        private BigInteger TryParseOrRandomize(string input, out bool isValid, Func<BigInteger> randomizeFunc, string fieldName)
        {
            if (BigInteger.TryParse(input, out BigInteger result))
            {
                isValid = true;
                return result;
            }

            // Parsing failed, auto-randomize the field
            isValid = false;
            BigInteger randomizedValue = randomizeFunc();
            UpdateFieldValue(fieldName, randomizedValue.ToString());
            return randomizedValue;
        }

        private void UpdateFieldValue(string fieldName, string value)
        {
            switch (fieldName)
            {
                case "p":
                    txtP.Text = value;
                    break;
                case "alpha":
                    txtAlpha.Text = value;
                    break;
                case "beta":
                    txtBeta.Text = value;
                    break;
                case "a":
                    txtA.Text = value;
                    break;
                case "k":
                    txtK.Text = value;
                    break;
                case "gamal":
                    txtY.Text = value;
                    break;
            }
        }
        private string ReadDocxContent(string filePath)
        {
            try
            {
                using (WordprocessingDocument wordDoc = WordprocessingDocument.Open(filePath, false))
                {
                    var body = wordDoc.MainDocumentPart.Document.Body;
                    return body.InnerText;
                }
            }
            catch (Exception ex)
            {
                return $"Lỗi khi đọc file .docx: {ex.Message}";
            }
        }
        private string ReadPdfContent(string filePath)
        {
            try
            {
                using (PdfReader pdfReader = new PdfReader(filePath))
                using (PdfDocument pdfDocument = new PdfDocument(pdfReader))
                {
                    string text = "";
                    for (int i = 1; i <= pdfDocument.GetNumberOfPages(); i++)
                    {
                        text += PdfTextExtractor.GetTextFromPage(pdfDocument.GetPage(i)) + "\n";
                    }
                    return text;
                }
            }
            catch (Exception ex)
            {
                return $"Lỗi khi đọc file PDF: {ex.Message}";
            }
        }

        private void btnOpenFile_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new()
            {
                Filter = "Text Files (*.txt)|*.txt|Word Documents (*.docx)|*.docx|PDF Files (*.pdf)|*.pdf|All Files (*.*)|*.*"
            };


            if (openFileDialog.ShowDialog() == true)
            {
                string filePath = openFileDialog.FileName;
                string fileExtension = Path.GetExtension(filePath);
                txtFilePath.Text = openFileDialog.FileName;

                if (fileExtension.Equals(".docx", StringComparison.OrdinalIgnoreCase))
                {
                    string content = ReadDocxContent(filePath);
                    txtFileContent.Text = content;
                }
                else if (fileExtension.Equals(".pdf", StringComparison.OrdinalIgnoreCase))
                {
                    string content = ReadPdfContent(filePath);
                    txtFileContent.Text = content;
                }
                else
                {
                    txtFileContent.Text = File.ReadAllText(openFileDialog.FileName, Encoding.UTF8);
                }
            }
        }

        private void GenerateSignature()
        {
            // Kiểm tra xem các giá trị khóa đã được nhập hay chưa
            if (string.IsNullOrWhiteSpace(txtP.Text) ||
                string.IsNullOrWhiteSpace(txtAlpha.Text) ||
                string.IsNullOrWhiteSpace(txtBeta.Text) ||
                string.IsNullOrWhiteSpace(txtA.Text) ||
                string.IsNullOrWhiteSpace(txtK.Text) ||
                string.IsNullOrWhiteSpace(txtY.Text))
            {
                MessageBox.Show("Hãy nhập đầy đủ các khóa công khai và bí mật trước khi ký!", "Lỗi!");
                return;
            }

            try
            {
                // Gọi CheckKey để kiểm tra các giá trị khóa
                CheckKey();

                // Chuyển các giá trị khóa từ TextBox sang BigInteger
                BigInteger p = BigInteger.Parse(txtP.Text);
                BigInteger alpha = BigInteger.Parse(txtAlpha.Text);
                BigInteger beta = BigInteger.Parse(txtBeta.Text);
                BigInteger a = BigInteger.Parse(txtA.Text);
                BigInteger k = BigInteger.Parse(txtK.Text);
                BigInteger gamal = BigInteger.Parse(txtY.Text);

                // Kiểm tra nội dung văn bản cần ký
                string text = txtFileContent.Text;
                if (string.IsNullOrWhiteSpace(text))
                {
                    MessageBox.Show("Không để nội dung trống!", "Lỗi!");
                    return;
                }

                // Kiểm tra thuật toán băm
                ComboBoxItem? typeItem = (ComboBoxItem?)cmbHashAlgorithm.SelectedItem;
                string hashMode = typeItem?.Content?.ToString() ?? "";
                if (string.IsNullOrEmpty(hashMode) || hashMode == "Chọn hàm băm")
                {
                    MessageBox.Show("Hãy chọn thuật toán băm trước khi ký!", "Lỗi!");
                    return;
                }

                // Tạo chữ ký
                var signature = ElGamalSignature.CreateSignature(text, hashMode, gamal, a, k, p);

                // Hiển thị chữ ký dưới dạng chuỗi JSON
                txtHashResult.Text = Newtonsoft.Json.JsonConvert.SerializeObject(signature);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Lỗi khi ký: " + ex.Message, "Lỗi!");
            }
        }


        private void VerifySignature()
        {
            CheckKey();

            BigInteger p = BigInteger.Parse(txtP.Text);
            BigInteger alpha = BigInteger.Parse(txtAlpha.Text);
            BigInteger beta = BigInteger.Parse(txtBeta.Text);
            BigInteger a = BigInteger.Parse(txtA.Text);
            BigInteger k = BigInteger.Parse(txtK.Text);
            BigInteger gamal = BigInteger.Parse(txtY.Text);

            string text = txtVerifyFileContent.Text;
            string signature = txtSignatureContent.Text;

            if (string.IsNullOrWhiteSpace(text) || string.IsNullOrWhiteSpace(signature))
            {
                MessageBox.Show("Không để nội dung/chữ ký trống!", "Lỗi!");
                return;
            }

            ComboBoxItem typeItem = (ComboBoxItem)cmbHashAlgorithm.SelectedItem;
            string hashMode = typeItem?.Content?.ToString() ?? "MD5";
            if (string.IsNullOrEmpty(hashMode))
            {
                MessageBox.Show("Chọn thuật toán băm!", "Lỗi!");
                return;
            }

            bool isValid = ElGamalSignature.VerifySignature(text, hashMode, signature, beta, gamal, alpha, p);
            if (isValid)
            {
                MessageBox.Show("Chữ ký khớp, văn bản không bị thay đổi!", "Thông báo!");
            }
            else
            {
                MessageBox.Show("Chữ ký không khớp, văn bản đã bị thay đổi!", "Thông báo!");
            }
        }

        private void btnGenerateKeys_Click(object sender, RoutedEventArgs e)
        {
            List<BigInteger> bigIntegers = ElGamalSignature.CreateKey();
            txtP.Text = bigIntegers[0].ToString();
            txtAlpha.Text = bigIntegers[1].ToString();
            txtA.Text = bigIntegers[2].ToString();
            txtBeta.Text = bigIntegers[3].ToString();
            txtK.Text = bigIntegers[4].ToString();
            txtY.Text = bigIntegers[5].ToString();

        }

        private void btnReset_Click(object sender, RoutedEventArgs e)
        {
            TextBox[] textBoxes = { txtP, txtAlpha, txtBeta, txtA, txtK, txtY, txtFileContent, txtHashResult, txtFilePath, txtSignatureContent, txtVerifyFileContent, txtVerifyFilePath, txtSignatureFilePath };
            foreach (var textBox in textBoxes)
            {
                textBox.Text = "";
            }
            //Rest combobox về mặc định
            cmbHashAlgorithm.SelectedIndex = 0;
        }

        private void btnExit_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void btnSignFile_Click(object sender, RoutedEventArgs e)
        {
            GenerateSignature();
        }

        private void btnTransferData_Click(object sender, RoutedEventArgs e)
        {
            txtSignatureContent.Text = txtHashResult.Text;
        }

        private void btnSaveSignature_Click(object sender, RoutedEventArgs e)
        {
            SaveValuesToFile();
        }

        private void btnOpenVerifyFile_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new()
            {
                Filter = "Text Files (*.txt)|*.txt|Word Documents (*.docx)|*.docx|PDF Files (*.pdf)|*.pdf|All Files (*.*)|*.*"
            };


            if (openFileDialog.ShowDialog() == true)
            {
                string filePath = openFileDialog.FileName;
                string fileExtension = Path.GetExtension(filePath);
                txtVerifyFilePath.Text = openFileDialog.FileName;
                if (fileExtension.Equals(".docx", StringComparison.OrdinalIgnoreCase))
                {
                    string content = ReadDocxContent(filePath);
                    txtVerifyFileContent.Text = content;
                }
                else if (fileExtension.Equals(".pdf", StringComparison.OrdinalIgnoreCase))
                {
                    string content = ReadPdfContent(filePath);
                    txtVerifyFileContent.Text = content;
                }
                else
                {
                    txtVerifyFileContent.Text = File.ReadAllText(openFileDialog.FileName, Encoding.UTF8);
                }
            }
        }

        private void btnOpenSignatureFile_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new()
            {
                Filter = "Text Files|*.txt|All Files|*.docx"
            };
            if (openFileDialog.ShowDialog() == true)
            {
                txtSignatureFilePath.Text = openFileDialog.FileName;
                txtSignatureContent.Text = File.ReadAllText(openFileDialog.FileName, Encoding.UTF8);
            }
        }

        private void btnVerifySignature_Click(object sender, RoutedEventArgs e)
        {
            VerifySignature();
        }

    }
}
