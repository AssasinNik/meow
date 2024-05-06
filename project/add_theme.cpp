#include "add_theme.h"
#include "ui_add_theme.h"
#include "greeting.h"

Add_theme::Add_theme(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_theme)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QRegExp regex("[0-9]*");
    QRegExpValidator *validator = new QRegExpValidator(regex, ui->lineEdit_6);
    ui->lineEdit_6->setValidator(validator);
}

Add_theme::~Add_theme()
{
    delete ui;
}

void Add_theme::on_pushButton_2_clicked()
{
    close();
}


void Add_theme::on_pushButton_3_clicked()
{
    showMinimized();
}


void Add_theme::on_pushButton_4_clicked()
{
    auto *return_back = new Greeting();  // Создать окно логина
    return_back->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    return_back->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

