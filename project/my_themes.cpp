#include "my_themes.h"
#include "ui_my_themes.h"
#include "greeting.h"

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
    auto *return_back = new Greeting();  // Создать окно логина
    return_back->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    return_back->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

