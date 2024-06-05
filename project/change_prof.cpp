#include "change_prof.h"
#include "ui_change_prof.h"
#include "list_of_prof.h"

change_prof::change_prof(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_prof)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->comboBox->addItem("Доцент");
    ui->comboBox->addItem("Профессор");
}

change_prof::~change_prof()
{
    delete ui;
}

void change_prof::on_pushButton_2_clicked()
{
    close();
}


void change_prof::on_pushButton_3_clicked()
{
    showMinimized();
}
void change_prof::setData(const QString &leaderName, const QString &leaderEmail, const QString &leaderPass) {
    int firstSpaceIndex = leaderName.indexOf(" "); // Индекс первого пробела
    int secondSpaceIndex = leaderName.indexOf(" ", firstSpaceIndex + 1); // Индекс второго пробела

    QString ucheb_zv = leaderName.left(firstSpaceIndex); // Получаем подстроку до первого пробела (это будет имя)
    QString firstName = leaderName.mid(firstSpaceIndex + 1, secondSpaceIndex - firstSpaceIndex - 1); // Получаем подстроку между первым и вторым пробелом (это будет второе имя)
    QString secondName = leaderName.mid(secondSpaceIndex + 1);

    ui->comboBox->setCurrentText(ucheb_zv);
    ui->lineEdit_2->setText(firstName);
    ui->lineEdit_3->setText(secondName);
    ui->lineEdit_5->setText(leaderEmail);
    ui->lineEdit_6->setText(leaderPass);


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

void change_prof::on_pushButton_4_clicked()
{
    auto *list = new list_of_prof();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void change_prof::on_pushButton_clicked()
{
    QString newUchZv = ui->comboBox->currentText();
    QString name = ui->lineEdit_2->text();
    QString surname = ui->lineEdit_3->text();
    QString newleaderPass =  ui->lineEdit_6->text();
    QString newleaderLogin = ui->lineEdit_5->text();

    // Выполняем запрос на обновление данных в таблице projects
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE leaders SET user_password = :pass, leadername = :name WHERE email = :login");
    updateQuery.bindValue(":pass", newleaderPass);
    updateQuery.bindValue(":name", newUchZv+ " " +name+ " " +surname);
    updateQuery.bindValue(":login", newleaderLogin);

    if (updateQuery.exec()) {
        qDebug() << "Данные успешно обновлены";
        QMessageBox::information(this, "Успех", "Данные успешно обновлены");
    } else {
        qDebug() << "Ошибка обновления данных:" << updateQuery.lastError().text();
        QMessageBox::critical(this, "Ошибка", "Ошибка при обновлении данных: " + updateQuery.lastError().text());
    }

    auto *list = new list_of_prof();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

