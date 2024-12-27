#include "Chu_ky_so_Elgamal.h"
#include "ui_Chu_ky_so_Elgamal.h"
#include <QPalette>
#include <QLineEdit>
#include <QTextEdit>
#include <bits/stdc++.h>
#include <QCryptographicHash>
#include <iostream>
#include <random>
#include <string>
#include <cmath>
#include <QMessageBox>
#include <utility>
#include <QTextDocument>
#include <QTextCursor>
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QProcess>
#include <QTemporaryFile>
#include <QTextCharFormat>

using namespace std;

Chu_ky_so_Elgamal::Chu_ky_so_Elgamal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Chu_ky_so_Elgamal)
{

    ui->setupUi(this);
    setupLineEdit();
    connect(ui->random, &QPushButton::clicked, this, &Chu_ky_so_Elgamal::generateRandomKey);
    connect(ui->manual, &QPushButton::clicked, this, &Chu_ky_so_Elgamal::generateKey);
    connect(ui->deleteKey, &QPushButton::clicked, this, &Chu_ky_so_Elgamal::DeleteKey);
    connect(ui->fileVB, &QPushButton::clicked, this,&Chu_ky_so_Elgamal::openFile1);
    connect(ui->fileKT, &QPushButton::clicked, this,&Chu_ky_so_Elgamal::openFile2);
    connect(ui->taoChuKy, &QPushButton::clicked, this,&Chu_ky_so_Elgamal::TaoChuKy);
    connect(ui->chuyen, &QPushButton::clicked, this,&Chu_ky_so_Elgamal::buttonChuyen);
    connect(ui->kiemTra, &QPushButton::clicked, this,&Chu_ky_so_Elgamal::KiemTra);
    connect(ui->luuChuky, &QPushButton::clicked, this,&Chu_ky_so_Elgamal::LuuChuKy);
    connect(ui->luuVB, &QPushButton::clicked, this, &Chu_ky_so_Elgamal::LuuVanBan);
    //connect(ui->luuBR, &QPushButton::clicked, this,&Chu_ky_so_Elgamal::saveFileGM);
    connect(ui->fileCK, &QPushButton::clicked, this, &Chu_ky_so_Elgamal::openFileKey);
}


#define ll long long

//#ifndef CONSTEXPR_HASH_MD5_H
#define CONSTEXPR_HASH_MD5_H

#include <array>
#include <iostream>
#include <cstdint>


#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <array>

namespace ConstexprHashes {
// MD5 operations
constexpr uint32_t f(uint32_t x, uint32_t y, uint32_t z) {
    return z ^ (x & (y ^ z));
}

constexpr uint32_t g(uint32_t x, uint32_t y, uint32_t z) {
    return y ^ (z & (x ^ y));
}

constexpr uint32_t h(uint32_t x, uint32_t y, uint32_t z) {
    return x ^ y ^ z;
}

constexpr uint32_t i(uint32_t x, uint32_t y, uint32_t z) {
    return y ^ (x | ~z);
}

constexpr uint32_t step_helper(uint32_t fun_val, uint32_t s, uint32_t b) {
    return ((fun_val << s) | ((fun_val & 0xffffffff) >> (32 - s))) + b;
}

// Generic application of the "fun" function

template<typename Functor>
constexpr uint32_t step(Functor fun, uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t t, uint32_t s) {
    return step_helper(a + fun(b, c, d) + x + t, s, b);
}

// Retrieve the nth uint32_t in the buffer

constexpr uint32_t data32(const char* data, size_t n) {
    return (static_cast<uint32_t>(data[n * 4]) & 0xff) |
           ((static_cast<uint32_t>(data[n * 4 + 1]) << 8) & 0xff00) |
           ((static_cast<uint32_t>(data[n * 4 + 2]) << 16) & 0xff0000) |
           ((static_cast<uint32_t>(data[n * 4 + 3]) << 24) & 0xff000000);
}

// Constants

constexpr std::array<uint32_t, 64> md5_constants = {{
    0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,0xf57c0faf,0x4787c62a,
    0xa8304613,0xfd469501,0x698098d8,0x8b44f7af,0xffff5bb1,0x895cd7be,
    0x6b901122,0xfd987193,0xa679438e,0x49b40821,0xf61e2562,0xc040b340,
    0x265e5a51,0xe9b6c7aa,0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,
    0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,0xa9e3e905,0xfcefa3f8,
    0x676f02d9,0x8d2a4c8a,0xfffa3942,0x8771f681,0x6d9d6122,0xfde5380c,
    0xa4beea44,0x4bdecfa9,0xf6bb4b60,0xbebfbc70,0x289b7ec6,0xeaa127fa,
    0xd4ef3085,0x04881d05,0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,
    0xf4292244,0x432aff97,0xab9423a7,0xfc93a039,0x655b59c3,0x8f0ccc92,
    0xffeff47d,0x85845dd1,0x6fa87e4f,0xfe2ce6e0,0xa3014314,0x4e0811a1,
    0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391
}};

constexpr std::array<size_t, 64> md5_shift = {{
    7,12,17,22,7,12,17,22,7,12,17,22,7,12,17,22,5,9,14,20,5,9,14,20,
    5,9,14,20,5,9,14,20,4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23,
    6,10,15,21,6,10,15,21,6,10,15,21,6,10,15,21
}};

constexpr std::array<size_t, 64> md5_indexes = {{
    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,1,6,11,0,5,10,15,4,
    9,14,3,8,13,2,7,12,5,8,11,14,1,4,7,10,13,0,3,6,9,12,15,2,
    0,7,14,5,12,3,10,1,8,15,6,13,4,11,2,9
}};

// Functions applied

constexpr std::array<decltype(f)*, 4> md5_functions = {{
    f, g, h, i
}};

/******************** Initial buffer generators ***********************/

// index_tuples to fill the initial buffer

template<size_t... indexes>
struct index_tuple {};

template<size_t head, size_t... indexes>
struct index_tuple<head, indexes...> {
    typedef typename index_tuple<head-1, head-1, indexes...>::type type;
};

template<size_t... indexes>
struct index_tuple<0, indexes...> {
    typedef index_tuple<indexes...> type;
};

template<typename... Args>
struct index_tuple_maker {
    typedef typename index_tuple<sizeof...(Args)>::type type;
};

/* This builds the buffer.
    *
    * For indexes < string length: output the ith character in the string.
    * For indexes > string length: output 0.
    * If index == string length: output 0x80
    * If index == 56: output string length << 3
    *
    */

template<size_t n, size_t i>
struct buffer_builder {
    static constexpr char make_value(const char *data) {
        return (i <= n) ? data[i] : 0;
    }
};

template<size_t n>
struct buffer_builder<n, n> {
    static constexpr char make_value(const char *) {
        return 0x80;
    }
};

template<size_t n>
struct buffer_builder<n, 56> {
    static constexpr char make_value(const char *) {
        return -1;//n << 3;
    }
};

/*
    * Simple array implementation, which allows constexpr access to its
    * elements.
    */

template<typename T, size_t n>
struct constexpr_array {
    const T array[n];

