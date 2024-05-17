/********************************************************************************
** Form generated from reading UI file 'profil.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFIL_H
#define UI_PROFIL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Profil
{
public:
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QLineEdit *lineEdit_5;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_7;
    QLabel *label_7;
    QPushButton *pushButton;
    QLabel *label_6;
    QLineEdit *lineEdit_6;

    void setupUi(QWidget *Profil)
    {
        if (Profil->objectName().isEmpty())
            Profil->setObjectName(QString::fromUtf8("Profil"));
        Profil->resize(921, 511);
        Profil->setMinimumSize(QSize(921, 511));
        Profil->setMaximumSize(QSize(921, 511));
        Profil->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_4 = new QPushButton(Profil);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 10, 61, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/return.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(35, 35));
        pushButton_2 = new QPushButton(Profil);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(880, 10, 20, 20));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 10px;\n"
"	background-color: #FF5B5B;\n"
"	color: white;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: #FFBCBC;\n"
"}"));
        label = new QLabel(Profil);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 0, 511, 61));
        label->setStyleSheet(QString::fromUtf8("color: rgb(109, 85, 255);\n"
"font: 75 40pt \"Karla\" bold;\n"
"font-weight: 500;"));
        pushButton_3 = new QPushButton(Profil);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(850, 10, 20, 20));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 10px;\n"
"	background-color: #45FF79;\n"
"	color: white;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: #B2FFC8;\n"
"}"));
        label_2 = new QLabel(Profil);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 121, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        lineEdit_5 = new QLineEdit(Profil);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(520, 110, 361, 41));
        lineEdit_5->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));
        label_3 = new QLabel(Profil);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 170, 121, 31));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        label_5 = new QLabel(Profil);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(520, 70, 121, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        lineEdit_3 = new QLineEdit(Profil);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 210, 361, 41));
        lineEdit_3->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));
        lineEdit_2 = new QLineEdit(Profil);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 110, 361, 41));
        lineEdit_2->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));
        label_4 = new QLabel(Profil);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 270, 121, 31));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        lineEdit_4 = new QLineEdit(Profil);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(20, 310, 361, 41));
        lineEdit_4->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));
        lineEdit_7 = new QLineEdit(Profil);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(520, 200, 361, 41));
        lineEdit_7->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));
        label_7 = new QLabel(Profil);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(520, 160, 201, 31));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        pushButton = new QPushButton(Profil);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(520, 280, 361, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Karla 13"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        pushButton->setFont(font);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: #6D55FF;\n"
"	border-radius: 15px; \n"
"	font: 75 16pt \"Karla\" bold;\n"
"	border: 2px;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: #A597FF;\n"
"}"));
        pushButton->setFlat(false);
        label_6 = new QLabel(Profil);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 360, 121, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        lineEdit_6 = new QLineEdit(Profil);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(20, 400, 361, 41));
        lineEdit_6->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));

        retranslateUi(Profil);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Profil);
    } // setupUi

    void retranslateUi(QWidget *Profil)
    {
        Profil->setWindowTitle(QApplication::translate("Profil", "Form", nullptr));
        pushButton_4->setText(QString());
        pushButton_2->setText(QString());
        label->setText(QApplication::translate("Profil", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        pushButton_3->setText(QString());
        label_2->setText(QApplication::translate("Profil", "\320\230\320\274\321\217", nullptr));
        label_3->setText(QApplication::translate("Profil", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_5->setText(QApplication::translate("Profil", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_4->setText(QApplication::translate("Profil", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        label_7->setText(QApplication::translate("Profil", "\320\235\320\276\320\262\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton->setText(QApplication::translate("Profil", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_6->setText(QApplication::translate("Profil", "\320\240\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Profil: public Ui_Profil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFIL_H
