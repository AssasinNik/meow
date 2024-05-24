#include "list_of_students.h"
#include "ui_list_of_students.h"
#include <QSqlDatabase>
#include <QMenu>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QStandardItemModel>
#include <QTableView>
#include "role_type.h"
#include "greeting.h"
#include "sgreeting.h"
#include "pgreeting.h"
#include <iostream>

list_of_students::list_of_students(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list_of_students)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

list_of_students::~list_of_students()
{
    delete ui;
}

void list_of_students::on_pushButton_2_clicked()
{
    close();
}


void list_of_students::on_pushButton_3_clicked()
{
    showMinimized();
}


void list_of_students::on_pushButton_4_clicked()
{
    if(IS_ADMIN == true){
        auto *greeting = new Greeting();
        greeting->setAttribute(Qt::WA_DeleteOnClose);
        greeting->show();
        this->close();
    }
    else if(IS_STUDENT == true){
        auto *greeting = new sgreeting();
        greeting->setAttribute(Qt::WA_DeleteOnClose);
        greeting->show();
        this->close();
    }
    else if(IS_PROFESSOR == true){
        auto *greeting = new pgreeting();
        greeting->setAttribute(Qt::WA_DeleteOnClose);
        greeting->show();
        this->close();
    }
}

