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
    QString stageName = ui->lineEdit_2->text(); // Предполагается наличие QLineEdit для имени этапа
    QString stageDescription = ui->textEdit->toPlainText(); // Предполагается наличие QTextEdit для описания
    int recommendedLength = (ui->lineEdit_4->text()).toInt(); // Предполагается наличие QSpinBox для длительности
    QString difficulty = ui->comboBox->currentText(); // Использование текущего значения QComboBox для уровня сложности

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
    auto *list = new list_of_stages();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

