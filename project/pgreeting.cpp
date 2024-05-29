#include "pgreeting.h"
#include "ui_pgreeting.h"
#include "my_themes.h"
#include "add_theme.h"
#include "list_of_themes.h"
#include "list_of_students.h"

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


void pgreeting::on_pushButton_6_clicked()
{
      auto *my = new my_themes();
      my->setAttribute(Qt::WA_DeleteOnClose);
      my->show();
      this->close();
}


void pgreeting::on_pushButton_clicked()
{
    auto *list = new List_of_themes();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void pgreeting::on_pushButton_7_clicked()
{
    auto *list = new list_of_students();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