    constexpr const T *data() const {
        return array;
    }
};

typedef constexpr_array<char, 64> buffer_type;

template<size_t n, size_t... indexes>
constexpr buffer_type make_buffer_helper(const char (&data)[n], index_tuple<indexes...>) {
    return buffer_type{{ buffer_builder<n - 1, indexes>::make_value(data)... }};
}

// Creates the actual buffer

template<size_t n>
constexpr buffer_type make_buffer(const char (&data)[n]) {
    return make_buffer_helper(data, index_tuple<64>::type());
}



/************************ MD5 impl ***************************/

typedef std::array<char, 16> md5_type;

/*
    * There are 64 steps. The ith step has the same structure as the ith + 4 step.
    * That means that we can repeat the same structure, and pick the appropiate
    * constants and function to apply, depending on the step number.
    */

template<size_t n, size_t rot>
struct md5_step;

/*
    * Nasty, but works. Convert the MD5 result(which is 4 uint32_t), to
    * a std::array<char, 16>.
    */


constexpr md5_type make_md5_result(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    typedef md5_type::value_type value_type;
    return md5_type{{
        static_cast<value_type>(a & 0xff), static_cast<value_type>((a & 0xff00) >> 8),
        static_cast<value_type>((a & 0xff0000) >> 16), static_cast<value_type>((a & 0xff000000) >> 24),

        static_cast<value_type>(b & 0xff), static_cast<value_type>((b & 0xff00) >> 8),
        static_cast<value_type>((b & 0xff0000) >> 16), static_cast<value_type>((b & 0xff000000) >> 24),

        static_cast<value_type>(c & 0xff), static_cast<value_type>((c & 0xff00) >> 8),
        static_cast<value_type>((c & 0xff0000) >> 16), static_cast<value_type>((c & 0xff000000) >> 24),

        static_cast<value_type>(d & 0xff), static_cast<value_type>((d & 0xff00) >> 8),
        static_cast<value_type>((d & 0xff0000) >> 16), static_cast<value_type>((d & 0xff000000) >> 24),
    }};
}

template<>
struct md5_step<64, 0> {
    static constexpr md5_type do_step(const char *, uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
        return make_md5_result(a + 0x67452301, b + 0xefcdab89, c + 0x98badcfe, d + 0x10325476);
    }
};

template<size_t n>
struct md5_step<n, 3> {
    static constexpr md5_type do_step(const char *data, uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
        return md5_step<n + 1, (n + 1) % 4>::do_step(data, a, step(md5_functions[n / 16], b, c, d, a, data32(data, md5_indexes[n]), md5_constants[n], md5_shift[n]), c, d);
    }
};

template<size_t n>
struct md5_step<n, 2> {
    static constexpr md5_type do_step(const char *data, uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
        return md5_step<n + 1, (n + 1) % 4>::do_step(data, a, b, step(md5_functions[n / 16], c, d, a, b, data32(data, md5_indexes[n]), md5_constants[n], md5_shift[n]), d);
    }
};

template<size_t n>
struct md5_step<n, 1> {
    static constexpr md5_type do_step(const char *data, uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
        return md5_step<n + 1, (n + 1) % 4>::do_step(data, a, b, c, step(md5_functions[n / 16], d, a, b, c, data32(data, md5_indexes[n]), md5_constants[n], md5_shift[n]));
    }
};

template<size_t n>
struct md5_step<n, 0> {
    static constexpr md5_type do_step(const char *data, uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
        return md5_step<n + 1, (n + 1) % 4>::do_step(data, step(md5_functions[n / 16], a, b, c, d, data32(data, md5_indexes[n]), md5_constants[n], md5_shift[n]), b, c, d);
    }
};

template<size_t n>
constexpr md5_type md5(const char (&data)[n]) {
    return md5_step<0, 0>::do_step(make_buffer(data).data(), 0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476);
}




// Convert md5_type to hexadecimal string
std::string md5_to_string(const std::string& input) {
    // Create a buffer that is at least 64 bytes long
    char buffer[64] = {0};
    input.copy(buffer, input.size());

    // Calculate MD5 hash
    auto hash = md5(buffer);

    // Convert the hash to a hexadecimal string
    std::ostringstream oss;
    for (auto i : hash) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (static_cast<int>(i) & 0xff);
    }
    return oss.str();
}
} // namespace ConstexprHashes
//CONSTEXPR_HASH_MD5_H















