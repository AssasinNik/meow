#include "greeting.h"
#include "ui_greeting.h"
#include "list_of_themes.h"
#include "list_of_stages.h"
#include "list_of_students.h"
#include "list_of_prof.h"
#include "add_theme.h"
#include "my_themes.h"

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
    auto *list = new list_of_students();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
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
    auto *list = new list_of_stages();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void Greeting::on_pushButton_6_clicked()
{
    auto *list = new list_of_prof();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

