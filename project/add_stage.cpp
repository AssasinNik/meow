#include "add_stage.h"
#include "ui_add_stage.h"
#include "list_of_stages.h"

add_stage::add_stage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_stage)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->comboBox->addItem("Низкая");
    ui->comboBox->addItem("Средняя");
    ui->comboBox->addItem("Сложная");

    QIntValidator *lengthValidator = new QIntValidator(1, 10000, this); // допустим длительность от 1 до 10000
        ui->lineEdit_4->setValidator(lengthValidator);
}

add_stage::~add_stage()
{
    delete ui;
}

void add_stage::on_pushButton_2_clicked()
{
    close();
}


void add_stage::on_pushButton_3_clicked()
{
    showMinimized();
}


void add_stage::on_pushButton_4_clicked()
{
    auto *list = new list_of_stages();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

void add_stage::on_pushButton_clicked()
{
    QString stageName = ui->lineEdit_2->text().trimmed(); // Получение и очистка поля для имени стадии
    QString stageDescription = ui->textEdit->toPlainText().trimmed(); // Получение и очистка поля для описания
    QString lengthText = ui->lineEdit_4->text().trimmed(); // Получение и очистка поля для длительности
    QString difficulty = ui->comboBox->currentText(); // Использование текущего значения QComboBox для уровня сложности

    // Проверка на наличие цифр в названии стадии
    QRegExp regex("[\\d]");
    if (regex.indexIn(stageName) != -1) {
        QMessageBox::warning(this, "Ошибка ввода", "Название стадии не должно содержать цифр.");
        return;
    }

    // Проверка на пустые поля
    if (stageName.isEmpty() || lengthText.isEmpty()) {
        QMessageBox::warning(this, "Незаполненные поля", "Все поля должны быть заполнены.");
        return;
    }

    // Проверка, что длина является числом
    bool ok;
    int recommendedLength = lengthText.toInt(&ok);
    if (!ok || recommendedLength <= 0) {
        QMessageBox::warning(this, "Некорректная длительность", "Длительность должна быть положительным числом.");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Stages (StageName, StageDescription, RecommendLength, Difficulty) "
                  "VALUES (:StageName, :StageDescription, :RecommendLength, :Difficulty)");
    query.bindValue(":StageName", stageName);
    query.bindValue(":StageDescription", stageDescription);
    query.bindValue(":RecommendLength", recommendedLength);
    query.bindValue(":Difficulty", difficulty);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось добавить этап: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Успешно", "Этап успешно добавлен.");
    }

    auto *list = new list_of_stages();  // Создать окно списка стадий
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

