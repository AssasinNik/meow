#include "list_of_stages.h"
#include "ui_list_of_stages.h"
#include "add_theme.h"
#include "add_stage.h"
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

list_of_stages::list_of_stages(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list_of_stages)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

list_of_stages::~list_of_stages()
{
    delete ui;
}

void list_of_stages::on_pushButton_4_clicked()
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


void list_of_stages::on_pushButton_3_clicked()
{
    showMinimized();
}


void list_of_stages::on_pushButton_2_clicked()
{
    close();
}


void list_of_stages::on_pushButton_clicked()
{
    auto *add = new add_stage();
    add->setAttribute(Qt::WA_DeleteOnClose);
    add->show();
    this->close();
}

