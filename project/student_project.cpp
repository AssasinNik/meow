#include "student_project.h"
#include "ui_student_project.h"
#include "list_of_themes.h"

student_project::student_project(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::student_project)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

student_project::~student_project()
{
    delete ui;
}

void student_project::on_pushButton_2_clicked()
{
    close();
}


void student_project::on_pushButton_3_clicked()
{
    showMinimized();
}


void student_project::on_pushButton_4_clicked()
{
    auto *list = new List_of_themes();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

