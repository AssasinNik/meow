/********************************************************************************
** Form generated from reading UI file 'sgreeting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SGREETING_H
#define UI_SGREETING_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sgreeting
{
public:
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;

    void setupUi(QWidget *sgreeting)
    {
        if (sgreeting->objectName().isEmpty())
            sgreeting->setObjectName(QString::fromUtf8("sgreeting"));
        sgreeting->resize(921, 511);
        sgreeting->setMinimumSize(QSize(921, 511));
        sgreeting->setMaximumSize(QSize(921, 511));
        sgreeting->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_7 = new QPushButton(sgreeting);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(130, 290, 611, 101));
        QFont font;
        font.setFamily(QString::fromUtf8("Karla 13"));
        font.setPointSize(25);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        pushButton_7->setFont(font);
        pushButton_7->setAutoFillBackground(false);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: #6D55FF;\n"
"	border-radius: 15px; \n"
"	font: 75 25pt \"Karla\" bold;\n"
"	border: 2px;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: #A597FF;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Book.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon);
        pushButton_7->setIconSize(QSize(125, 125));
        pushButton_7->setFlat(false);
        pushButton_5 = new QPushButton(sgreeting);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(130, 180, 611, 101));
        pushButton_5->setFont(font);
        pushButton_5->setAutoFillBackground(false);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: #6D55FF;\n"
"	border-radius: 15px; \n"
"	font: 75 25pt \"Karla\" bold;\n"
"	border: 2px;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: #A597FF;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/Palette.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon1);
        pushButton_5->setIconSize(QSize(125, 125));
        pushButton_5->setFlat(false);
        pushButton = new QPushButton(sgreeting);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 70, 611, 101));
        pushButton->setFont(font);
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/spisok.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(125, 125));
        pushButton->setFlat(false);
        label = new QLabel(sgreeting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 0, 541, 61));
        label->setStyleSheet(QString::fromUtf8("color: rgb(109, 85, 255);\n"
"font: 75 40pt \"Karla\" bold;\n"
"font-weight: 500;"));
        pushButton_3 = new QPushButton(sgreeting);
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
        pushButton_2 = new QPushButton(sgreeting);
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
        pushButton_6 = new QPushButton(sgreeting);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(130, 400, 611, 101));
        pushButton_6->setFont(font);
        pushButton_6->setAutoFillBackground(false);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: #6D55FF;\n"
"	border-radius: 15px; \n"
"	font: 75 25pt \"Karla\" bold;\n"
"	border: 2px;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: #A597FF;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/Backpack.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon3);
        pushButton_6->setIconSize(QSize(125, 125));
        pushButton_6->setFlat(false);

        retranslateUi(sgreeting);

        pushButton_7->setDefault(false);
        pushButton_5->setDefault(false);
        pushButton->setDefault(false);
        pushButton_6->setDefault(false);


        QMetaObject::connectSlotsByName(sgreeting);
    } // setupUi

    void retranslateUi(QWidget *sgreeting)
    {
        sgreeting->setWindowTitle(QApplication::translate("sgreeting", "Form", nullptr));
        pushButton_7->setText(QApplication::translate("sgreeting", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\276\320\262", nullptr));
        pushButton_5->setText(QApplication::translate("sgreeting", "\320\234\320\276\320\270 \321\202\320\265\320\274\321\213", nullptr));
        pushButton->setText(QApplication::translate("sgreeting", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\202\320\265\320\274", nullptr));
        label->setText(QApplication::translate("sgreeting", "\320\240\320\260\320\261\320\276\321\207\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214", nullptr));
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
        pushButton_6->setText(QApplication::translate("sgreeting", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\320\265\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sgreeting: public Ui_sgreeting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SGREETING_H
