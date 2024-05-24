#include "pgreeting.h"
#include "ui_pgreeting.h"

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

