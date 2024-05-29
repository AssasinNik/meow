#include "change_stage.h"
#include "ui_change_stage.h"
#include "list_of_stages.h"

change_stage::change_stage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_stage)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->comboBox->addItem("Низкая");
    ui->comboBox->addItem("Средняя");
    ui->comboBox->addItem("Сложная");
}

change_stage::~change_stage()
{
    delete ui;
}

void change_stage::on_pushButton_2_clicked()
{
    close();
}


void change_stage::on_pushButton_3_clicked()
{
    showMinimized();
}


void change_stage::on_pushButton_4_clicked()
{
    auto *list = new list_of_stages();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

