#include "change_student.h"
#include "ui_change_student.h"
#include "list_of_students.h"

change_student::change_student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_student)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

change_student::~change_student()
{
    delete ui;
}

void change_student::on_pushButton_2_clicked()
{
    close();
}


void change_student::on_pushButton_3_clicked()
{
    showMinimized();
}


void change_student::on_pushButton_4_clicked()
{
    auto *list = new list_of_students();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

