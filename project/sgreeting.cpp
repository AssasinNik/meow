#include "sgreeting.h"
#include "ui_sgreeting.h"
#include "list_of_students.h"
#include "my_themes.h"
#include "list_of_themes.h"
#include "list_of_prof.h"

sgreeting::sgreeting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sgreeting)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

sgreeting::~sgreeting()
{
    delete ui;
}

void sgreeting::on_pushButton_7_clicked()
{
    auto *list_s = new list_of_students();  // Создать окно логина
    list_s->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list_s->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void sgreeting::on_pushButton_3_clicked()
{
    showMinimized();
}


void sgreeting::on_pushButton_2_clicked()
{
    close();
}


void sgreeting::on_pushButton_5_clicked()
{
    auto *list_my = new my_themes();
    list_my->setAttribute(Qt::WA_DeleteOnClose);
    list_my->show();
    this->close();
}


void sgreeting::on_pushButton_clicked()
{
    auto *list_t = new List_of_themes();
    list_t->setAttribute(Qt::WA_DeleteOnClose);
    list_t->show();
    this->close();
}


void sgreeting::on_pushButton_6_clicked()
{
    auto *list_p = new list_of_prof();
    list_p->setAttribute(Qt::WA_DeleteOnClose);
    list_p->show();
    this->close();
}

