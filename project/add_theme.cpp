#include "add_theme.h"
#include "ui_add_theme.h"
#include "list_of_themes.h"
#include "greeting.h"
#include "pgreeting.h"
#include "sgreeting.h"
#include <QFileDialog>
#include "role_type.h"
#include "iostream"
Add_theme::Add_theme(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_theme)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QIntValidator *validator = new QIntValidator(0, 400000, this);
    ui->lineEdit_6->setValidator(validator);
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(400000);

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSlider_valueChanged(int)));
    connect(ui->lineEdit_6, SIGNAL(textChanged(const QString &)), this, SLOT(on_lineEdit_6_textChanged(const QString &)));
}
QByteArray fileData;
QString fileExtension;
Add_theme::~Add_theme()
{
    delete ui;
}

void Add_theme::on_pushButton_2_clicked()
{
    close();
}


void Add_theme::on_pushButton_3_clicked()
{
    showMinimized();
}


void Add_theme::on_pushButton_4_clicked()
{
    if(IS_TABLE == true){
        IS_TABLE=false;
        auto *list = new List_of_themes();  // Создать окно логина
        list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
        list->show();
        this->close(); // Скрываем текущее окно вместо закрытия
    }
    else{
        auto *greet = new pgreeting();  // Создать окно логина
        greet->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
        greet->show();
        this->close(); // Скрываем текущее окно вместо закрытия
    }
}


void Add_theme::on_pushButton_5_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Select a file to upload");
    if (fileName.isEmpty()) {
        ui->label_8->setText("Не удалось прикрепить файл");
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open file for reading.";
        ui->label_8->setText("Не удалось прикрепить файл");
        return;
    }

    fileData = file.readAll();
    fileExtension = QFileInfo(fileName).suffix();
    if (fileExtension==" ") {
        ui->label_8->setText("Не удалось прикрепить файл");
    } else {
        ui->label_8->setText("Прикреплен файл: " + QFileInfo(fileName).fileName());
    }
    file.close();
}
void Add_theme::on_lineEdit_6_textChanged(const QString &text)
{
    bool ok;
    int value = text.toInt(&ok);
    if (ok) {
        if (value > 400000) {
            ui->lineEdit_6->setText("400000");
            value = 400000;
        }
        ui->horizontalSlider->setValue(value);
    }
}

void Add_theme::on_horizontalSlider_valueChanged(int value)
{
    ui->lineEdit_6->setText(QString::number(value));
}

void Add_theme::on_pushButton_clicked()
{
    QString projectName = ui->lineEdit_2->text().trimmed();
    QString information = ui->lineEdit_3->text().trimmed();
    QString funding = ui->lineEdit_6->text().trimmed();

    // Проверка на пустые или несодержательные строки
    if (projectName.isEmpty() || information.isEmpty() || funding.isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Поля 'Название проекта', 'Информация', 'Финансирование' не должны быть пустыми.");
        return;
    }

    QSqlQuery query;
    query.exec("SELECT MAX(projectid) FROM projects");
    int projectID = 1; // Стартуем с 1, если таблица пуста
    if (query.next()) {
        projectID = query.value(0).toInt() + 1; // Получаем следующий ID
    }

    QDate currentDate = QDate::currentDate();
    QString formattedDate = currentDate.toString("yyyy-MM-dd");

    query.exec("SELECT MIN(stageid) FROM stages");
    int minStageId = -1;
    if (query.next()) {
        minStageId = query.value(0).toInt();
    }

    query.prepare("INSERT INTO projects (projectid, projectname, start_date, end_date, information, file, file_index, funding, stageid) "
                  "VALUES (:projectid, :projectname, :start_date, NULL, :information, :file, :file_index, :funding, :stageid)");
    query.bindValue(":projectid", projectID);
    query.bindValue(":projectname", projectName);
    query.bindValue(":start_date", formattedDate);
    query.bindValue(":information", information);
    query.bindValue(":file", fileData);
    query.bindValue(":file_index", fileExtension);
    query.bindValue(":funding", funding);
    query.bindValue(":stageid", minStageId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось добавить проект: " + query.lastError().text());
        return;
    } else {
        QMessageBox::information(this, "Успешно", "Проект успешно добавлен.");
    }

    // Окно после добавления проекта
    if(IS_TABLE == true){
        IS_TABLE=false;
        auto *list = new List_of_themes();  // Создать окно списка тем
        list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
        list->show();
        this->close(); // Скрываем текущее окно вместо закрытия
    }
    else{
        auto *greet = new pgreeting();  // Создать окно приветствия
        greet->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
        greet->show();
        this->close(); // Скрываем текущее окно вместо закрытия
    }
}

