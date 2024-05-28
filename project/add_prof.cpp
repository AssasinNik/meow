#include "add_prof.h"
#include "ui_add_prof.h"
#include "list_of_prof.h"

add_prof::add_prof(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_prof)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

add_prof::~add_prof()
{
    delete ui;
}

void add_prof::on_pushButton_2_clicked()
{
    close();
}


void add_prof::on_pushButton_3_clicked()
{
    showMinimized();
}


void add_prof::on_pushButton_4_clicked()
{
    auto *list = new list_of_prof();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

