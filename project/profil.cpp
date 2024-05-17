#include "profil.h"
#include "ui_profil.h"
#include "greeting.h"

Profil::Profil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Profil)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

Profil::~Profil()
{
    delete ui;
}

void Profil::on_pushButton_clicked()
{
    if (ui->lineEdit_7->text().length() <= 8) {
        QMessageBox::warning(this, "Ошибка", "Пароль должен содержать больше 8 символов.");
        return;
    }
    if (ui->lineEdit_7->text().contains(" ")) {
        QMessageBox::warning(this, "Ошибка", "Пароль не должен содержать пробелов.");
        return;
    }
    auto *greetWindow = new Greeting();  // Создать окно логина
    greetWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    greetWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void Profil::on_pushButton_2_clicked()
{
    close();
}


void Profil::on_pushButton_3_clicked()
{
    showMinimized();
}


void Profil::on_pushButton_4_clicked()
{
    auto *greetWindow = new Greeting();  // Создать окно логина
    greetWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    greetWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

