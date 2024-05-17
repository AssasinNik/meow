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
    // Проверка, заполнены ли все поля
    if (ui->lineEdit_2->text().isEmpty() || ui->lineEdit_3->text().isEmpty() ||
        ui->lineEdit_4->text().isEmpty() || ui->lineEdit_5->text().isEmpty() ||
        ui->comboBox->currentText().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены.");
        return;
    }

    // Проверка email
    QRegularExpression emailRegex("[\\w-]+(\\.[\\w-]+)*@[\\w-]+(\\.[\\w-]+)+");
    if (!emailRegex.match(ui->lineEdit_4->text()).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Некорректный email адрес.");
        return;
    }

    // Проверка длины пароля
    if (ui->lineEdit_5->text().length() <= 8) {
        QMessageBox::warning(this, "Ошибка", "Пароль должен содержать больше 8 символов.");
        return;
    }

    // Если все проверки пройдены, переход на другую форму
    auto *greetWindow = new Greeting();  // Создать окно приветствия
    greetWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    greetWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

