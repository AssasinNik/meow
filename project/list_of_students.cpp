#include "list_of_students.h"
#include "ui_list_of_students.h"
#include "add_stud.h"
#include <QSqlDatabase>
#include <QMenu>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QStandardItemModel>
#include <QTableView>
#include "role_type.h"
#include "greeting.h"
#include "sgreeting.h"
#include "pgreeting.h"
#include "change_student.h"
#include <iostream>

list_of_students::list_of_students(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list_of_students)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    if(IS_PROFESSOR==true || IS_STUDENT==true){
        ui->pushButton->close();
        ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
        ui->tableView->verticalHeader()->hide();
        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        // Выполнение запроса
        QSqlQuery query;
        if (!query.exec(R"(SELECT studentname, email FROM students;)")) {
            std::cerr << "Ошибка выполнения запроса: " << query.lastError().text().toStdString() << std::endl;
        }
        else {
            std::cout << "Запрос выполнен успешно" << std::endl;

            // Создание модели для TableView
            QStandardItemModel *model = new QStandardItemModel();
            model->setColumnCount(query.record().count());

            // Установка заголовков столбцов
            QStringList headers;
            headers << "Студент" << "Почта студента";
            model->setHorizontalHeaderLabels(headers);

            // Заполнение модели данными из запроса
            int row = 0;
            while (query.next()) {
                model->insertRow(row);
                for (int col = 0; col < query.record().count(); ++col) {
                    QModelIndex index = model->index(row, col, QModelIndex());
                    model->setData(index, query.value(col).toString());
                }
                ++row;
            }

            // Установка модели в TableView
            ui->tableView->setModel(model);
            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }
    }
    else{
        if(!IS_STUDENT){
            connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)),
                    this, SLOT(customMenuRequested(QPoint)));
        }
        ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
        ui->tableView->verticalHeader()->hide();
        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        // Выполнение запроса
        QSqlQuery query;
        if (!query.exec(R"(SELECT studentname, email, user_password FROM students;)")) {
            std::cerr << "Ошибка выполнения запроса: " << query.lastError().text().toStdString() << std::endl;
        }
        else {
            std::cout << "Запрос выполнен успешно" << std::endl;

            // Создание модели для TableView
            QStandardItemModel *model = new QStandardItemModel();
            model->setColumnCount(query.record().count());

            // Установка заголовков столбцов
            QStringList headers;
            headers << "Студент" << "Почта студента" << "Пароль студента";
            model->setHorizontalHeaderLabels(headers);

            // Заполнение модели данными из запроса
            int row = 0;
            while (query.next()) {
                model->insertRow(row);
                for (int col = 0; col < query.record().count(); ++col) {
                    QModelIndex index = model->index(row, col, QModelIndex());
                    model->setData(index, query.value(col).toString());
                }
                ++row;
            }

            // Установка модели в TableView
            ui->tableView->setModel(model);
            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }
    }

}

list_of_students::~list_of_students()
{
    delete ui;
}

void list_of_students::on_pushButton_2_clicked()
{
    close();
}


void list_of_students::on_pushButton_3_clicked()
{
    showMinimized();
}


