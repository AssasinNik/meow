/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QComboBox *comboBox;
    QLabel *label_6;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(921, 511);
        Register->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 0, 491, 61));
        label->setStyleSheet(QString::fromUtf8("color: rgb(109, 85, 255);\n"
"font: 75 40pt \"Karla\" bold;\n"
"font-weight: 500;"));
        pushButton_2 = new QPushButton(Register);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(890, 10, 20, 20));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 10px;\n"
"	background-color: #FF5B5B;\n"
"	color: white;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: #FFBCBC;\n"
"}"));
        pushButton_3 = new QPushButton(Register);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(860, 10, 20, 20));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 10px;\n"
"	background-color: #45FF79;\n"
"	color: white;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: #B2FFC8;\n"
"}"));
        lineEdit_2 = new QLineEdit(Register);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 120, 361, 41));
        lineEdit_2->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));
        label_2 = new QLabel(Register);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 121, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        pushButton_4 = new QPushButton(Register);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 10, 61, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/return.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(35, 35));
        pushButton = new QPushButton(Register);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(500, 420, 401, 71));
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: #6D55FF;\n"
"	border-radius: 15px; \n"
"	font: 75 25pt \"Karla\" bold;\n"
"	border: 2px;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: #A597FF;\n"
"}"));
        pushButton->setFlat(false);
        pushButton_5 = new QPushButton(Register);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(600, 200, 221, 201));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/register.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon1);
        pushButton_5->setIconSize(QSize(200, 200));
        label_3 = new QLabel(Register);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 180, 121, 31));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        lineEdit_3 = new QLineEdit(Register);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 220, 361, 41));
        lineEdit_3->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));
        label_4 = new QLabel(Register);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 280, 121, 31));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        lineEdit_4 = new QLineEdit(Register);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(20, 320, 361, 41));
        lineEdit_4->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));
        label_5 = new QLabel(Register);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 380, 121, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        lineEdit_5 = new QLineEdit(Register);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(20, 420, 361, 41));
        lineEdit_5->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));
        comboBox = new QComboBox(Register);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(520, 120, 361, 41));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	border-radius: 15px; \n"
"	font: 14pt \"Karla\";\n"
"	padding-left: 10px;\n"
"	padding-right:10px;\n"
"	border: 2px solid #6D55FF;\n"
"}\n"
"QComboBox::drop-down {\n"
"        subcontrol-origin: padding;\n"
"        subcontrol-position: top right;\n"
"        width: 20px;\n"
"        border-left-width: 1px;\n"
"        border-left-color: darkgray;\n"
"        border-left-style: solid;\n"
"        border-top-right-radius: 3px;\n"
"         border-bottom-right-radius: 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"        image: url(:/new/prefix1/combobox.png);\n"
"		width:20px;\n"
"		height:20px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    border: 2px solid #6D55FF;\n"
"    selection-background-color: #6D55FF;\n"
"    background-color: white; \n"
"}"));
        label_6 = new QLabel(Register);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(530, 80, 121, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));

        retranslateUi(Register);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", nullptr));
        label->setText(QApplication::translate("Register", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        label_2->setText(QApplication::translate("Register", "\320\230\320\274\321\217", nullptr));
        pushButton_4->setText(QString());
        pushButton->setText(QApplication::translate("Register", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        pushButton_5->setText(QString());
        label_3->setText(QApplication::translate("Register", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_4->setText(QApplication::translate("Register", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        label_5->setText(QApplication::translate("Register", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_6->setText(QApplication::translate("Register", "\320\240\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
