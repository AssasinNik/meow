#include "add_theme.h"
#include "ui_add_theme.h"
#include "greeting.h"
#include <QFileDialog>
#include "iostream"
Add_theme::Add_theme(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_theme)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QRegExp regex("[0-9]*");
    QRegExpValidator *validator = new QRegExpValidator(regex, ui->lineEdit_6);
    ui->lineEdit_6->setValidator(validator);
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
    auto *return_back = new Greeting();  // Создать окно логина
    return_back->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    return_back->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void Add_theme::on_pushButton_5_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Select a file to upload");
            if (fileName.isEmpty()) return;

            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)) {
                qDebug() << "Could not open file for reading.";
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
            } else {
                qDebug() << "File uploaded successfully with extension " << fileExtension;
            }
            file.close();
}


void Add_theme::on_pushButton_6_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Save file as");
    if (fileName.isEmpty()) return;

    QSqlQuery query("SELECT file_data, extension FROM files_12 ORDER BY id DESC LIMIT 1");
    if (query.next()) {
        QByteArray fileData = query.value(0).toByteArray();
        QString fileExtension = query.value(1).toString();
        QString completeFileName = fileName + "." + fileExtension;

        QFile file(completeFileName);
        if (!file.open(QIODevice::WriteOnly)) {
            qDebug() << "Could not open file for writing.";
            return;
        }
        file.write(fileData);
        file.close();
        qDebug() << "File downloaded successfully as " << completeFileName;
    } else {
        qDebug() << "No file found in the database.";
    }
}


void Add_theme::on_pushButton_clicked()
{
    if (ui->lineEdit_2->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Название должно быть заполнено.");
        return;
    }
    auto *return_back = new Greeting();  // Создать окно логина
    return_back->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    return_back->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

