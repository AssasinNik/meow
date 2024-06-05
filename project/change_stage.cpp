#include "change_stage.h"
#include "ui_change_stage.h"
#include "list_of_stages.h"

change_stage::change_stage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_stage)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->comboBox->addItem("Низкая");
    ui->comboBox->addItem("Средняя");
    ui->comboBox->addItem("Сложная");

    QIntValidator *lengthValidator = new QIntValidator(1, 10000, this);
    ui->lineEdit_4->setValidator(lengthValidator);
}

change_stage::~change_stage()
{
    delete ui;
}

void change_stage::on_pushButton_2_clicked()
{
    close();
}


void change_stage::on_pushButton_3_clicked()
{
    showMinimized();
}

void change_stage::setData(const QString &stageName, const QString &stageDesc, const QString &recommendLen, const QString &difficulty) {
    ui->lineEdit_2->setText(stageName);
    ui->lineEdit_4->setText(recommendLen);
    ui->comboBox->setCurrentText(difficulty);
    ui->textEdit->setText(stageDesc);

    ui->lineEdit_2->setReadOnly(true); // Устанавливаем атрибут readOnly
    ui->lineEdit_2->setStyleSheet("background-color: #dddddd;"
                                       "border-radius: 15px;"
                                       "font: 14pt \"Karla\";"
                                       "padding-left: 10px;"
                                       "padding-right: 10px;"
                                       "border: 2px solid #6D55FF;");

}
void change_stage::on_pushButton_4_clicked()
{
    auto *list = new list_of_stages();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void change_stage::on_pushButton_clicked()
{
    QString newStageName = ui->lineEdit_2->text().trimmed();
    QString newDescription = ui->textEdit->toPlainText().trimmed();
    QString newLength = ui->lineEdit_4->text().trimmed();
    QString newDifficulty = ui->comboBox->currentText();

    // Проверка на наличие цифр в названии стадии
    QRegExp regex("[\\d]");
    if (regex.indexIn(newStageName) != -1) {
        QMessageBox::warning(this, "Ошибка ввода", "Название стадии не должно содержать цифр.");
        return;
    }

    // Проверка на пустые поля
    if (newStageName.isEmpty() || newLength.isEmpty()) {
        QMessageBox::warning(this, "Незаполненные поля", "Все поля должны быть заполнены.");
        return;
    }

    // Проверка, что длительность является числом
    bool ok;
    int recommendedLength = newLength.toInt(&ok);
    if (!ok || recommendedLength <= 0) {
        QMessageBox::warning(this, "Некорректная длительность", "Длительность должна быть положительным числом.");
        return;
    }

    // Выполняем запрос на обновление данных в таблице Stages
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Stages SET StageDescription = :description, RecommendLength = :length, Difficulty = :diff WHERE StageName = :stageName");
    updateQuery.bindValue(":description", newDescription);
    updateQuery.bindValue(":length", recommendedLength);
    updateQuery.bindValue(":diff", newDifficulty);
    updateQuery.bindValue(":stageName", newStageName);

    if (!updateQuery.exec()) {
        qDebug() << "Ошибка обновления данных:" << updateQuery.lastError().text();
        QMessageBox::critical(this, "Ошибка", "Ошибка при обновлении данных: " + updateQuery.lastError().text());
    } else {
        QMessageBox::information(this, "Успех", "Данные успешно обновлены");
    }

    auto *list = new list_of_stages();  // Создать окно списка стадий
    list->setAttribute(Qt::WA_DeleteOnClose);
    list->show();
    this->close();
}
