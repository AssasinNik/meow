#include "change_student.h"
#include "ui_change_student.h"
#include "list_of_students.h"
#include "role_type.h"

change_student::change_student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_student)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

change_student::~change_student()
{
    delete ui;
}

void change_student::on_pushButton_2_clicked()
{
    close();
}


void change_student::on_pushButton_3_clicked()
{
    showMinimized();
}


void change_student::on_pushButton_4_clicked()
{
    auto *list = new list_of_students();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

void change_student::setData(const QString &studentName, const QString &email, const QString &user_password) {
    int spaceIndex = studentName.indexOf(" "); // Ищем индекс первого пробела
    QString firstName = studentName.left(spaceIndex); // Получаем подстроку до первого пробела (это будет имя)
    QString lastName = studentName.mid(spaceIndex + 1);
    ui->lineEdit_2->setText(firstName);
    ui->lineEdit_3->setText(lastName);
    ui->lineEdit_5->setText(email);
    ui->lineEdit_6->setText(user_password);

    ui->lineEdit_2->setReadOnly(true); // Устанавливаем атрибут readOnly
    ui->lineEdit_2->setStyleSheet("background-color: #dddddd;"
                                       "border-radius: 15px;"
                                       "font: 14pt \"Karla\";"
                                       "padding-left: 10px;"
                                       "padding-right: 10px;"
                                       "border: 2px solid #6D55FF;");
    ui->lineEdit_3->setReadOnly(true); // Устанавливаем атрибут readOnly
    ui->lineEdit_3->setStyleSheet("background-color: #dddddd;"
                                       "border-radius: 15px;"
                                       "font: 14pt \"Karla\";"
                                       "padding-left: 10px;"
                                       "padding-right: 10px;"
                                       "border: 2px solid #6D55FF;");
    ui->lineEdit_5->setReadOnly(true); // Устанавливаем атрибут readOnly
    ui->lineEdit_5->setStyleSheet("background-color: #dddddd;"
                                       "border-radius: 15px;"
                                       "font: 14pt \"Karla\";"
                                       "padding-left: 10px;"
                                       "padding-right: 10px;"
                                       "border: 2px solid #6D55FF;");

}
void change_student::on_pushButton_clicked()
{
    IS_TABLE=false;
    // Получаем новые значения описания, финансирования и стадии

        QString newPassword = ui->lineEdit_6->text();
        QString newLogin = ui->lineEdit_5->text();

        // Выполняем запрос на обновление данных в таблице projects
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE students SET user_password = :description WHERE email = :projectName");
        updateQuery.bindValue(":description", newPassword);
        updateQuery.bindValue(":projectName", newLogin);

        if (updateQuery.exec()) {
            qDebug() << "Данные успешно обновлены";
            QMessageBox::information(this, "Успех", "Данные успешно обновлены");
        } else {
            qDebug() << "Ошибка обновления данных:" << updateQuery.lastError().text();
            QMessageBox::critical(this, "Ошибка", "Ошибка при обновлении данных: " + updateQuery.lastError().text());
        }
    auto *list = new list_of_students();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

