#include "sgreeting.h"
#include "ui_sgreeting.h"

sgreeting::sgreeting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sgreeting)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

sgreeting::~sgreeting()
{
    delete ui;
}
