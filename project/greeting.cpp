#include "greeting.h"
#include "ui_greeting.h"

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
