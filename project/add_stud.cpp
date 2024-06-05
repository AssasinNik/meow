#include "add_stud.h"
#include "ui_add_stud.h"
#include "list_of_students.h"

add_stud::add_stud(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_stud)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

add_stud::~add_stud()
{
    delete ui;
}

void add_stud::on_pushButton_2_clicked()
{
    close();
}


void add_stud::on_pushButton_3_clicked()
{
    showMinimized();
}


void add_stud::on_pushButton_4_clicked()
{
    auto *list = new list_of_students();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void add_stud::on_pushButton_clicked()
{
    QString firstName = ui->lineEdit_3->text().trimmed(); // QLineEdit для имени студента
       QString lastName = ui->lineEdit_2->text().trimmed(); // QLineEdit для фамилии студента
       QString email = ui->lineEdit_5->text().trimmed(); // QLineEdit для электронной почты
       QString password = ui->lineEdit_6->text(); // QLineEdit для пароля

       // Проверка имен и фамилий на наличие цифр
       QRegExp nameRegEx("[\\d]");
       if (nameRegEx.indexIn(firstName) != -1 || nameRegEx.indexIn(lastName) != -1) {
           QMessageBox::warning(this, "Некорректные данные", "Имя и фамилия не должны содержать цифры.");
           return;
       }

       // Проверка, что email соответствует формату электронной почты
       QRegExp emailRegEx("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}\\b");
       if (!emailRegEx.exactMatch(email)) {
           QMessageBox::warning(this, "Некорректный email", "Введите корректный адрес электронной почты.");
           return;
       }

       // Проверка на минимальную длину пароля
       if (password.length() < 6) {
           QMessageBox::warning(this, "Слишком короткий пароль", "Пароль должен содержать не менее 6 символов.");
           return;
       }
        QSqlQuery query;
        query.exec("SELECT MAX(Student_ID_Card) FROM Students");
        int studentID = 1; // Стартуем с 1, если таблица пуста
        if (query.next()) {
            studentID = query.value(0).toInt() + 1; // Получаем следующий ID
        }
        QString studentName = ui->lineEdit_3->text() + " " + ui->lineEdit_2->text(); // QLineEdit для имени студента

        query.prepare("INSERT INTO Students (Student_ID_Card, StudentName, Email, User_Password) "
                      "VALUES (:Student_ID_Card, :StudentName, :Email, :User_Password)");
        query.bindValue(":Student_ID_Card", studentID);
        query.bindValue(":StudentName", studentName);
        query.bindValue(":Email", email);
        query.bindValue(":User_Password", password);

        if (!query.exec()) {
            QMessageBox::critical(this, "Ошибка", "Не удалось добавить студента: " + query.lastError().text());
        } else {
            QMessageBox::information(this, "Успешно", "Студент успешно добавлен.");
        }
        auto *list = new list_of_students();  // Создать окно логина
        list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
        list->show();
        this->close(); // Скрываем текущее окно вместо закрытия
}

