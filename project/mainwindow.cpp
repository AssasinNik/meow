#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "role.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QStandardItemModel>
#include <QTableView>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    auto *RegisterWindow = new Role();  // Создать окно логина
    RegisterWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    RegisterWindow->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void MainWindow::on_pushButton_2_clicked()
{
    close();
}


void MainWindow::on_pushButton_3_clicked()
{
    showMinimized();
}

