#include "custombutton.h"
#include "ui_custombutton.h"

CustomButton::CustomButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomButton)
{
    ui->setupUi(this);
}

CustomButton::~CustomButton()
{
    delete ui;
}
