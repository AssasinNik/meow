#include "register.h"
#include "ui_register.h"
#include "mainwindow.h"
#include "list_of_themes.h"
Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->lineEdit_5->setEchoMode(QLineEdit::Password);
    ui->comboBox->addItem("Студент");
    ui->comboBox->addItem("Преподаватель");
}


Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_2_clicked()
{
    close();
}


void Register::on_pushButton_3_clicked()
{
    showMinimized();
}


void Register::on_pushButton_4_clicked()
{
    auto *mainWindow = new MainWindow();  // Создать окно логина
    mainWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    mainWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void Register::on_pushButton_clicked()
{
    auto *list_of_themesWindow = new List_of_themes();  // Создать окно логина
    list_of_themesWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list_of_themesWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

