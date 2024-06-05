#include "login.h"
#include "ui_login.h"
#include "role_type.h"
#include "role.h"
#include "greeting.h"
#include "sgreeting.h"
#include "pgreeting.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include "iostream"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_2_clicked()
{
    close();
}


void login::on_pushButton_3_clicked()
{
    showMinimized();
}


void login::on_pushButton_4_clicked()
{
    auto *role_choice = new Role();
    role_choice->setAttribute(Qt::WA_DeleteOnClose);
    role_choice->show();
    this->close();
}


void login::on_pushButton_clicked()
{
    if(IS_ADMIN == true){
        if(ui->lineEdit_2->text() == "admin_user" && ui->lineEdit_3->text() == "adminPass"){
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
            auto *greeting = new Greeting();
            greeting->setAttribute(Qt::WA_DeleteOnClose);
            greeting->show();
            this->close();
        }
        else{
            QMessageBox::critical(this, "Ошибка", "Неверный логин или пароль");
        }
    }
    else if(IS_STUDENT == true){
        if(ui->lineEdit_2->text() == "uni_student" && ui->lineEdit_3->text() == "studentPass"){
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
            auto *greeting = new sgreeting();
            greeting->setAttribute(Qt::WA_DeleteOnClose);
            greeting->show();
            this->close();
        }
        else{
            QMessageBox::critical(this, "Ошибка", "Неверный логин или пароль");
        }
    }
    else if(IS_PROFESSOR == true){
        if(ui->lineEdit_2->text() == "professor" && ui->lineEdit_3->text() == "professorPass"){
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
            auto *greeting = new pgreeting();
            greeting->setAttribute(Qt::WA_DeleteOnClose);
            greeting->show();
            this->close();
        }
        else{
            QMessageBox::critical(this, "Ошибка", "Неверный логин или пароль");
        }
    }
}