Chu_ky_so_Elgamal::~Chu_ky_so_Elgamal()
{
    delete ui;
}
// Cài đặt chỉ đọc cho một số lineEdit và textEdit
void Chu_ky_so_Elgamal::setupLineEdit()
{
    ui->yTxt->setReadOnly(true);
   // ui->editKpub->setReadOnly(true);
   // ui->editKpr->setReadOnly(true);
    ui->chuKy_1->setReadOnly(true);
    //ui->chuKy_2->setReadOnly(false);
    // Không cho con trỏ hoạt động trong vùng này!
    ui->yTxt->setCursor(Qt::ArrowCursor);
  //  ui->editKpub->setCursor(Qt::ArrowCursor);
   // ui->editKpr->setCursor(Qt::ArrowCursor);
    ui->chuKy_1->setCursor(Qt::ArrowCursor);
    //ui->chuKy_2->setCursor(Qt::ArrowCursor);
}
void  Chu_ky_so_Elgamal::setupLine(bool a)
{
    ui->pTxt->setReadOnly(a);
    ui->gTxt->setReadOnly(a);
    ui->xTxt->setReadOnly(a);
}
void  Chu_ky_so_Elgamal::setupVanBanKy(bool a)
{
    ui->vanBanKy->setReadOnly(a);
}
void  Chu_ky_so_Elgamal::setupVanBanKT(bool a)
{
    ui->vanBanKT->setReadOnly(a);
}


// Các thuật toán cần dùng:

// void Chu_ky_so_Elgamal::DecToBin(ll a, int *result, int &dem){
//     while (a > 0) {
//         result[dem] = a % 2;
//         a /= 2;
//         dem++;
//     }
// }

// int Chu_ky_so_Elgamal::HexToDec(string &hex){
//     int dec = 0;
//     int power = 1;
//     for (int i = hex.size() - 1; i >= 0; --i) {
//         char c = hex[i];
//         if (c >= '0' && c <= '9') {
//             dec += (c - '0') * power;
//         } else if (c >= 'A' && c <= 'F') {
//             dec += (c - 'A' + 10) * power;
//         } else if (c >= 'a' && c <= 'f') {
//             dec += (c - 'a' + 10) * power;
//         }
//         power *= 16;
//     }
//     return dec;
// }

// Thuật toán bình phương và nhân để tìm lũy thừa lớn: Hàm tính a^b mod n
ll Chu_ky_so_Elgamal:: BinhPhuongNhan(ll a, ll b, ll n) {
    ll f = 1;
    while (b > 0) {
        if (b & 1) {
            f = (f * a) % n;
        }
        a = (a * a) % n;
        b >>= 1;
    }
    return f;
}

//Thuat toan binh phuong nhan tinh a^b mod n
// ll Chu_ky_so_Elgamal:: power(ll a, ll b, ll n) {
//     int dem = 0;
//     int *bin = new int[dem];
//     DecToBin(b, bin, dem);

