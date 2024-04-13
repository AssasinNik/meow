#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"

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
}


void MainWindow::on_pushButton_2_clicked()
{
    close();
}


void MainWindow::on_pushButton_3_clicked()
{
    showMinimized();
}


void MainWindow::on_label_4_linkActivated(const QString &link)
{
    if (link == "login") {
            auto *loginWindow = new Login();  // Создать окно логина
            loginWindow->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
            loginWindow->show();
            this->close(); // Скрываем текущее окно вместо закрытия
        }
}

