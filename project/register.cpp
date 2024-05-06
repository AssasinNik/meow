#include "register.h"
#include "ui_register.h"
#include "mainwindow.h"
#include "greeting.h"
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
    auto *greetWindow = new Greeting();  // Создать окно логина
    greetWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    greetWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