//     ll f = 1;
//     for (int i = dem - 1; i >= 0; i--) {
//         f =(f * f) % n;
//         if(bin[i] == 1)
//             f = (f * a) % n;
//     }
//     return f;
// }


    // Hàm kiểm tra một số có phải nguyên tố hay không
    // bool Chu_ky_so_Elgamal::checkPrime(int n) {
    //     if (n <= 1) return false;
    //     if (n <= 3) return true;
    //     if (n % 2 == 0 || n % 3 == 0) return false;
    //     for (int i = 5; i * i <= n; i += 6) {
    //         if (n % i == 0 || n % (i + 2) == 0) return false;
    //     }
    //     return true;
    // }


    bool Chu_ky_so_Elgamal::checkPrime(int n){
        if(n < 2){
            return false;
        }
        int count = 0;
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                count++;
            }
        }
        if(count == 0)
            return true;
        else
            return false;
    }

    // Hàm sinh ngẫu nhiên một số nguyên tố
    int Chu_ky_so_Elgamal::generateLargePrime() {

        bool isPrimeNumber = false;
        int prime;

        while (!isPrimeNumber) {
            prime = generateRandomNumber(100,1000);
            if (checkPrime(prime)) {
                isPrimeNumber = true;
            }
        }

        return prime;
    }
    // Sinh một số nguyên ngẫu nhiên trong khoảng từ a đến b
    int Chu_ky_so_Elgamal::generateRandomNumber(int a, int b) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(a, b);
        return dist(gen);
    }
    // Kiểm tra xem một số có phải là phần tử nguyên thủy của một số nguyên tố hay không
    bool Chu_ky_so_Elgamal::isPrimitiveRoot(int g, int p) {
        std::vector<bool> seen(p, false);
        int order = 0;

        for (int i = 1; i < p; ++i) {
            int val = BinhPhuongNhan(g, i, p);
            if (seen[val]) {
                return false;  // Không phải phần tử nguyên thủy
            }
            seen[val] = true;
            ++order;
        }

        // Một phần tử nguyên thủy phải có bậc là phi(p) = p - 1
        return order == p - 1;
    }


    //Tìm phần tử nguyên thủy của một số nguyên tố
    int Chu_ky_so_Elgamal::findPrimitiveRoot(int p) {
        for (int g = 2; g < p; ++g) {
            if (isPrimitiveRoot(g, p)) {
                return g;
            }
        }
        return -1;  // Không tìm thấy phần tử nguyên thủy
    }

    //Tim phan tu nguyen thuy
    // int Chu_ky_so_Elgamal::findPrimitiveRoot(int p) {
    //     int g;

    //     do{
    //         g = generateRandomNumber(1, p);
    //     }while(!isPrimitiveRoot(g,p));

    //     return g;
    // }


    //Thuật toán Euclid mở rộng để tìm phần tử nghịch đảo của r1 mod r0
    // int Chu_ky_so_Elgamal::extendedEuclidean(int a, int m) {
    //     int m0= m;
    //     int y =0, x =1;
    //     if(m==1){
    //         return 0;
    //     }
    //     while(a>1){
    //         int q = a/m;
    //         int t = m;
    //         m = a%m;
    //         a =t;
    //         t=y;
    //         y = x-q*y;
    //         x=t;
    //     }
    //     if(x<0){
    //         x+=m0;
    //     }
    //     return x;
    // }

    //Thuat toan tinh luy thua
    int Chu_ky_so_Elgamal::LuyThua(int a, int n)
    {
        int res = 1;
        for(int i = 1; i <= n ;i++)
            res *= a;

        return res;
    }

    //Thuật toán Euclid mở rộng
    int Chu_ky_so_Elgamal::ExtendedEuclid(int a, int b, int &x, int &y){
        if(b == 0){
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1;
        int d = ExtendedEuclid(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);

        return d;
    }

    //Thuật toán tìm phần tử nghịch đảo
    int Chu_ky_so_Elgamal::TimNghichDao(int a, int n) {
        int x, y;
        int d = ExtendedEuclid(a, n, x, y);
        if(d != 1)
            return 0;
        else
            return (x % n + n) % n;
    }

    // Thuật toán tìm UCLN của hai số
    int Chu_ky_so_Elgamal::GCD(int a, int b) {
        while (b != 0) {
            int temp = a;
            a = b;
            b = temp % b;
        }
        return a;
    }
// Slot tạo khóa tự động.
void Chu_ky_so_Elgamal:: generateRandomKey()
{
    int p, g ;
    do{
        // Chọn số nguyên tố lớn p
        p = generateLargePrime();

        // Chọn một số nguyên g là phần tử sinh trong trường modulo p
        g = findPrimitiveRoot(p);
    }while(g == -1);

    // // Chọn khóa bí mật
    int x = generateRandomNumber(1, p);

    // // // Tính khóa công khai
    int y = BinhPhuongNhan(g, x, p);

    // p = 463; g = 2;
    // int x = 211;
    // int y = BinhPhuongNhan(g, x, p);

    // Hiển thị các giá trị trên giao diện
    ui->pTxt->setText(QString::number(p));
    ui->gTxt->setText(QString::number(g));
    ui->xTxt->setText(QString::number(x));
    ui->yTxt->setText(QString::number(y));
    //ui->editKpr->setText(QString::number(A));
    //ui->editKpub->setText(QString::number(p) + "; " + QString::number(Alpha) + "; " + QString::number(Beta));
    setupLine(true);
}

// Slot tạo key khi nhập
void Chu_ky_so_Elgamal::generateKey()
{
    // Mở chế độ cho nhập:
    //setupLine(false);

    // Kiểm tra xem người dùng đã nhập đủ các biến hay chưa


    // Lấy giá trị P từ nguồn dữ liệu người dùng
    bool ok1, ok2, ok3;
    int p = ui->pTxt->text().toInt(&ok1);
    int g = ui->gTxt->text().toInt(&ok2);
    int x = ui->xTxt->text().toInt(&ok3);

    if(!ok1 && !ok2 && !ok3){
        QMessageBox::information(this, "Thông báo", "Cần nhập đầy đủ các giá trị");
        return;
    }

    // Kiểm tra xem người dùng đã nhập đủ biến P, g và x hay chưa
    if (!ok1) {
        QMessageBox::information(this, "Thông báo", "<html><b>Chưa nhập giá trị P!</b></html>");
        return;
    }

    if (!ok2) {
        QMessageBox::information(this, "Thông báo", "<html><b>Chưa nhập giá trị g!</b></html>");
        return;
    }


    if (!ok3) {
        QMessageBox::information(this, "Thông báo", "<html><b>Chưa nhập giá trị x!</b></html>");
        return;
    }


    //Kiem tra p co lon qua k
    if(p > 1000){
        QMessageBox::information(this, "Thông báo", "<html><b>Giá trị của P quá lớn (1 < p < 1000</b></html>");
        return;
    }


    // Kiểm tra tính nguyên tố của P

    if(!checkPrime(p)){
        QMessageBox::information(this, "Thông báo", "P phải là số nguyên tố");
        return;
    }


    // Kiểm tra  g
    if(!isPrimitiveRoot(g, p)){
        QMessageBox::information(this, "Thông báo", "g phải là phần tử nguyên thủy của p");
        return;
    }


    // Kiểm tra giá trị x
    if (x <= 1 || x >= p) {
        QMessageBox::information(this, "Thông báo", "x phải nằm trong khoảng (1, p)");
        return;
    }

    int y = BinhPhuongNhan(g, x, p);

    // Nếu tất cả các kiểm tra trên đều thành công, thực hiện phần còn lại của hàm
    ui->pTxt->setText(QString::number(p));
    ui->gTxt->setText(QString::number(g));
    ui->xTxt->setText(QString::number(x));
    ui->yTxt->setText(QString::number(y));
    //ui->editKpr->setText(QString::number(userInputAa));
    // ui->editKpub->setText(QString::number(userInputPp) + "; " + QString::number(userInputAlphal) + "; " + QString::number(power(userInputAlphal, userInputAa, userInputPp)));
    setupLine(true);
}

/* void Chu_ky_so_Elgamal:: generateKey()
// {
// // Mở chế độ cho nhập:
//     setupLine(false);

//     // Kiểm tra xem người dùng đã nhập đủ các biến hay chưa
//     bool isInputValid = true;

//     // Lấy giá trị P từ nguồn dữ liệu người dùng
//     bool ok1, ok2, ok3;
//     int userInputPp = ui->pTxt->text().toInt(&ok1);
//     int userInputAlphal = ui->gTxt->text().toInt(&ok2);
//     int userInputAa = ui->xTxt->text().toInt(&ok3);

//     // Kiểm tra xem người dùng đã nhập đủ biến P, Alpha và A hay chưa
//     if (!ok1) {
//         QMessageBox::information(this, "Warning", "<html><b>Chưa nhập giá trị P!</b></html>");
//         isInputValid = false;
//     }
//     else{
//         if(userInputPp < 8000){
//                QMessageBox::information(this, "Warning", "<html><b>Giá trị của P chưa đủ lớn! (P>8000)</b></html>");
//                isInputValid = false;
//        }
//    }

//     if (!ok2) {
//         QMessageBox::information(this, "Warning", "<html><b>Chưa nhập giá trị Alpha!</b></html>");
//         isInputValid = false;
//     }

//     if (!ok3) {
//         QMessageBox::information(this, "Warning", "<html><b>Chưa nhập giá trị A!</b></html>");
//         isInputValid = false;
//     }

//     // Kiểm tra xem tất cả các biến đã được nhập đúng định dạng hay chưa
//     if (!isInputValid) {
//         return;
//     }

//     // Kiểm tra tính nguyên tố của P
//     if (!checkPrime(userInputPp)) {
//         QMessageBox::information(this, "Warning", "<html><b>Giá trị P không phải là số nguyên tố!</b></html>");
//         return;
//     }

//     // Kiểm tra tính nguyên sinh của Alpha
//     if (!isPrimitiveRoot(userInputAlphal, userInputPp)) {
//         QMessageBox::information(this, "Warning", "<html><b>Alpha không phải là phần tử nguyên sinh của số nguyên tố P!</b></html>");
//         return;
//     }

//     // Kiểm tra giá trị A
//     if (userInputAa <= 0 || userInputAa >= userInputPp - 1) {
//         QMessageBox::information(this, "Warning", "<html><b>Số bí mật thứ nhất không thỏa mãn!</b></html>");
//         return;
//     }

//     // Nếu tất cả các kiểm tra trên đều thành công, thực hiện phần còn lại của hàm
//     ui->pTxt->setText(QString::number(userInputPp));
//     ui->gTxt->setText(QString::number(userInputAlphal));
//     ui->xTxt->setText(QString::number(userInputAa));
//     ui->yTxt->setText(QString::number(BinhPhuongNhan(userInputAlphal, userInputAa, userInputPp)));
//     //ui->editKpr->setText(QString::number(userInputAa));
//    // ui->editKpub->setText(QString::number(userInputPp) + "; " + QString::number(userInputAlphal) + "; " + QString::number(power(userInputAlphal, userInputAa, userInputPp)));
//     setupLine(true);
// } */

// Slot khi xóa khóa
void Chu_ky_so_Elgamal:: DeleteKey()
{
    ui->pTxt->clear();
    ui->gTxt->clear();
    ui->xTxt->clear();
    ui->yTxt->clear();
    //ui->editKpub->clear();
   // ui->editKpr->clear();
    //ui->editK->clear();
    ui->chuKy_1->clear();
    ui->chuKy_2->clear();
    ui->vanBanKy->clear();
    ui->vanBanKT->clear();
    setupLine(false);
    setupVanBanKT(false);
    setupVanBanKy(false);
}

// Hàm đọc và hiện thị nội dung của 1 file    // bo
void Chu_ky_so_Elgamal::readAndDisplayDocx(const QString& filePath, QTextEdit* textEdit)
{
    // Tạo tệp tin tạm để lưu nội dung đã chuyển đổi
    QString tempFilePath = QDir::tempPath() + "/temp.html";

    // Chuyển đổi tệp tin .docx sang HTML bằng Pandoc
    QString pandocPath = "C:\\Program Files\\pandoc\\pandoc.exe";
    QStringList arguments;
    arguments << "-s" << filePath << "-o" << tempFilePath;

    QProcess process;
    process.setProgram(pandocPath);
    process.setArguments(arguments);
    process.start();
    process.waitForFinished();
    // Không chuyển đổi được sang HTML thì đọc trực tiếp trong lớp QtEdit
    if (process.exitCode() != 0)
    {
        // Đọc nội dung của file .docx
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly))
        {
               QByteArray docxData = file.readAll();
               file.close();

               // Hiển thị nội dung thuần túy trong QTextEdit
               QString plainText = QString::fromUtf8(docxData);
               textEdit->setPlainText(plainText);
        }
    }else{
        // Đọc nội dung HTML đã chuyển đổi và hiển thị trong QTextEdit
        QFile file(tempFilePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
               QTextStream stream(&file);
               QString html = stream.readAll();

               // Hiển thị HTML trong QTextEdit
               textEdit->setHtml(html);

               file.close();
        }

        // Xóa tệp tin tạm
        QFile::remove(tempFilePath);
    }
}

