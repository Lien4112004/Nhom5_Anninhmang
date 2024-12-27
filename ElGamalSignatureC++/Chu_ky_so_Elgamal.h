#ifndef CHU_KY_SO_ELGAMAL_H
#define CHU_KY_SO_ELGAMAL_H

#include <QMainWindow>
#include <QTextEdit>

typedef long long ll;

QT_BEGIN_NAMESPACE
namespace Ui { class Chu_ky_so_Elgamal; }
QT_END_NAMESPACE

class Chu_ky_so_Elgamal : public QMainWindow
{
    Q_OBJECT

public:
    Chu_ky_so_Elgamal(QWidget *parent = nullptr);
    ~Chu_ky_so_Elgamal();
    // Khai báo các hàm
    void setupLineEdit();
    void setupLine(bool a);
    void setupVanBanKy(bool a);
    void setupVanBanKT(bool a);
    ll BinhPhuongNhan(ll a, ll b, ll n);
    int LuyThua(int a, int n);
    bool checkPrime(int n);
    void DecToBin(ll a, int *result, int &dem);
    int HexToDec(std::string &hex);
    int HashStringToInt(const QString& str);
    quint8 md5HashToInt(const QByteArray& md5Bytes);
    //quint16 md5HashToInt(const QByteArray& md5Bytes);
    //quint32 md5HashToInt(QByteArray& md5Bytes);
    //int extendedEuclidean(int a, m);
    int ExtendedEuclid(int a, int b, int &x, int &y);
    int TimNghichDao(int a, int n);
    int generateLargePrime();
    bool isPrimitiveRoot(int g, int p);
    int findPrimitiveRoot(int p);
    int generateRandomNumber(int a, int b);
    int GCD(int a, int b);
    QList<std::pair<int, int>>ElGamalEncrypt(const QList<int>& plaintext);
    void readAndDisplayDocx(const QString& filePath, QTextEdit* textEdit);
    void ReadFile(QString &filePath, QTextEdit *textEdit);
    QList<int>convertTextToIntList(const QString& text);
    QList<int>ElGamalDecrypt(const QList<std::pair<int, int>>& ciphertext);
    QList<std::pair<int, int>>convertCiphertextToIntPairs(const QString& ciphertext);
    QString convertToChar(int num);
    int convertToInt(QChar ch);
    QString encodeBase64(const QList<int>& intList);
    QList<int> decodeBase64(const QString& base64String);
    // Khai báo các slots
private slots:
    void generateRandomKey();
    void generateKey();
    void DeleteKey();
    void openFile1();
    void openFile2();
    void openFileKey();
    void TaoChuKy();
    void KiemTra();
    void buttonChuyen();
    //void convertAndDecrypt();
    void LuuChuKy();
    void LuuVanBan();
    void saveFileGM();
    // Khai báo các biến cần dùng

private:
    Ui::Chu_ky_so_Elgamal *ui;
};
#endif // CHU_KY_SO_ELGAMAL_H
