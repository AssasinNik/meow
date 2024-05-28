#include "add_stage.h"
#include "ui_add_stage.h"
#include "list_of_stages.h"

add_stage::add_stage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_stage)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

add_stage::~add_stage()
{
    delete ui;
}

void add_stage::on_pushButton_2_clicked()
{
    close();
}


void add_stage::on_pushButton_3_clicked()
{
    showMinimized();
}


void add_stage::on_pushButton_4_clicked()
{
    auto *list = new list_of_stages();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

