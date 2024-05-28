#include "pgreeting.h"
#include "ui_pgreeting.h"
#include "add_theme.h"

pgreeting::pgreeting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pgreeting)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

pgreeting::~pgreeting()
{
    delete ui;
}

void pgreeting::on_pushButton_2_clicked()
{
    close();
}


void pgreeting::on_pushButton_3_clicked()
{
    showMinimized();
}


void pgreeting::on_pushButton_5_clicked()
{
    auto *add_t = new Add_theme();  // Создать окно логина
    add_t->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    add_t->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

