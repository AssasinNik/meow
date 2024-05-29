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
    // Установка соединения с базой данных
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("science");
    db.setUserName("cherenkov_pg");
    db.setPassword("Parol1810");
            if (!db.open()) {
                qDebug() << "Database error occurred:" << db.lastError();
                return;
            }
            QSqlQuery query;
            query.exec("CREATE TABLE IF NOT EXISTS files_12 (id SERIAL PRIMARY KEY, file_data BYTEA, extension TEXT)");
}

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

    QByteArray fileData = file.readAll();
    QString fileExtension = QFileInfo(fileName).suffix();

    QSqlQuery query;
    query.prepare("INSERT INTO files_12 (file_data, extension) VALUES (:file_data, :extension)");
    query.bindValue(":file_data", fileData);
    query.bindValue(":extension", fileExtension);
    if (!query.exec()) {
        qDebug() << "Error inserting file into the database:" << query.lastError();
        ui->label_8->setText("Не удалось прикрепить файл");
    } else {
        qDebug() << "File uploaded successfully with extension " << fileExtension;
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
    if (ui->lineEdit_2->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Название должно быть заполнено.");
        return;
    }
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

