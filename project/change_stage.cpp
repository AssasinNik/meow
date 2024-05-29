#include "change_stage.h"
#include "ui_change_stage.h"

change_stage::change_stage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_stage)
{
    ui->setupUi(this);
}

change_stage::~change_stage()
{
    delete ui;
}
