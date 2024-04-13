#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_2_clicked()
{
    close();
}


void Login::on_pushButton_3_clicked()
{
    showMinimized();
}

