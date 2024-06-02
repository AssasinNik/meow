#include "list_of_students.h"
#include "ui_list_of_students.h"
#include "add_stud.h"
#include <QSqlDatabase>
#include <QMenu>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QStandardItemModel>
#include <QTableView>
#include "role_type.h"
#include "greeting.h"
#include "sgreeting.h"
#include "pgreeting.h"
#include "change_student.h"
#include <iostream>

list_of_students::list_of_students(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list_of_students)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    if(IS_PROFESSOR==true || IS_STUDENT==true){
        ui->pushButton->close();
    }
}

list_of_students::~list_of_students()
{
    delete ui;
}

void list_of_students::on_pushButton_2_clicked()
{
    close();
}


void list_of_students::on_pushButton_3_clicked()
{
    showMinimized();
}


void list_of_students::on_pushButton_4_clicked()
{
    if(IS_ADMIN == true){
        auto *greeting = new Greeting();
        greeting->setAttribute(Qt::WA_DeleteOnClose);
        greeting->show();
        this->close();
    }
    else if(IS_STUDENT == true){
        auto *greeting = new sgreeting();
        greeting->setAttribute(Qt::WA_DeleteOnClose);
        greeting->show();
        this->close();
    }
    else if(IS_PROFESSOR == true){
        auto *greeting = new pgreeting();
        greeting->setAttribute(Qt::WA_DeleteOnClose);
        greeting->show();
        this->close();
    }
}
void list_of_students::deleteRecord(QModelIndex index) {
    // Логика для удаления записи
}
void list_of_students::editRecord(QModelIndex index) {
    // Создаем форму редактирования и передаем туда данные
    auto *change_t = new change_student();  // Создать окно логина
    change_t->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    change_t->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}
void list_of_students::customMenuRequested(QPoint pos) {
    QModelIndex index = ui->tableView->indexAt(pos);
    if (!index.isValid())
        return;

    QMenu *menu = new QMenu(this);
    menu->setStyleSheet(
            "QMenu {"
            "    border: 2px solid #6D55FF; /* Фиолетовая рамка */"
            "    background-color: #FFFFFF; /* Белый фон */"
            "    color: #000000; /* Чёрный текст */"
            "}"
            "QMenu::item:selected {"
            "    background-color: #6D55FF; /* Фиолетовый фон при наведении */"
            "    color: #FFFFFF; /* Белый текст */"
            "}"
        );
    menu->addAction(new QAction("Удалить", this));
    menu->addAction(new QAction("Изменить", this));

    connect(menu->actions()[0], &QAction::triggered, [this, index]() { editRecord(index); });
    connect(menu->actions()[1], &QAction::triggered, [this, index]() { deleteRecord(index); });
    menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
}
void list_of_students::on_pushButton_clicked()
{
    auto *add = new add_stud();
    add->setAttribute(Qt::WA_DeleteOnClose);
    add->show();
    this->close();
}

