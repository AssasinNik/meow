#include "add_stud.h"
#include "ui_add_stud.h"
#include "list_of_students.h"

add_stud::add_stud(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_stud)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

add_stud::~add_stud()
{
    delete ui;
}

void add_stud::on_pushButton_2_clicked()
{
    close();
}


void add_stud::on_pushButton_3_clicked()
{
    showMinimized();
}


void add_stud::on_pushButton_4_clicked()
{
    auto *list = new list_of_students();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