void Chu_ky_so_Elgamal::ReadFile(QString &filePath, QTextEdit *textEdit)
{
        QFile file(filePath);
        if(file.open(QIODevice::ReadOnly)){
            QTextStream stream(&file);
            QString fileData;
            while (stream.atEnd() == false) {
                fileData += stream.readLine() + "\n";
            }
            textEdit->setText(fileData);
        }
}

// Xây dựng slot chọn file để đọc và hiển thị nội dung vào QTextEdit van ban ky
// void Chu_ky_so_Elgamal::openFile1()
// {
//     QString filePath = QFileDialog::getOpenFileName(this, "Chọn file", "", "Text Files (*.txt *.docx *.doc)");

//     if (!filePath.isEmpty())
//     {
//         readAndDisplayDocx(filePath, ui->vanBanKy);
//         setupVanBanKy(true);
//     }
// }

void Chu_ky_so_Elgamal::openFile1()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Chọn file", "", "Text Files (*.txt *.docx *.doc)");

    if (!filePath.isEmpty())
    {
        ReadFile(filePath, ui->vanBanKy);
        //setupVanBanKy(true);
    }
}

// Xây dựng slot chọn file để đọc và hiển thị nội dung vào QTextEdit textEdit_GM1
void Chu_ky_so_Elgamal::openFile2()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Chọn file", "", "Text Files (*.txt *.docx *.doc)");

    if (!filePath.isEmpty())
    {
        ReadFile(filePath, ui->vanBanKT);
        //setupVanBanKy(true);
    }
}

