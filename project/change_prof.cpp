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
    QString name = ui->lineEdit_2->text().trimmed();
    QString surname = ui->lineEdit_3->text().trimmed();
    QString newleaderPass = ui->lineEdit_6->text().trimmed();
    QString newleaderLogin = ui->lineEdit_5->text().trimmed();

    // Проверка на пустые поля
    if (newUchZv.isEmpty() || surname.isEmpty() || newleaderLogin.isEmpty()) {
        QMessageBox::warning(this, "Недостаточно данных", "Все поля должны быть заполнены.");
        return;
    }

    // Проверка на недопустимые символы в имени и фамилии
    QRegExp nameRegex("^[a-zA-Zа-яА-Я\\s-]+$");
    if (!nameRegex.exactMatch(name) || !nameRegex.exactMatch(surname)) {
        QMessageBox::warning(this, "Некорректные данные", "Имя и фамилия должны содержать только буквы.");
        return;
    }

    // Проверка длины пароля
    if (newleaderPass.length() < 6) {
        QMessageBox::warning(this, "Слишком короткий пароль", "Пароль должен содержать не менее 6 символов.");
        return;
    }

    // Проверка формата электронной почты
    QRegExp emailRegEx("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}\\b");
    if (!emailRegEx.exactMatch(newleaderLogin)) {
        QMessageBox::warning(this, "Некорректный email", "Введите корректный адрес электронной почты.");
        return;
    }

    // Выполнение запроса на обновление данных
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Leaders SET User_Password = :pass, LeaderName = :name WHERE Email = :login");
    updateQuery.bindValue(":pass", newleaderPass);
    updateQuery.bindValue(":name", newUchZv + " " + name + " " + surname);
    updateQuery.bindValue(":login", newleaderLogin);

    if (updateQuery.exec()) {
        qDebug() << "Данные успешно обновлены";
        QMessageBox::information(this, "Успех", "Данные успешно обновлены");
    } else {
        qDebug() << "Ошибка обновления данных:" << updateQuery.lastError().text();
        QMessageBox::critical(this, "Ошибка", "Ошибка при обновлении данных: " + updateQuery.lastError().text());
    }

    auto *list = new list_of_prof();
    list->setAttribute(Qt::WA_DeleteOnClose);
    list->show();
    this->close();
}

