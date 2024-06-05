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
    // Получаем новые значения описания, финансирования и стадии

        QString newstageName = ui->lineEdit_2->text();
        QString newDescription = ui->textEdit->toPlainText();
        QString newLength = ui->lineEdit_4->text();
        QString newDifficulty = ui->comboBox->currentText();

        // Выполняем запрос на обновление данных в таблице projects
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE stages SET stagedescription = :description, recommendlength = :length, difficulty = :diff WHERE stagename = :projectName");
        updateQuery.bindValue(":description", newDescription);
        updateQuery.bindValue(":projectName", newstageName);
        updateQuery.bindValue(":length", newLength);
        updateQuery.bindValue(":diff", newDifficulty);

        if (updateQuery.exec()) {
            qDebug() << "Данные успешно обновлены";
            QMessageBox::information(this, "Успех", "Данные успешно обновлены");
        } else {
            qDebug() << "Ошибка обновления данных:" << updateQuery.lastError().text();
            QMessageBox::critical(this, "Ошибка", "Ошибка при обновлении данных: " + updateQuery.lastError().text());
        }

    auto *list = new list_of_stages();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

