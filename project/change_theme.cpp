#include "change_theme.h"
#include "ui_change_theme.h"

change_theme::change_theme(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_theme)
{
    ui->setupUi(this);
}

change_theme::~change_theme()
{
    delete ui;
}
