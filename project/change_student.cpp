#include "change_student.h"
#include "ui_change_student.h"

change_student::change_student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_student)
{
    ui->setupUi(this);
}

change_student::~change_student()
{
    delete ui;
}
