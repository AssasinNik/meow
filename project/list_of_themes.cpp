#include "list_of_themes.h"
#include "ui_list_of_themes.h"
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>
#include <QTableView>

List_of_themes::List_of_themes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::List_of_themes)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost"); // Имя хоста
    db.setDatabaseName("film_app.db"); // Имя базы данных
    db.setUserName("postgres"); // Имя пользователя
    db.setPassword("Parol1810!"); // Пароль
    db.open();

    QSqlTableModel *model = new QSqlTableModel(parent, db);
    model->setTable("movies"); // Название вашей таблицы в базе данных
    model->select();
    ui->tableView->setModel(model);
}

List_of_themes::~List_of_themes()
{
    delete ui;
}

void List_of_themes::on_pushButton_2_clicked()
{
    close();
}


void List_of_themes::on_pushButton_3_clicked()
{
    showMinimized();
}


void List_of_themes::on_pushButton_4_clicked()
{
    auto *mainWindow = new MainWindow();  // Создать окно логина
    mainWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    mainWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

