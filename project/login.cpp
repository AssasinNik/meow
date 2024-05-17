#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "greeting.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->lineEdit->setEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_2_clicked()
{
    close();
}


void Login::on_pushButton_3_clicked()
{
    showMinimized();
}

void Login::on_lineEdit_cursorPositionChanged(int, int){

}

void Login::on_pushButton_4_clicked()
{
    auto *greetWindow = new MainWindow();  // Создать окно логина
    greetWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    greetWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void Login::on_pushButton_clicked()
{
    // Проверка, заполнены ли все поля
    if (ui->lineEdit_2->text().isEmpty() || ui->lineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены.");
        return;
    }
    QRegularExpression emailRegex("[\\w-]+(\\.[\\w-]+)*@[\\w-]+(\\.[\\w-]+)+");
    if (!emailRegex.match(ui->lineEdit_2->text()).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Некорректный email адрес.");
        return;
    }
    auto *greetWindow = new Greeting();  // Создать окно логина
    greetWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    greetWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

