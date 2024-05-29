#include "change_prof.h"
#include "ui_change_prof.h"

change_prof::change_prof(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_prof)
{
    ui->setupUi(this);
}

change_prof::~change_prof()
{
    delete ui;
}
