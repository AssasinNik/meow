#include "list_of_stages.h"
#include "ui_list_of_stages.h"
#include "add_theme.h"
#include "add_stage.h"
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
#include "change_stage.h"
#include <iostream>

list_of_stages::list_of_stages(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list_of_stages)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    if(!IS_STUDENT || !IS_PROFESSOR){
        connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)),
                this, SLOT(customMenuRequested(QPoint)));
    }
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive); // Распределение столбцов
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(205); // Задайте начальную ширину

    // Выполнение запроса
    QSqlQuery query;
    if (!query.exec(R"(SELECT stagename, stagedescription, recommendlength, difficulty FROM stages)")) {
        std::cerr << "Ошибка выполнения запроса: " << query.lastError().text().toStdString() << std::endl;
    }
    else {
        std::cout << "Запрос выполнен успешно" << std::endl;

        // Создание модели для TableView
        QStandardItemModel *model = new QStandardItemModel();
        model->setColumnCount(query.record().count());

        // Установка заголовков столбцов
        QStringList headers;
        headers << "Название стадии" << "Описание" << "Продолжительность(реком.)" << "Сложность";
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
    }
}

list_of_stages::~list_of_stages()
{
    delete ui;
}

void list_of_stages::on_pushButton_4_clicked()
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


void list_of_stages::on_pushButton_3_clicked()
{
    showMinimized();
}


void list_of_stages::on_pushButton_2_clicked()
{
    close();
}
void list_of_stages::deleteRecord(QModelIndex index) {
    if (!index.isValid())
            return;

        int row = index.row();
        QString stageName = ui->tableView->model()->index(row, 0).data().toString(); // Получаем имя стадии

        QSqlDatabase::database().transaction();
        QSqlQuery query;

        // Получаем ID стадии по её названию
        query.prepare("SELECT stageid FROM stages WHERE stagename = :stageName");
        query.bindValue(":stageName", stageName);
        if (!query.exec()) {
            qDebug() << "Ошибка при получении stageID: " << query.lastError().text();
            QSqlDatabase::database().rollback();
            return;
        }

        int stageID = -1;
        if (query.next()) {
            stageID = query.value(0).toInt();
        }

        if (stageID == -1) {
            qDebug() << "Стадия не найдена";
            QSqlDatabase::database().rollback();
            return;
        }

        // Обновляем StageID на NULL в таблице Projects для соответствующих записей
        query.prepare("UPDATE Projects SET StageID = NULL WHERE StageID = :StageID;");
        query.bindValue(":StageID", stageID);
        if (!query.exec()) {
            qDebug() << "Ошибка при обновлении Projects: " << query.lastError().text();
            QSqlDatabase::database().rollback();
            return;
        }

        // Удаляем стадию из таблицы Stages
        query.prepare("DELETE FROM stages WHERE stageid = :stageID;");
        query.bindValue(":stageID", stageID);
        if (!query.exec()) {
            qDebug() << "Ошибка при удалении стадии: " << query.lastError().text();
            QSqlDatabase::database().rollback();
            return;
        }

        QSqlDatabase::database().commit();
    if (!query.exec(R"(SELECT stagename, stagedescription, recommendlength, difficulty FROM stages)")) {
        std::cerr << "Ошибка выполнения запроса: " << query.lastError().text().toStdString() << std::endl;
    }
    else {
        std::cout << "Запрос выполнен успешно" << std::endl;

        // Создание модели для TableView
        QStandardItemModel *model = new QStandardItemModel();
        model->setColumnCount(query.record().count());

        // Установка заголовков столбцов
        QStringList headers;
        headers << "Название стадии" << "Описание" << "Продолжительность(реком.)" << "Сложность";
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
    }

}
void list_of_stages::editRecord(QModelIndex index) {
    // Создаем форму редактирования и передаем туда данные
    if (!index.isValid())
        return;

    // Получаем модель из QTableView
    QAbstractItemModel *model = ui->tableView->model();

    // Получаем данные из выделенной строки
    QString stageName = model->data(model->index(index.row(), 0)).toString();
    QString stageDesc = model->data(model->index(index.row(), 1)).toString();
    QString recommendLen = model->data(model->index(index.row(), 2)).toString();
    QString difficulty = model->data(model->index(index.row(), 3)).toString();

    auto *change_t = new change_stage();  // Создать окно логина
    change_t->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    change_t->setData(stageName, stageDesc, recommendLen, difficulty);
    change_t->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}
void list_of_stages::customMenuRequested(QPoint pos) {
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

void list_of_stages::on_pushButton_clicked()
{
    auto *add = new add_stage();
    add->setAttribute(Qt::WA_DeleteOnClose);
    add->show();
    this->close();
}

