   M S B A M L   `   `   `  ����   ElGamalSignature!    ElGamalSignature.MainWindow   W SPresentationCore, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=8.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     R NSystem.Xaml, Version=8.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml       � Title$  ElGamal Signature��$	��600��$	��900��.��� $��10q� � ColumnDefinitions �� $��* ��� $��* ��� $��* �.+��� $��0��$��10q�$	��Top=�.+��� $��TẠO KHÓA��$
��Bold"�$��16(�$��0,0,0,10q��� $#��Khóa công khai (p, α, β):��$
��Bold"��� $��Số nguyên tố p =���� -    ��Name$
 txtP���� $��Số (alpha) α =���� -   $ txtAlpha���� $��Số β = α^a mod p =���� -   $ txtBeta���� $��Khóa bí mật (a):��$
��Bold"�$��10,0,0,0q��� $��Số nguyên a =���� -   $
 txtA���� $��Số ngẫu nhiên k =���� -   $
 txtK���� $��Số Y = α^k mod p =���� -   $
 txtY���� -    ��Name$ btnGenerateKeys��$��Tạo khóa ngẫu nhiên��$��0,10,0,0q��� -   $ btnReset��$��Reset dữ liệu��$��0,5,0,0q��� -	   $ btnExit��$��Thoát��$��0,5,0,0q��� $��1��$��10q�$	��Top=�.+��� $��PHÁT SINH CHỮ KÝ��$
��Bold"�$��16(�$��0,0,0,10q��� $��Chọn file văn bản:��$
��Bold"��� -
   $ txtFilePath��$
��Auto=�$��50���� -   $ btnOpenFile��$��	Mở file��$��0,5,0,0q��� $��Nội dung văn bản:��$
��Bold"�$��10,0,0,0q��� -   $ txtFileContent��$	��100�� �� TextWrapping$
 Wrap=� �� AcceptsReturn$
 True���� $��Nội dung chữ ký:��$
��Bold"�$��10,0,0,0q��� -    ��Name$ cmbHashAlgorithm��$��0,5,0,0q�.@��� $��Chọn hàm băm�� �� 
IsSelected$
 True���� $	��MD5���� $��SHA-1���� $��SHA-256���� $��SHA-384���� $��SHA-512���� $��Kết quả:��$
��Bold"�$��10,0,0,0q��� -   $ txtHashResult��$	��100��$
 Wrap=�$
 True���� -   $ btnSignFile��$!��Tiến hành ký văn bản��$��0,10,0,0q��� -   $ btnTransferData��$!��Chuyển tiếp dữ liệu��$��0,5,0,0q��� -   $ btnSaveSignature��$��Lưu file chữ ký��$��0,5,0,0q��� $��2��$��10q�$	��Top=�.+��� $��KIỂM TRA CHỮ KÝ��$
��Bold"�$��16(�$��0,0,0,10q��� $(��"Chọn file văn bản kiểm tra:��$
��Bold"��� -   $ txtVerifyFilePath���� -   $ btnOpenVerifyFile��$��	Mở file��$��0,5,0,0q��� $��Nội dung văn bản:��$
��Bold"�$��10,0,0,0q��� -   $ txtVerifyFileContent��$	��100��$
 Wrap=�$
 True���� $��Chọn file chữ ký:��$
��Bold"�$��10,0,0,0q��� -   $ txtSignatureFilePath���� -   $ btnOpenSignatureFile��$��	Mở file��$��0,5,0,0q��� $��Nội dung chữ ký:��$
��Bold"�$��10,0,0,0q��� -   $ txtSignatureContent��$	��100��$
 Wrap=�$
 True���� -   $ btnVerifySignature��$'��!Tiến hành kiểm tra chữ ký��$��0,10,0,0q