/********************************************************************************
** Form generated from reading UI file 'list_of_themes.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIST_OF_THEMES_H
#define UI_LIST_OF_THEMES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_List_of_themes
{
public:
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableView *tableView;

    void setupUi(QWidget *List_of_themes)
    {
        if (List_of_themes->objectName().isEmpty())
            List_of_themes->setObjectName(QString::fromUtf8("List_of_themes"));
        List_of_themes->resize(921, 511);
        List_of_themes->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(List_of_themes);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 0, 731, 61));
        label->setStyleSheet(QString::fromUtf8("color: rgb(109, 85, 255);\n"
"font: 75 40pt \"Karla\" bold;\n"
"font-weight: 500;"));
        pushButton_2 = new QPushButton(List_of_themes);
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
        pushButton_3 = new QPushButton(List_of_themes);
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
        pushButton_4 = new QPushButton(List_of_themes);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 10, 61, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/return.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(35, 35));
        tableView = new QTableView(List_of_themes);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(50, 90, 821, 391));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    border: 2px solid #6D55FF;\n"
"    border-radius: 5px;\n"
"    gridline-color: #6D55FF;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    background-color: white;\n"
"    font-family: Karla; /* \320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    font-size: 14pt; /* \320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \321\200\320\260\320\267\320\274\320\265\321\200\320\260 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #6D55FF;\n"
"    color: white;\n"
"}\n"
"\n"
"QTableView::item:focus {\n"
"    background-color: #6D55FF;\n"
"    color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #6D55FF;\n"
"    color: white;\n"
"    font-family: Karla;\n"
"    font-size: 14pt;\n"
"}\n"
"QHeaderView::section:horizontal {\n"
"    border: none; /* \321\203\320\261\320\270\321\200\320\260\320\265\320\274 \320\263\320"
                        "\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\321\213\320\265 \320\273\320\270\320\275\320\270\320\270 \321\200\320\260\320\267\320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\217 */\n"
"}\n"
"\n"
"QHeaderView::section:vertical {\n"
"    border: none; /* \321\203\320\261\320\270\321\200\320\260\320\265\320\274 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\321\213\320\265 \320\273\320\270\320\275\320\270\320\270 \321\200\320\260\320\267\320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\217 */\n"
"}"));

        retranslateUi(List_of_themes);

        QMetaObject::connectSlotsByName(List_of_themes);
    } // setupUi

    void retranslateUi(QWidget *List_of_themes)
    {
        List_of_themes->setWindowTitle(QApplication::translate("List_of_themes", "Form", nullptr));
        label->setText(QApplication::translate("List_of_themes", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\276\321\202\320\272\321\200\321\213\321\202\321\213\321\205 \321\202\320\265\320\274", nullptr));
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class List_of_themes: public Ui_List_of_themes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIST_OF_THEMES_H