void list_of_students::on_pushButton_4_clicked()
{
    if(IS_ADMIN == true){
        auto *greeting = new Greeting();
        greeting->setAttribute(Qt::WA_DeleteOnClose);
        greeting->show();
        this->close();
    }
    else if(IS_STUDENT == true){
        auto *greeting = new sgreeting();
        greeting->setAttribute(Qt::WA_DeleteOnClose);
        greeting->show();
        this->close();
    }
    else if(IS_PROFESSOR == true){
        auto *greeting = new pgreeting();
        greeting->setAttribute(Qt::WA_DeleteOnClose);
        greeting->show();
        this->close();
    }
}
void list_of_students::deleteRecord(QModelIndex index) {
    if (!index.isValid())
        return;

    int row = index.row();
    QString studentName = ui->tableView->model()->index(row, 0).data().toString(); // Предположим, что имя проекта находится во второй колонке

    QSqlDatabase::database().transaction();
    QSqlQuery query;

    // Получаем ID проекта по его названию
    query.prepare("SELECT student_id_card FROM students WHERE studentname = :studentName");
    query.bindValue(":studentName", studentName);
    if (!query.exec()) {
        qDebug() << "Ошибка при получении ProjectID: " << query.lastError().text();
        QSqlDatabase::database().rollback();
        return;
    }

    int studentID = -1;
    if (query.next()) {
        studentID = query.value(0).toInt();
    }

    if (studentID == -1) {
        qDebug() << "Проект не найден";
        QSqlDatabase::database().rollback();
        return;
    }
    // Удаляем записи из таблицы ProjectStudents
    query.prepare("DELETE FROM ProjectStudents WHERE student_id_card = :ProjectID");
    query.bindValue(":ProjectID", studentID);
    if (!query.exec()) {
        qDebug() << "Ошибка при удалении из ProjectStudents: " << query.lastError().text();
        QSqlDatabase::database().rollback();
        return;
    }
    // Удаляем запись из таблицы Projects
    query.prepare("DELETE FROM students WHERE student_id_card = :studentID");
    query.bindValue(":studentID", studentID);
    if (!query.exec()) {
        qDebug() << "Ошибка при удалении проекта: " << query.lastError().text();
        QSqlDatabase::database().rollback();
        return;
    }

    QSqlDatabase::database().commit();
    if (!query.exec(R"(SELECT studentname, email FROM students;)")) {
        std::cerr << "Ошибка выполнения запроса: " << query.lastError().text().toStdString() << std::endl;
    }
    else {
        std::cout << "Запрос выполнен успешно" << std::endl;

        // Создание модели для TableView
        QStandardItemModel *model = new QStandardItemModel();
        model->setColumnCount(query.record().count());

        // Установка заголовков столбцов
        QStringList headers;
        headers << "Студент" << "Почта студента";
        model->setHorizontalHeaderLabels(headers);

        // Заполнение модели данными из запроса
        int row = 0;
        while (query.next()) {
            model->insertRow(row);
            for (int col = 0; col < query.record().count(); ++col) {
                QModelIndex index = model->index(row, col, QModelIndex());
                model->setData(index, query.value(col).toString());
            }
            ++row;
        }

        // Установка модели в TableView
        ui->tableView->setModel(model);

}}
void list_of_students::editRecord(QModelIndex index) {
    if (!index.isValid())
        return;

    // Получаем модель из QTableView
    QAbstractItemModel *model = ui->tableView->model();

    // Получаем данные из выделенной строки
    QString studentName = model->data(model->index(index.row(), 0)).toString();
    QString email = model->data(model->index(index.row(), 1)).toString();
    QString user_password = model->data(model->index(index.row(), 2)).toString();



    auto *change_t = new change_student();  // Создать окно логина
    change_t->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    change_t->setData(studentName, email, user_password); // Передача данных в форму
    change_t->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}
void list_of_students::customMenuRequested(QPoint pos) {
    QModelIndex index = ui->tableView->indexAt(pos);
    if (!index.isValid())
        return;

    QMenu *menu = new QMenu(this);
    menu->setStyleSheet(
            "QMenu {"
            "    border: 2px solid #6D55FF; /* Фиолетовая рамка */"
            "    background-color: #FFFFFF; /* Белый фон */"
            "    color: #000000; /* Чёрный текст */"
            "}"
            "QMenu::item:selected {"
            "    background-color: #6D55FF; /* Фиолетовый фон при наведении */"
            "    color: #FFFFFF; /* Белый текст */"
            "}"
        );
    menu->addAction(new QAction("Удалить", this));
    menu->addAction(new QAction("Изменить", this));

    connect(menu->actions()[1], &QAction::triggered, [this, index]() { editRecord(index); });
    connect(menu->actions()[0], &QAction::triggered, [this, index]() { deleteRecord(index); });
    menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
}
void list_of_students::on_pushButton_clicked()
{
    auto *add = new add_stud();
    add->setAttribute(Qt::WA_DeleteOnClose);
    add->show();
    this->close();
}

