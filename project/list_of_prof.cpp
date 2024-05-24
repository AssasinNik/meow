#include "list_of_prof.h"
#include "ui_list_of_prof.h"
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

list_of_prof::list_of_prof(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list_of_prof)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

list_of_prof::~list_of_prof()
{
    delete ui;
}

void list_of_prof::on_pushButton_4_clicked()
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


void list_of_prof::on_pushButton_3_clicked()
{
    showMinimized();
}


void list_of_prof::on_pushButton_2_clicked()
{
    close();
}

