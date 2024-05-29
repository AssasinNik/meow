#include "my_themes.h"
#include "ui_my_themes.h"
#include "sgreeting.h"
#include "pgreeting.h"
#include "role_type.h"

my_themes::my_themes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::my_themes)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

my_themes::~my_themes()
{
    delete ui;
}

void my_themes::on_pushButton_2_clicked()
{
    close();
}


void my_themes::on_pushButton_3_clicked()
{
    showMinimized();
}


void my_themes::on_pushButton_4_clicked()
{
    if(IS_STUDENT == true){
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

