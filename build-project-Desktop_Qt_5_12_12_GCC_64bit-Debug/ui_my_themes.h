/********************************************************************************
** Form generated from reading UI file 'my_themes.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MY_THEMES_H
#define UI_MY_THEMES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_my_themes
{
public:
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableView *tableView;

    void setupUi(QWidget *my_themes)
    {
        if (my_themes->objectName().isEmpty())
            my_themes->setObjectName(QString::fromUtf8("my_themes"));
        my_themes->resize(921, 511);
        my_themes->setMinimumSize(QSize(921, 511));
        my_themes->setMaximumSize(QSize(921, 511));
        my_themes->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(my_themes);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 0, 301, 61));
        label->setStyleSheet(QString::fromUtf8("color: rgb(109, 85, 255);\n"
"font: 75 40pt \"Karla\" bold;\n"
"font-weight: 500;"));
        pushButton_2 = new QPushButton(my_themes);
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
        pushButton_3 = new QPushButton(my_themes);
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
        pushButton_4 = new QPushButton(my_themes);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 10, 61, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/return.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(35, 35));
        tableView = new QTableView(my_themes);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(50, 90, 821, 391));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    border: 1.5px solid #6D55FF;\n"
"    border-radius: 5px; /* \320\243\320\274\320\265\320\275\321\214\321\210\320\265\320\275\320\275\320\276\320\265 \320\267\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \320\272\321\200\320\260\321\221\320\262 */\n"
"    gridline-color: #6D55FF; /* \320\246\320\262\320\265\321\202 \320\273\320\270\320\275\320\270\320\271 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 */\n"
"    background: white; /* \320\221\320\265\320\273\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 */\n"
"    selection-background-color: #6D55FF; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\270\320\270 */\n"
"    selection-color: white; /* \320\246\320\262"
                        "\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\321\200\320\270 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QTableView::item {\n"
"    border: 1.5px solid #6D55FF; /* \320\244\320\270\320\276\320\273\320\265\321\202\320\276\320\262\321\213\320\265 \320\273\320\270\320\275\320\270\320\270 \321\217\321\207\320\265\320\265\320\272 */\n"
"    border-width: 1px; /* \320\243\320\274\320\265\320\275\321\214\321\210\320\265\320\275\320\275\320\260\321\217 \321\202\320\276\320\273\321\211\320\270\320\275\320\260 \320\273\320\270\320\275\320\270\320\271 */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #6D55FF; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\320\276\320\271 \321\201\321\202\321\200\320\276\320\272\320\270 */\n"
"    color: white; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262\321"
                        "\213\320\264\320\265\320\273\320\265\320\275\320\275\320\276\320\271 \321\201\321\202\321\200\320\276\320\272\320\270 */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: white; /* \320\221\320\265\320\273\321\213\320\271 \321\204\320\276\320\275 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\276\320\262 \321\201\321\202\320\276\320\273\320\261\321\206\320\276\320\262 */\n"
"    color: black; /* \320\247\320\265\321\200\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\276\320\262 \321\201\321\202\320\276\320\273\320\261\321\206\320\276\320\262 */\n"
"    padding: 4px;\n"
"    border: 1.5px solid #6D55FF; /* \320\244\320\270\320\276\320\273\320\265\321\202\320\276\320\262\320\260\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\276\320\262 */\n"
"	 border-width: 1px;\n"
"}\n"
"QScrollBar:horizontal {\n"
"    "
                        "border: none;\n"
"    background: #f0f0f0;\n"
"    height: 10px; /* \320\243\320\274\320\265\320\275\321\214\321\210\320\265\320\275\320\275\320\260\321\217 \320\262\321\213\321\201\320\276\321\202\320\260 */\n"
"    margin: 0px 10px 0 10px;\n"
"    border-radius: 5px; /* \320\243\320\274\320\265\320\275\321\214\321\210\320\265\320\275\320\275\320\276\320\265 \320\267\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 */\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #6D55FF;\n"
"    min-width: 10px; /* \320\243\320\274\320\265\320\275\321\214\321\210\320\265\320\275\320\275\320\260\321\217 \320\274\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\273\320\270\320\275\320\260 */\n"
"    border-radius: 5px; /* \320\243\320\274\320\265\320\275\321\214\321\210\320\265\320\275\320\275\320\276\320\265 \320\267\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 */\n"
"}\n"
"\n"
"QScrollBar::add-li"
                        "ne:horizontal,\n"
"QScrollBar::sub-line:horizontal {\n"
"    border: none;\n"
"    background: none;\n"
"    width: 0px;\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #f0f0f0;\n"
"    width: 10px; /* \320\243\320\274\320\265\320\275\321\214\321\210\320\265\320\275\320\275\320\260\321\217 \321\210\320\270\321\200\320\270\320\275\320\260 */\n"
"    margin: 10px 0 10px 0;\n"
"    border-radius: 5px; /* \320\243\320\274\320\265\320\275\321\214\321\210\320\265\320\275\320\275\320\276\320\265 \320\267\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 */\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #6D55FF;\n"
"    min-height: 10px; /* \320\243\320\274\320\265\320\275\321\214\321\210\320\265\320\275\320\275\320\260\321\217 \320\274\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\273\320\270\320\275\320\260 */\n"
"    border-radius: 5px; /* \320\243\320\274\320\265\320\275"
                        "\321\214\321\210\320\265\320\275\320\275\320\276\320\265 \320\267\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    border: none;\n"
"    background: none;\n"
"    width: 0px;\n"
"    height: 0px;\n"
"}"));

        retranslateUi(my_themes);

        QMetaObject::connectSlotsByName(my_themes);
    } // setupUi

    void retranslateUi(QWidget *my_themes)
    {
        my_themes->setWindowTitle(QApplication::translate("my_themes", "Form", nullptr));
        label->setText(QApplication::translate("my_themes", "\320\234\320\276\320\270 \321\202\320\265\320\274\321\213", nullptr));
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class my_themes: public Ui_my_themes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY_THEMES_H
