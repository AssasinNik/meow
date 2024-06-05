/********************************************************************************
** Form generated from reading UI file 'change_stage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_STAGE_H
#define UI_CHANGE_STAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_change_stage
{
public:
    QPushButton *pushButton_2;
    QLabel *label_5;
    QPushButton *pushButton;
    QLineEdit *lineEdit_4;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_3;

    void setupUi(QWidget *change_stage)
    {
        if (change_stage->objectName().isEmpty())
            change_stage->setObjectName(QString::fromUtf8("change_stage"));
        change_stage->resize(921, 511);
        change_stage->setMinimumSize(QSize(921, 511));
        change_stage->setMaximumSize(QSize(921, 511));
        change_stage->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(change_stage);
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
        label_5 = new QLabel(change_stage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(470, 180, 411, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        pushButton = new QPushButton(change_stage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 420, 361, 71));
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
        lineEdit_4 = new QLineEdit(change_stage);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(470, 130, 191, 41));
        lineEdit_4->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));
        textEdit = new QTextEdit(change_stage);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 220, 361, 181));
        textEdit->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));
        label = new QLabel(change_stage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 0, 581, 61));
        label->setStyleSheet(QString::fromUtf8("color: rgb(109, 85, 255);\n"
"font: 75 40pt \"Karla\" bold;\n"
"font-weight: 500;"));
        label_4 = new QLabel(change_stage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(470, 90, 411, 31));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 15pt \"Karla\";\n"
""));
        lineEdit_2 = new QLineEdit(change_stage);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(30, 130, 361, 41));
        lineEdit_2->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));
        label_2 = new QLabel(change_stage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 90, 261, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        comboBox = new QComboBox(change_stage);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(470, 220, 251, 41));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border-radius: 15px; \n"
"    font: 14pt \"Karla\";\n"
"    padding-left: 10px;\n"
"    padding-right:10px;\n"
"    border: 2px solid #6D55FF;\n"
"    color: black; /* Default text color - black */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/new/prefix1/combobox.png);\n"
"    width: 20px;\n"
"    height: 20px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    border: 2px solid #6D55FF;\n"
"    color: #6D55FF; /* Text color in the dropdown - purple */\n"
"    background-color: white; \n"
"}\n"
"\n"
"QComboBox:hover { /* Hover state - highlight with purple border */\n"
"    border: 2px solid #6D55FF;\n"
"}\n"
"\n"
"QComboBox:focus { /* Focus state - highlight wit"
                        "h purple border */\n"
"    border: 2px solid #6D55FF;\n"
"}\n"
"\n"
"QComboBox:selected { /* Selected state - highlight with purple border */\n"
"    border: 2px solid #6D55FF;\n"
"    color: #6D55FF; /* Text color in the selected state - purple */\n"
"}"));
        pushButton_3 = new QPushButton(change_stage);
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
        pushButton_4 = new QPushButton(change_stage);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 10, 61, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/return.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(35, 35));
        label_3 = new QLabel(change_stage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 180, 261, 31));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));

        retranslateUi(change_stage);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(change_stage);
    } // setupUi

    void retranslateUi(QWidget *change_stage)
    {
        change_stage->setWindowTitle(QApplication::translate("change_stage", "Form", nullptr));
        pushButton_2->setText(QString());
        label_5->setText(QApplication::translate("change_stage", "\320\241\320\273\320\276\320\266\320\275\320\276\321\201\321\202\321\214 \321\201\321\202\320\260\320\264\320\270\320\270", nullptr));
        pushButton->setText(QApplication::translate("change_stage", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label->setText(QApplication::translate("change_stage", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\201\321\202\320\260\320\264\320\270\321\216", nullptr));
        label_4->setText(QApplication::translate("change_stage", "\320\240\320\265\320\272\320\276\320\274\320\265\320\275\320\264\321\203\320\265\320\274\320\260\321\217 \320\264\320\273\320\270\320\275\320\260 \321\201\321\202\320\260\320\264\320\270\320\270 (\321\207\320\260\321\201\321\213)", nullptr));
        label_2->setText(QApplication::translate("change_stage", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\321\202\320\260\320\264\320\270\320\270", nullptr));
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        label_3->setText(QApplication::translate("change_stage", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class change_stage: public Ui_change_stage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_STAGE_H