void Chu_ky_so_Elgamal::openFileKey()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Chọn file", "", "Text Files (*.txt *.docx *.doc)");

    if (!filePath.isEmpty())
    {
        ReadFile(filePath, ui->chuKy_2);
        //setupVanBanKy(true);
    }
}
// Thuật toán mã hóa Elgamal
// QList<std::pair<int, int>> Chu_ky_so_Elgamal::ElGamalEncrypt(const QList<int>& plaintext)
// {
//     bool ok, ok1, ok2, ok3;
//     //int k = ui->editK->text().toInt(&ok);
//     //int p = ui->editP->text().toInt(&ok1);
//     //int g = ui->editAlpha->text().toInt(&ok2);
//     //int beta = ui->editBeta->text().toInt(&ok3);

//     QList<std::pair<int, int>> encryptedList;

//     for (int num : plaintext)
//     {
//         //int y1 = power(g, k, p);
//         //int y2 = (num * power(beta, k, p)) % p;

//         //encryptedList.append(std::make_pair(y1, y2));
//     }

//     return encryptedList;
// }
void Chu_ky_so_Elgamal::buttonChuyen()
{
    QString vanBanKy = ui->vanBanKy->toPlainText();
    QString chuKy1 = ui->chuKy_1->toPlainText();
    ui->vanBanKT->setPlainText(vanBanKy);
    ui->chuKy_2->setText(chuKy1);
    setupVanBanKy(true);
}
// Thuật toán giải mã Elgamal
// QList<int> Chu_ky_so_Elgamal::ElGamalDecrypt(const QList<std::pair<int, int>>& ciphertext)
// {
//     bool ok, ok1;
//     int a = ui->xTxt->text().toInt(&ok);
//     int p = ui->pTxt->text().toInt(&ok1);
//     QList<int> decryptedList;

//     for (const auto& pair : ciphertext)
//     {
//         int y1 = pair.first;
//         int y2 = pair.second;

//         // Giải mã cặp (y1, y2)
//         int num = (y2 * extendedEuclidean(power(y1, a, p), p)) % p;
//         decryptedList.append(num);
//     }

//     return decryptedList;
// }

// quint32 Chu_ky_so_Elgamal::md5HashToInt(QByteArray& md5Bytes) {
//     quint32 intValue = 0;
//     for (int i = 0; i < md5Bytes.size(); i++) {
//         intValue += (md5Bytes[i] & 0xFF) << (i % 4) * 8;
//     }
//     return intValue % (1 << 24); // reduce to a 24-bit range
// }

// quint16 Chu_ky_so_Elgamal::md5HashToInt(const QByteArray &md5Bytes)
// {
//     quint16 intValue = 0;
//     for (int i = 0; i < 2; i++) { // take only the first 2 bytes
//         intValue += (md5Bytes[i] & 0xFF) << (i % 2) * 8;
//     }
//     return intValue;
// }

quint8 Chu_ky_so_Elgamal::md5HashToInt(const QByteArray& md5Bytes) {
    quint8 intValue = 0;
    for (int i = 0; i < md5Bytes.size(); i++) {
        intValue += (md5Bytes[i] & 0xFF);
    }
    return intValue % 256; // reduce to a range of 0 to 255
}

// Tạo chữ ký
void Chu_ky_so_Elgamal::TaoChuKy()
{
    // bool isInputValid = true;
    // bool isInputValid2 = true;
    //bool ok, ok1;
    int p = ui->pTxt->text().toInt(); //so nguyen to p

    int g = ui->gTxt->text().toInt(); // phan tu nguyen thuy g

    // chon so k ngau nhien 1 < k < p -1 va gcd(k, p-1) = 1
    int k;
    do{
        k = generateRandomNumber(1, p - 1);
    }while(GCD(k, p - 1) != 1);


    // if (!ok1) {
    //     QMessageBox::information(this, "Warning", "<html><b>Chưa tạo khóa!</b></html>");
    //     isInputValid = false;
    // }
    // if (!isInputValid) {
    //     return;
    // }

    // if (!isInputValid2) {
    //     return;
    // }
    // if (k <= 0 || k >= p - 1) {
    //     QMessageBox::information(this, "Warning", "<html><b>Số bí mật thứ hai không thỏa mãn!</b></html>");
    //     return;
    // }
    //QString vanBanKy = ui->vanBanKy->toPlainText().replace("\n", "\\n"); // khi sử dụng mỗi toPlainText thì dấu xuống dòng sẽ bị bỏ thay vào là khoảng trắng
    // Chuyển đổi văn bản thành một dãy số nguyên
    //QList<int> intList = convertTextToIntList(plaintext);
    // Mã hóa dãy số nguyên sử dụng ElGamal
   // QList<std::pair<int, int>> encryptedData = ElGamalEncrypt(intList);
    // Tạo chuỗi mã hóa để hiển thị
    // QString ciphertext;
    // QList<int> list;
    // for (const auto& pair : encryptedData) {
    //     list.append(pair.first);
    //     list.append(pair.second);
    // }
    // ciphertext = encodeBase64(list);
    // Hiển thị chuỗi mã hóa trong textEdit_MH2
    //->textEdit_MH2->setPlainText(ciphertext);
    //int k2 = ui->pTxt->text().toInt() - 2;

    //x la khoa bi mat
    int x = ui->xTxt->text().toInt();

    QString vanBanKy = ui->vanBanKy->toPlainText();
    if(vanBanKy.isEmpty()){
        QMessageBox::information(this, "Thông báo", "<html><b>Chưa nhập văn bản!</b></html>");
        return;
    }

    // Bam van ban
    QByteArray bytes = QCryptographicHash::hash(vanBanKy.toUtf8(),QCryptographicHash::Md5);

    //Chuyen chuoi bam thanh so

    quint8 intValue = md5HashToInt(bytes);

    //k2 la nghich dao cua k
    int k2 = TimNghichDao(k, p - 1);


    int r = BinhPhuongNhan(g, k, p); // Tinh thanh phan thu 1
    int s = ((k2 * (intValue - x * r)) % (p - 1) + (p - 1) ) % (p - 1); // Tinh thanh phan thu 2

    ui->chuKy_1->setPlainText(QString::number(r) + ", " + QString::number(s));
    //QMessageBox::information(this, "Thông báo", QString(bytes.toHex()) + "\n" + QString::number(intValue));
    setupLine(true);
    setupVanBanKy(true);
    QMessageBox::information(this, "Thông báo", "Ký thành công");



}

