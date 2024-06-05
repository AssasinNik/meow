#include "add_prof.h"
#include "ui_add_prof.h"
#include "list_of_prof.h"

add_prof::add_prof(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_prof)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->comboBox->addItem("Доцент");
    ui->comboBox->addItem("Профессор");
}

add_prof::~add_prof()
{
    delete ui;
}

void add_prof::on_pushButton_2_clicked()
{
    close();
}


void add_prof::on_pushButton_3_clicked()
{
    showMinimized();
}


void add_prof::on_pushButton_4_clicked()
{
    auto *list = new list_of_prof();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void add_prof::on_pushButton_clicked()
{
    QString title = ui->comboBox->currentText();
    QString firstName = ui->lineEdit_2->text().trimmed();
    QString lastName = ui->lineEdit_3->text().trimmed();
    QString email = ui->lineEdit_5->text().trimmed();
    QString password = ui->lineEdit_6->text().trimmed();

    // Проверка на пустые поля
    if (firstName.isEmpty() || lastName.isEmpty() || email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Недостаточно данных", "Все поля должны быть заполнены.");
        return;
    }

    // Проверка на наличие цифр в именах
    QRegExp regex("[\\d]");
    if (regex.indexIn(firstName) != -1 || regex.indexIn(lastName) != -1) {
        QMessageBox::warning(this, "Ошибка данных", "Имена не должны содержать цифры.");
        return;
    }

    // Проверка формата электронной почты
    QRegExp emailRegEx("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}\\b");
    if (!emailRegEx.exactMatch(email)) {
        QMessageBox::warning(this, "Некорректный email", "Введите корректный адрес электронной почты.");
        return;
    }

    // Проверка минимальной длины пароля
    if (password.length() < 6) {
        QMessageBox::warning(this, "Слишком короткий пароль", "Пароль должен содержать не менее 6 символов.");
        return;
    }

    QString leaderName = title + " " + firstName + " " + lastName;

    QSqlQuery query;
    query.exec("SELECT MAX(LeaderID) FROM Leaders");
    int newLeaderID = 1;
    if (query.next()) {
        newLeaderID = query.value(0).toInt() + 1;
    }

    query.prepare("INSERT INTO Leaders (LeaderID, LeaderName, Email, User_Password) "
                  "VALUES (:LeaderID, :LeaderName, :Email, :User_Password)");
    query.bindValue(":LeaderID", newLeaderID);
    query.bindValue(":LeaderName", leaderName);
    query.bindValue(":Email", email);
    query.bindValue(":User_Password", password);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось добавить преподавателя: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Успешно", "Преподаватель успешно добавлен.");
    }

    auto *list = new list_of_prof();
    list->setAttribute(Qt::WA_DeleteOnClose);
    list->show();
    this->close();
}

