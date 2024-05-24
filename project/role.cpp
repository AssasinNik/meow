#include "role.h"
#include "ui_role.h"
#include "mainwindow.h"
#include "greeting.h"
#include "pgreeting.h"
#include "sgreeting.h"

Role::Role(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Role)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

Role::~Role()
{
    delete ui;
}

void Role::on_pushButton_2_clicked()
{
    close();
}


void Role::on_pushButton_3_clicked()
{
    showMinimized();
}


void Role::on_pushButton_6_clicked()
{
    auto *mWindow = new MainWindow();  // Создать окно логина
    mWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    mWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void Role::on_pushButton_clicked()
{
    auto *gWindow = new Greeting();  // Создать окно логина
    gWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    gWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void Role::on_pushButton_5_clicked()
{
    auto *pgWindow = new pgreeting();  // Создать окно логина
    pgWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    pgWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void Role::on_pushButton_4_clicked()
{
    auto *sgWindow = new sgreeting();  // Создать окно логина
    sgWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    sgWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

