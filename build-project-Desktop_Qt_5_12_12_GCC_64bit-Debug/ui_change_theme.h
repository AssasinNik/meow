/********************************************************************************
** Form generated from reading UI file 'change_theme.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_THEME_H
#define UI_CHANGE_THEME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_change_theme
{
public:
    QPushButton *pushButton_4;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_5;
    QSlider *horizontalSlider;
    QLabel *label_6;
    QLabel *label_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit_6;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_8;

    void setupUi(QWidget *change_theme)
    {
        if (change_theme->objectName().isEmpty())
            change_theme->setObjectName(QString::fromUtf8("change_theme"));
        change_theme->resize(921, 511);
        change_theme->setMinimumSize(QSize(921, 511));
        change_theme->setMaximumSize(QSize(921, 511));
        change_theme->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_4 = new QPushButton(change_theme);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 10, 61, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/return.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(35, 35));
        label_2 = new QLabel(change_theme);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 161, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        pushButton_3 = new QPushButton(change_theme);
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
        pushButton_2 = new QPushButton(change_theme);
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
        lineEdit_2 = new QLineEdit(change_theme);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 120, 361, 41));
        lineEdit_2->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));
        lineEdit_3 = new QLineEdit(change_theme);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 220, 361, 41));
        lineEdit_3->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));
        pushButton_5 = new QPushButton(change_theme);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 320, 251, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Karla 13"));
        font.setPointSize(17);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        pushButton_5->setFont(font);
        pushButton_5->setAutoFillBackground(false);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: #6D55FF;\n"
"	border-radius: 15px; \n"
"	font: 75 17pt \"Karla\" bold;\n"
"	border: 2px;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: #A597FF;\n"
"}"));
        pushButton_5->setFlat(false);
        horizontalSlider = new QSlider(change_theme);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(520, 120, 361, 31));
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    background: #CFCFCF; /* \320\246\320\262\320\265\321\202 \320\275\320\265\320\267\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\275\320\276\320\271 \321\207\320\260\321\201\321\202\320\270 */\n"
"    height: 10px; /* \320\222\321\213\321\201\320\276\321\202\320\260 \320\273\320\270\320\275\320\270\320\270 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \320\272\321\200\320\260\321\217 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: #6D55FF; /* \320\246\320\262\320\265\321\202 \320\267\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\275\320\276\320\271 \321\207\320\260\321\201\321\202\320\270 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \320\272\321\200\320\260\321\217 */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #CFCFCF; /* \320\246\320\262"
                        "\320\265\321\202 \320\275\320\265\320\267\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\275\320\276\320\271 \321\207\320\260\321\201\321\202\320\270 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \320\272\321\200\320\260\321\217 */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #E476FF; /* \320\246\320\262\320\265\321\202 \320\272\321\200\321\203\320\263\320\273\320\276\320\271 \321\202\320\276\321\207\320\272\320\270 */\n"
"    border: 1px solid #E476FF; /* \320\223\321\200\320\260\320\275\320\270\321\206\320\260 \320\262\320\276\320\272\321\200\321\203\320\263 \321\202\320\276\321\207\320\272\320\270 */\n"
"    width: 20px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \321\202\320\276\321\207\320\272\320\270 */\n"
"    height: 20px; /* \320\222\321\213\321\201\320\276\321\202\320\260 \321\202\320\276\321\207\320\272\320\270 */\n"
"    border-radius: 10px; /* \320\232\321\200\321\203\320\263"
                        "\320\273\320\260\321\217 \321\204\320\276\321\200\320\274\320\260 */\n"
"    margin-top: -6px; \n"
"    margin-bottom: -6px; /* \320\246\320\265\320\275\321\202\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\202\320\276\321\207\320\272\320\270 */\n"
"}"));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(change_theme);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(520, 80, 231, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        label_3 = new QLabel(change_theme);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 180, 151, 31));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        pushButton = new QPushButton(change_theme);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 430, 361, 71));
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
        lineEdit_6 = new QLineEdit(change_theme);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(660, 160, 201, 41));
        lineEdit_6->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"font: 14pt \"Karla\";\n"
"padding-left: 10px;\n"
"padding-right:10px;\n"
"border: 2px solid #6D55FF;\n"
""));
        label_7 = new QLabel(change_theme);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(870, 160, 31, 31));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        label_4 = new QLabel(change_theme);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 280, 251, 31));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 18pt \"Karla\";\n"
""));
        label = new QLabel(change_theme);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 0, 511, 61));
        label->setStyleSheet(QString::fromUtf8("color: rgb(109, 85, 255);\n"
"font: 75 40pt \"Karla\" bold;\n"
"font-weight: 500;"));
        label_8 = new QLabel(change_theme);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 390, 831, 21));
        label_8->setStyleSheet(QString::fromUtf8("font: 75 11pt \"Karla\" bold;"));

        retranslateUi(change_theme);

        pushButton_5->setDefault(false);
        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(change_theme);
    } // setupUi

    void retranslateUi(QWidget *change_theme)
    {
        change_theme->setWindowTitle(QApplication::translate("change_theme", "Form", nullptr));
        pushButton_4->setText(QString());
        label_2->setText(QApplication::translate("change_theme", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
        lineEdit_2->setText(QString());
        pushButton_5->setText(QApplication::translate("change_theme", "\320\237\321\200\320\270\320\272\321\200\320\265\320\277\320\270\321\202\321\214", nullptr));
        label_6->setText(QApplication::translate("change_theme", "\320\244\320\270\320\275\320\260\320\275\321\201\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_3->setText(QApplication::translate("change_theme", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        pushButton->setText(QApplication::translate("change_theme", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_7->setText(QApplication::translate("change_theme", "\342\202\275", nullptr));
        label_4->setText(QApplication::translate("change_theme", "\320\237\321\200\320\270\320\272\321\200\320\265\320\277\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        label->setText(QApplication::translate("change_theme", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\202\320\265\320\274\321\203", nullptr));
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class change_theme: public Ui_change_theme {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_THEME_H