//Kiem tra 1
// void Chu_ky_so_Elgamal::KiemTra()
// {
//     QStringList chuKy_1 = ui->chuKy_1->toPlainText().split(",");
//     QStringList chuKy_2 = ui->chuKy_2->text().split(",");
//     int r1 =  chuKy_1[0].toInt();
//     int s1 = chuKy_1[1].toInt();
//     int r2 = chuKy_2[0].toInt();
//     int s2 = chuKy_2[1].toInt();

//     if(r1 == r2 && s1 == s2)
//         QMessageBox::information(this, "Thong bao", "Chu ky dung");
//     else
//         QMessageBox::warning(this, "Loi", "Chu ky gia mao");
// }



//Kiem tra 2
void Chu_ky_so_Elgamal::KiemTra()
{
    int g = ui->gTxt->text().toInt();
    int p = ui->pTxt->text().toInt();
    QString vanBanKy = ui->vanBanKy->toPlainText();
    QString vanBanKT = ui->vanBanKT->toPlainText();

    //Bam van ban ky
    QByteArray bytes1 = QCryptographicHash::hash(vanBanKy.toUtf8(),QCryptographicHash::Md5);

    //Bam van ban kiem tra
    QByteArray bytes2 = QCryptographicHash::hash(vanBanKT.toUtf8(), QCryptographicHash::Md5);

    //Chuyen chuoi bam van ban ky thanh so
    quint8 intValue1 = md5HashToInt(bytes1);

    //chuyen chuoi bam van ban ktra thanh so
    quint8 intValue2 = md5HashToInt(bytes2);


    //Tinh thanh phan thu nhat: u = g^H(m) mod p
    int u = BinhPhuongNhan(g, intValue2, p);

    //Lay khoa cong khai
    int y = ui->yTxt->text().toInt();

    //Lay chu ky o o chuky2
    QStringList chuKy = ui->chuKy_2->toPlainText().split(",");

    // Lay r
    int r = chuKy[0].toInt();

    //Lay s
    int s = chuKy[1].toInt();

    //Tinh thanh phan thu 2: y^r * r^s mod p
    int v = ( BinhPhuongNhan(y, r, p) * BinhPhuongNhan(r, s, p) ) % p;

    if(intValue1 == intValue2)
    {
        if(u == v)
            QMessageBox::information(this, "Thông báo", "Văn bản không bị sửa đổi\n");
        else
            QMessageBox::warning(this, "Thông báo", "Chữ ký giả mạo\n");
    }
    else
        QMessageBox::warning(this, "Lỗi", "Văn bản đã bị sửa đổi\n");


    // if(intValue1 == intValue2)
    // {
    //     if(u == v)
    //          QMessageBox::information(this, "Thong bao", "Van ban khong bi sua doi\n" + QString::number(u) + "\n" + QString::number(v)+ "\n" + QString::number(intValue1) + "\n" + QString::number(intValue2));
    //     else
    //          QMessageBox::warning(this, "Thong bao", "Chu ky gia mao\n" + QString::number(u) + "\n" + QString::number(v) + "\n" + QString::number(intValue1) + "\n" + QString::number(intValue2));
    // }
    // else
    //     QMessageBox::warning(this, "Loi", "Van ban da bi sua doi\n" + QString::number(u) + "\n" + QString::number(v)+ "\n" + QString::number(intValue1) + "\n" + QString::number(intValue2));
}

// Slot giải hóa văn bản trong textEditGM1 và hiển thị trong textEditGM2
// void Chu_ky_so_Elgamal::convertAndDecrypt()
// {
//     bool ok1,ok2;
//     bool isInputValid = true;
//     QString ciphertext = ui->vanBanKy->toPlainText();
//     ui->pTxt->text().toInt(&ok1);
//     ui->xTxt->text().toInt(&ok2);
//     if (!ok1) {
//         QMessageBox::information(this, "Warning", "<html><b>Chưa nhập p!</b></html>");
//         isInputValid = false;
//     }
//     if (!ok2) {
//         QMessageBox::information(this, "Warning", "<html><b>Chưa nhập Kpr!</b></html>");
//         isInputValid = false;
//     }
//     if (!isInputValid) {
//         return;
//     }
//     // Chuyển đổi chuỗi mã hóa thành dãy các cặp số nguyên
//     QList<std::pair<int, int>> intPairs = convertCiphertextToIntPairs(ciphertext);

//     // Giải mã ElGamal với dãy cặp số nguyên này thành dãy số nguyên
//     QList<int> decryptedList = ElGamalDecrypt(intPairs);

