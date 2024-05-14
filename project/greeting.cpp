#include "greeting.h"
#include "ui_greeting.h"
#include "list_of_themes.h"
#include "add_theme.h"
#include "my_themes.h"
#include "profil.h"

Greeting::Greeting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Greeting)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

Greeting::~Greeting()
{
    delete ui;
}

void Greeting::on_pushButton_7_clicked()
{
    auto *list_my = new my_themes();  // Создать окно логина
    list_my->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list_my->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void Greeting::on_pushButton_clicked()
{
    auto *list = new List_of_themes();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void Greeting::on_pushButton_2_clicked()
{
    close();
}
void Greeting::on_pushButton_3_clicked()
{
    showMinimized();
}



void Greeting::on_pushButton_5_clicked()
{
    auto *add = new Add_theme();  // Создать окно логина
    add->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    add->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void Greeting::on_pushButton_6_clicked()
{
    auto *profil = new class profil();  // Создать окно логина
    profil->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    profil->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

