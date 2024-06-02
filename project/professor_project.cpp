#include "professor_project.h"
#include "ui_professor_project.h"
#include "list_of_themes.h"

professor_project::professor_project(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::professor_project)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

professor_project::~professor_project()
{
    delete ui;
}

void professor_project::on_pushButton_2_clicked()
{
    close();
}


void professor_project::on_pushButton_3_clicked()
{
    showMinimized();
}


void professor_project::on_pushButton_4_clicked()
{
    auto *list = new List_of_themes();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

