#include "role.h"
#include "ui_role.h"
#include "mainwindow.h"
#include "greeting.h"
#include "pgreeting.h"
#include "sgreeting.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include "role_type.h"
#include "iostream"

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
    IS_ADMIN=true;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("science");
    db.setUserName("admin_user");
    db.setPassword("adminPass");
    if (!db.open()) {
        std::cerr << "Не удалось открыть соединение с базой данных" << std::endl;
    }
    else{
        std::cout << "Соединение с базой данных установлено" << std::endl;
    }
    auto *gWindow = new Greeting();  // Создать окно логина
    gWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    gWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void Role::on_pushButton_5_clicked()
{
    IS_PROFESSOR=true;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("science");
    db.setUserName("professor");
    db.setPassword("professorPass");
    if (!db.open()) {
        std::cerr << "Не удалось открыть соединение с базой данных" << std::endl;
    }
    else{
        std::cout << "Соединение с базой данных установлено" << std::endl;
    }
    auto *pgWindow = new pgreeting();  // Создать окно логина
    pgWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    pgWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void Role::on_pushButton_4_clicked()
{
    IS_STUDENT=true;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("science");
    db.setUserName("uni_student");
    db.setPassword("studentPass");
    if (!db.open()) {
        std::cerr << "Не удалось открыть соединение с базой данных" << std::endl;
    }
    else{
        std::cout << "Соединение с базой данных установлено" << std::endl;
    }
    auto *sgWindow = new sgreeting();  // Создать окно логина
    sgWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    sgWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

