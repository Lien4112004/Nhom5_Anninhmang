/********************************************************************************
** Form generated from reading UI file 'Chu_ky_so_Elgamal.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHU_KY_SO_ELGAMAL_H
#define UI_CHU_KY_SO_ELGAMAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chu_ky_so_Elgamal
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *pTxt;
    QLabel *label_2;
    QLineEdit *gTxt;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *xTxt;
    QLineEdit *yTxt;
    QPushButton *random;
    QPushButton *deleteKey;
    QLabel *label_11;
    QLabel *label_12;
    QGroupBox *groupBox_3;
    QLabel *label_8;
    QLabel *label_9;
    QTextEdit *vanBanKT;
    QPushButton *kiemTra;
    QPushButton *fileCK;
    QPushButton *fileKT;
    QTextEdit *chuKy_2;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QLabel *label_7;
    QTextEdit *vanBanKy;
    QPushButton *taoChuKy;
    QPushButton *chuyen;
    QPushButton *luuChuky;
    QPushButton *fileVB;
    QTextEdit *chuKy_1;
    QLabel *label_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Chu_ky_so_Elgamal)
    {
        if (Chu_ky_so_Elgamal->objectName().isEmpty())
            Chu_ky_so_Elgamal->setObjectName("Chu_ky_so_Elgamal");
        Chu_ky_so_Elgamal->resize(793, 776);
        Chu_ky_so_Elgamal->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 251, 255);"));
        centralwidget = new QWidget(Chu_ky_so_Elgamal);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 40, 751, 161));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable Text")});
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        groupBox->setFont(font);
        groupBox->setCursor(QCursor(Qt::ArrowCursor));
        groupBox->setMouseTracking(true);
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 239, 255);"));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 50, 16, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Variable Text")});
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        label->setFont(font1);
        label->setTextFormat(Qt::MarkdownText);
        label->setOpenExternalLinks(false);
        pTxt = new QLineEdit(groupBox);
        pTxt->setObjectName("pTxt");
        pTxt->setGeometry(QRect(190, 40, 141, 28));
        pTxt->setFont(font1);
        pTxt->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(370, 50, 21, 20));
        label_2->setFont(font1);
        gTxt = new QLineEdit(groupBox);
        gTxt->setObjectName("gTxt");
        gTxt->setGeometry(QRect(390, 40, 141, 28));
        gTxt->setFont(font1);
        gTxt->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 80, 21, 20));
        label_3->setFont(font1);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(570, 50, 16, 20));
        label_4->setFont(font1);
        xTxt = new QLineEdit(groupBox);
        xTxt->setObjectName("xTxt");
        xTxt->setGeometry(QRect(190, 80, 141, 28));
        xTxt->setFont(font1);
        xTxt->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        yTxt = new QLineEdit(groupBox);
        yTxt->setObjectName("yTxt");
        yTxt->setGeometry(QRect(590, 40, 141, 28));
        yTxt->setFont(font1);
        yTxt->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 200, 206);\n"
"background-color: rgb(226, 226, 226);"));
        random = new QPushButton(groupBox);
        random->setObjectName("random");
        random->setGeometry(QRect(270, 120, 91, 29));
        random->setFont(font1);
        random->setCursor(QCursor(Qt::PointingHandCursor));
        random->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 205, 255);"));
        deleteKey = new QPushButton(groupBox);
        deleteKey->setObjectName("deleteKey");
        deleteKey->setGeometry(QRect(402, 120, 81, 29));
        deleteKey->setFont(font1);
        deleteKey->setCursor(QCursor(Qt::PointingHandCursor));
        deleteKey->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 205, 255);"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 50, 121, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI Variable Text")});
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"color: rgb(0, 0, 171);"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 70, 121, 31));
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"color: rgb(0, 0, 171);"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(410, 220, 361, 471));
        groupBox_3->setFont(font);
        groupBox_3->setCursor(QCursor(Qt::ArrowCursor));
        groupBox_3->setLayoutDirection(Qt::LeftToRight);
        groupBox_3->setAutoFillBackground(false);
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 239, 255);"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 50, 63, 20));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(false);
        label_8->setFont(font3);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"color: rgb(0, 0, 171);"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 280, 63, 20));
        label_9->setFont(font3);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"color: rgb(0, 0, 171);"));
        vanBanKT = new QTextEdit(groupBox_3);
        vanBanKT->setObjectName("vanBanKT");
        vanBanKT->setGeometry(QRect(20, 90, 241, 111));
        vanBanKT->setFont(font1);
        vanBanKT->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        kiemTra = new QPushButton(groupBox_3);
        kiemTra->setObjectName("kiemTra");
        kiemTra->setGeometry(QRect(70, 350, 83, 29));
        kiemTra->setFont(font1);
        kiemTra->setCursor(QCursor(Qt::PointingHandCursor));
        kiemTra->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 205, 255);"));
        fileCK = new QPushButton(groupBox_3);
        fileCK->setObjectName("fileCK");
        fileCK->setGeometry(QRect(190, 350, 83, 29));
        fileCK->setFont(font1);
        fileCK->setCursor(QCursor(Qt::PointingHandCursor));
        fileCK->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 205, 255);"));
        fileKT = new QPushButton(groupBox_3);
        fileKT->setObjectName("fileKT");
        fileKT->setGeometry(QRect(270, 130, 83, 29));
        fileKT->setFont(font1);
        fileKT->setCursor(QCursor(Qt::PointingHandCursor));
        fileKT->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 205, 255);"));
        chuKy_2 = new QTextEdit(groupBox_3);
        chuKy_2->setObjectName("chuKy_2");
        chuKy_2->setGeometry(QRect(90, 259, 231, 51));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 220, 361, 471));
        groupBox_2->setFont(font);
        groupBox_2->setCursor(QCursor(Qt::ArrowCursor));
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 239, 255);"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 50, 63, 20));
        label_6->setFont(font3);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"color: rgb(0, 0, 171);"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 290, 63, 20));
        label_7->setFont(font3);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"color: rgb(0, 0, 171);"));
        vanBanKy = new QTextEdit(groupBox_2);
        vanBanKy->setObjectName("vanBanKy");
        vanBanKy->setGeometry(QRect(20, 90, 241, 121));
        vanBanKy->setFont(font1);
        vanBanKy->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        taoChuKy = new QPushButton(groupBox_2);
        taoChuKy->setObjectName("taoChuKy");
        taoChuKy->setGeometry(QRect(130, 230, 91, 31));
        taoChuKy->setFont(font1);
        taoChuKy->setCursor(QCursor(Qt::PointingHandCursor));
        taoChuKy->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 205, 255);"));
        chuyen = new QPushButton(groupBox_2);
        chuyen->setObjectName("chuyen");
        chuyen->setGeometry(QRect(70, 410, 83, 29));
        chuyen->setFont(font1);
        chuyen->setCursor(QCursor(Qt::PointingHandCursor));
        chuyen->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 205, 255);"));
        luuChuky = new QPushButton(groupBox_2);
        luuChuky->setObjectName("luuChuky");
        luuChuky->setGeometry(QRect(200, 410, 83, 29));
        luuChuky->setFont(font1);
        luuChuky->setCursor(QCursor(Qt::PointingHandCursor));
        luuChuky->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 205, 255);"));
        fileVB = new QPushButton(groupBox_2);
        fileVB->setObjectName("fileVB");
        fileVB->setGeometry(QRect(270, 130, 83, 29));
        fileVB->setFont(font1);
        fileVB->setCursor(QCursor(Qt::PointingHandCursor));
        fileVB->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 205, 255);"));
        chuKy_1 = new QTextEdit(groupBox_2);
        chuKy_1->setObjectName("chuKy_1");
        chuKy_1->setGeometry(QRect(40, 330, 281, 41));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(290, 0, 241, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI Variable Text")});
        font4.setPointSize(20);
        font4.setBold(true);
        label_10->setFont(font4);
        Chu_ky_so_Elgamal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Chu_ky_so_Elgamal);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 793, 21));
        Chu_ky_so_Elgamal->setMenuBar(menubar);
        statusbar = new QStatusBar(Chu_ky_so_Elgamal);
        statusbar->setObjectName("statusbar");
        Chu_ky_so_Elgamal->setStatusBar(statusbar);

        retranslateUi(Chu_ky_so_Elgamal);

        QMetaObject::connectSlotsByName(Chu_ky_so_Elgamal);
    } // setupUi

    void retranslateUi(QMainWindow *Chu_ky_so_Elgamal)
    {
        Chu_ky_so_Elgamal->setWindowTitle(QCoreApplication::translate("Chu_ky_so_Elgamal", "NguyenThiHongNhung_2021602687_Elgamal", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Chu_ky_so_Elgamal", "T\341\272\241o kh\303\263a", nullptr));
        label->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "p", nullptr));
        label_2->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "g", nullptr));
        label_3->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "x", nullptr));
        label_4->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "y", nullptr));
        random->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "Random", nullptr));
        deleteKey->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "Delete All", nullptr));
        label_11->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "Kh\303\263a c\303\264ng khai :", nullptr));
        label_12->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "Kh\303\263a b\303\255 m\341\272\255t :", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Chu_ky_so_Elgamal", "Ki\341\273\203m tra ch\341\273\257 k\303\275", nullptr));
        label_8->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "V\304\203n b\341\272\243n", nullptr));
        label_9->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "Ch\341\273\257 K\303\275", nullptr));
        kiemTra->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "Ki\341\273\203m tra", nullptr));
        fileCK->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "File", nullptr));
        fileKT->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "File", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Chu_ky_so_Elgamal", "T\341\272\241o ch\341\273\257 k\303\275", nullptr));
        label_6->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "V\304\203n b\341\272\243n", nullptr));
        label_7->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "Ch\341\273\257 k\303\275", nullptr));
        taoChuKy->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "K\303\275", nullptr));
        chuyen->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "Chuy\341\273\203n", nullptr));
        luuChuky->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "L\306\260u", nullptr));
        fileVB->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "File", nullptr));
        label_10->setText(QCoreApplication::translate("Chu_ky_so_Elgamal", "Ch\341\273\257 K\303\275 S\341\273\221 Elgamal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chu_ky_so_Elgamal: public Ui_Chu_ky_so_Elgamal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHU_KY_SO_ELGAMAL_H
