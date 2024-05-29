#include "change_prof.h"
#include "ui_change_prof.h"
#include "list_of_prof.h"

change_prof::change_prof(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_prof)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

change_prof::~change_prof()
{
    delete ui;
}

void change_prof::on_pushButton_2_clicked()
{
    close();
}


void change_prof::on_pushButton_3_clicked()
{
    showMinimized();
}


void change_prof::on_pushButton_4_clicked()
{
    auto *list = new list_of_prof();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