//     QString plaintext;

//     for (int num : decryptedList)
//     {
//         QString character; // Ánh xạ số nguyên thành ký tự tương ứng
//         if(num == -2){
//                character = "\\n";
//         }else{
//                character = convertToChar(num);
//         }
//         plaintext += character;
//     }
//     // Khôi phục ký tự xuống dòng
//     plaintext = plaintext.replace("\\n", "\n");

//     // Hiển thị văn bản giải mã trong textEdit_GM2
//     ui->chuKy_2->setText(plaintext);
// }

// Chuyển đổi văn bản thành một dãy số nguyên trong trường modulo p
QList<int> Chu_ky_so_Elgamal::convertTextToIntList(const QString& text)
{
    QList<int> intList;

    for (const QChar& ch : text)
    {
        int intValue; // Ánh xạ ký tự thành số nguyên trong trường modulo p
        // Không được viết là if(ch =="\\n") vì trình biên dịch sẽ hiểu là \\n = \ và \n
        if(ch == QChar('\\') && ch == QChar('n')){
               intValue = -2; // định nghĩa xuống dòng là -1
        }else{
               intValue = convertToInt(ch);
        }
        intList.append(intValue);
    }

    return intList;
}

// Chuyển đổi chuỗi mã hóa thành dãy các cặp số nguyên trong trường modulo p
QList<std::pair<int, int>> Chu_ky_so_Elgamal::convertCiphertextToIntPairs(const QString& ciphertext)
{
    QList<std::pair<int, int>> intPairs;
    QList<int> intList = decodeBase64(ciphertext);

    for (int i = 0; i < intList.size(); i += 2) {
        int firstNum = intList[i];
        int secondNum = intList[i + 1];
        intPairs.append(std::make_pair(firstNum, secondNum));
    }
    return intPairs;
}
// Ánh xạ số nguyên mã hóa thành ký tự tương ứng trong trường modulo p
QString Chu_ky_so_Elgamal::convertToChar(int num)
{
    int convertedValue = num + 32; // Chuyển số nguyên thành giá trị Unicode (32-126)

    return QString(QChar(convertedValue));
}

// Ánh xạ ký tự thành số nguyên tương ứng trong trường modulo p
int Chu_ky_so_Elgamal::convertToInt(QChar ch)
{
    int unicode = ch.unicode(); // Lấy giá trị Unicode của ký tự
    int intValue = unicode - 32; // Chuyển giá trị Unicode thành số nguyên trong trường modulo p

    return intValue;
}
// Hàm mã hóa dãy số nguyên thành chuỗi Base64
QString Chu_ky_so_Elgamal::encodeBase64(const QList<int>& intList)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);

    for (int num : intList) {
        stream << num;
    }

    QByteArray encodedData = data.toBase64();
    return QString(encodedData);
}
QList<int> Chu_ky_so_Elgamal::decodeBase64(const QString& base64String)
{
    QByteArray decodedData = QByteArray::fromBase64(base64String.toUtf8());

    QList<int> intList;
    QDataStream stream(decodedData);

    while (!stream.atEnd()) {
        int num;
        stream >> num;
        intList.append(num);
    }

    return intList;
}

void Chu_ky_so_Elgamal::LuuVanBan()
{
    // Lấy nội dung từ QTextEdit
    QString vanBan = ui->vanBanKy->toPlainText();

    // Hiển thị hộp thoại lưu file
    QString filePath = QFileDialog::getSaveFileName(this, "Lưu file", "", "Text Files (*.txt);;Word Files (*.docx)");

    // Kiểm tra xem người dùng đã chọn đường dẫn lưu trữ hay chưa
    if (!filePath.isEmpty())
    {
        // Tạo và mở file để ghi nội dung vào
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            stream << vanBan;
            file.close();

            QMessageBox::information(this, "Thông báo", "Đã lưu file thành công!");
        }
        else
        {
            QMessageBox::critical(this, "Lỗi", "Không thể lưu file!");
        }
    }
}

// Slot để xử lý khi nhấn vào QPushButton luu chu ky
void Chu_ky_so_Elgamal::LuuChuKy()
{
    // Lấy nội dung từ QTextEdit
    QString chuKy = ui->chuKy_1->toPlainText();

    // Hiển thị hộp thoại lưu file
        QString filePath = QFileDialog::getSaveFileName(this, "Lưu file", "", "Text Files (*.txt);;Word Files (*.docx)");

        // Kiểm tra xem người dùng đã chọn đường dẫn lưu trữ hay chưa
    if (!filePath.isEmpty())
    {
        // Tạo và mở file để ghi nội dung vào
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
                QTextStream stream(&file);
                stream << chuKy;
                file.close();

                QMessageBox::information(this, "Thông báo", "Đã lưu file thành công!");
        }
        else
        {
                QMessageBox::critical(this, "Lỗi", "Không thể lưu file!");
        }
    }
}
// Slot để xử lý khi nhấn vào QPushButton luuBM
void Chu_ky_so_Elgamal::saveFileGM()
{
    // Lấy nội dung từ QTextEdit
    QString content = ui->chuKy_2->toPlainText();

    // Hiển thị hộp thoại lưu file
    QString filePath = QFileDialog::getSaveFileName(this, "Lưu file", "", "Text Files (*.txt);;Word Files (*.docx)");

        // Kiểm tra xem người dùng đã chọn đường dẫn lưu trữ hay chưa
        if (!filePath.isEmpty())
    {
        // Tạo và mở file để ghi nội dung vào
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
                QTextStream stream(&file);
                stream << content;
                file.close();

                QMessageBox::information(this, "Thông báo", "Đã lưu file thành công!");
        }
        else
        {
                QMessageBox::critical(this, "Lỗi", "Không thể lưu file!");
        }
    }
}
