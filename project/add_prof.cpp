#include "add_prof.h"
#include "ui_add_prof.h"
#include "list_of_prof.h"

add_prof::add_prof(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_prof)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
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
    QString leaderName = ui->lineEdit_7->text()+ui->lineEdit_2->text()+ui->lineEdit_3->text(); // QLineEdit для имени лидера
        QString email = ui->lineEdit_5->text(); // QLineEdit для электронной почты
        QString password = ui->lineEdit_6->text(); // QLineEdit для пароля

        QSqlQuery query;
        query.exec("SELECT MAX(LeaderID) FROM Leaders");
        int newLeaderID = 1; // Начинаем с 1, если таблица пуста
        if (query.next()) {
            newLeaderID = query.value(0).toInt() + 1; // Получаем следующий ID
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
            QMessageBox::information(this, "Успешно", "Преподаватель успешно добавлен с ID " + QString::number(newLeaderID) + ".");
        }
        auto *list = new list_of_prof();  // Создать окно логина
        list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
        list->show();
        this->close(); // Скрываем текущее окно вместо закрытия
}

