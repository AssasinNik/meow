#include "list_of_themes.h"
#include "ui_list_of_themes.h"
#include "greeting.h"
#include "sgreeting.h"
#include "pgreeting.h"
#include "add_theme.h"
#include <QSqlDatabase>
#include <QMenu>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QStandardItemModel>
#include "role_type.h"
#include "student_project.h"
#include "delete_pp.h"
#include "delete_sp.h"
#include "professor_project.h"
#include "change_theme.h"
#include <QTableView>
#include <iostream>

List_of_themes::List_of_themes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::List_of_themes)
{

    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    if(IS_STUDENT==true){
        ui->pushButton->close();
    }


    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Выполнение запроса
    QSqlQuery query;
    if (!query.exec(R"(SELECT
                    p.ProjectName,
                    p.Funding,
                    p.Start_date,
                    p.End_date,
                    p.Information,
                    COALESCE(s.StageName, 'N/A') AS Stage,  -- Замена null на 'N/A' для StageName
                    STRING_AGG(DISTINCT st.StudentName, ', ' ORDER BY st.StudentName) AS Students,
                    STRING_AGG(DISTINCT l.LeaderName, ', ' ORDER BY l.LeaderName) AS Leaders
                FROM
                    Projects p
                LEFT JOIN
                    Stages s ON p.StageID = s.StageID
                LEFT JOIN
                    ProjectStudents ps ON p.ProjectID = ps.ProjectID
                LEFT JOIN
                    Students st ON ps.Student_ID_Card = st.Student_ID_Card
                LEFT JOIN
                    ProjectLeaders pl ON p.ProjectID = pl.ProjectID
                LEFT JOIN
                    Leaders l ON pl.LeaderID = l.LeaderID
                GROUP BY
                    p.ProjectID, p.ProjectName, p.Funding, p.Start_date, p.End_date, p.Information, s.StageName
                ORDER BY
                    p.ProjectID;)")) {
        std::cerr << "Ошибка выполнения запроса: " << query.lastError().text().toStdString() << std::endl;
    }
    else {
        std::cout << "Запрос выполнен успешно" << std::endl;

        // Создание модели для TableView
        QStandardItemModel *model = new QStandardItemModel();
        model->setColumnCount(query.record().count());

        // Установка заголовков столбцов
        QStringList headers;
        headers << "Название проекта" << "Финансирование" << "Дата начала" << "Дата окончания" << "Информация" << "Стадия" << "Студенты" << "Руководители";
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
    if(!IS_STUDENT){
        connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)),
                this, SLOT(customMenuRequested(QPoint)));
    }
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
void List_of_themes::loadData() {
    QSqlQuery query;
    if (!query.exec(R"(SELECT
                    p.ProjectName,
                    p.Funding,
                    p.Start_date,
                    p.End_date,
                    p.Information,
                    COALESCE(s.StageName, 'N/A') AS Stage,  -- Замена null на 'N/A' для StageName
                    STRING_AGG(DISTINCT st.StudentName, ', ' ORDER BY st.StudentName) AS Students,
                    STRING_AGG(DISTINCT l.LeaderName, ', ' ORDER BY l.LeaderName) AS Leaders
                FROM
                    Projects p
                LEFT JOIN
                    Stages s ON p.StageID = s.StageID
                LEFT JOIN
                    ProjectStudents ps ON p.ProjectID = ps.ProjectID
                LEFT JOIN
                    Students st ON ps.Student_ID_Card = st.Student_ID_Card
                LEFT JOIN
                    ProjectLeaders pl ON p.ProjectID = pl.ProjectID
                LEFT JOIN
                    Leaders l ON pl.LeaderID = l.LeaderID
                GROUP BY
                    p.ProjectID, p.ProjectName, p.Funding, p.Start_date, p.End_date, p.Information, s.StageName
                ORDER BY
                    p.ProjectID;)")) {
        std::cerr << "Ошибка выполнения запроса: " << query.lastError().text().toStdString() << std::endl;
    }
    else {
        QStandardItemModel *model = new QStandardItemModel();
        model->setColumnCount(query.record().count());
        QStringList headers{"Название проекта", "Финансирование", "Дата начала", "Дата окончания", "Информация", "Стадия", "Студенты", "Руководители"};
        model->setHorizontalHeaderLabels(headers);

        int row = 0;
        while (query.next()) {
            model->insertRow(row);
            for (int col = 0; col < query.record().count(); ++col) {
                QModelIndex index = model->index(row, col, QModelIndex());
                model->setData(index, query.value(col).toString());
            }
            ++row;
        }
        ui->tableView->setModel(model);
    }
}
void List_of_themes::addStudent(QModelIndex index) {
    // Логика для добавления студента

    if (!index.isValid())
        return;

    // Получаем модель из QTableView
    QAbstractItemModel *model = ui->tableView->model();

    // Получаем данные из выделенной строки
    QString projectName = model->data(model->index(index.row(), 0)).toString();

    // Создаем форму редактирования и передаем туда данные
    auto *sp = new student_project();
    sp->setAttribute(Qt::WA_DeleteOnClose);
    sp->setData(projectName); // Передача данных в форму
    sp->show();
    this->close(); // Скрываем текущее окно вместо закрытия

}
void List_of_themes::addProfessor(QModelIndex index) {
    // Логика для добавления преподавателя

    if (!index.isValid())
        return;

    // Получаем модель из QTableView
    QAbstractItemModel *model = ui->tableView->model();

    // Получаем данные из выделенной строки
    QString projectName = model->data(model->index(index.row(), 0)).toString();


    // Создаем форму редактирования и передаем туда данные
    auto *change_t = new professor_project();
    change_t->setAttribute(Qt::WA_DeleteOnClose);
    change_t->setData(projectName); // Передача данных в форму
    change_t->show();
    this->close(); // Скрываем текущее окно вместо закрытия

}
void List_of_themes::deleteStudent(QModelIndex index) {
    // Логика для добавления студента

    if (!index.isValid())
        return;

    // Получаем модель из QTableView
    QAbstractItemModel *model = ui->tableView->model();

    // Получаем данные из выделенной строки
    QString projectName = model->data(model->index(index.row(), 0)).toString();

    // Создаем форму редактирования и передаем туда данные
    auto *sp = new delete_sp();
    sp->setAttribute(Qt::WA_DeleteOnClose);
    sp->setData(projectName); // Передача данных в форму
    sp->show();
    this->close(); // Скрываем текущее окно вместо закрытия

}
void List_of_themes::deleteProfessor(QModelIndex index) {
    // Логика для добавления преподавателя

    if (!index.isValid())
        return;

    // Получаем модель из QTableView
    QAbstractItemModel *model = ui->tableView->model();

    // Получаем данные из выделенной строки
    QString projectName = model->data(model->index(index.row(), 0)).toString();


    // Создаем форму редактирования и передаем туда данные
    auto *change_t = new delete_pp();
    change_t->setAttribute(Qt::WA_DeleteOnClose);
    change_t->setData(projectName); // Передача данных в форму
    change_t->show();
    this->close(); // Скрываем текущее окно вместо закрытия

}
void List_of_themes::deleteRecord(QModelIndex index) {
    if (!index.isValid())
        return;

    int row = index.row();
    QString projectName = ui->tableView->model()->index(row, 0).data().toString(); // Предположим, что имя проекта находится во второй колонке

    qDebug() << "Project Name: " << projectName;

    QSqlDatabase::database().transaction();
    QSqlQuery query;

    // Получаем ID проекта по его названию
    query.prepare("SELECT ProjectID FROM Projects WHERE ProjectName = :ProjectName");
    query.bindValue(":ProjectName", projectName);
    if (!query.exec()) {
        qDebug() << "Ошибка при получении ProjectID: " << query.lastError().text();
        QSqlDatabase::database().rollback();
        return;
    }

    int projectID = -1;
    if (query.next()) {
        projectID = query.value(0).toInt();
    }

    if (projectID == -1) {
        qDebug() << "Проект не найден";
        QSqlDatabase::database().rollback();
        return;
    }

    // Удаляем записи из таблицы ProjectLeaders
    query.prepare("DELETE FROM ProjectLeaders WHERE ProjectID = :ProjectID");
    query.bindValue(":ProjectID", projectID);
    if (!query.exec()) {
        qDebug() << "Ошибка при удалении из ProjectLeaders: " << query.lastError().text();
        QSqlDatabase::database().rollback();
        return;
    }

    // Удаляем записи из таблицы ProjectStudents
    query.prepare("DELETE FROM ProjectStudents WHERE ProjectID = :ProjectID");
    query.bindValue(":ProjectID", projectID);
    if (!query.exec()) {
        qDebug() << "Ошибка при удалении из ProjectStudents: " << query.lastError().text();
        QSqlDatabase::database().rollback();
        return;
    }

    // Удаляем запись из таблицы Projects
    query.prepare("DELETE FROM Projects WHERE ProjectID = :ProjectID");
    query.bindValue(":ProjectID", projectID);
    if (!query.exec()) {
        qDebug() << "Ошибка при удалении проекта: " << query.lastError().text();
        QSqlDatabase::database().rollback();
        return;
    }

    QSqlDatabase::database().commit();
    loadData(); // Загрузить данные после успешного удаления
}
void List_of_themes::editRecord(QModelIndex index) {
    if (!index.isValid())
        return;

    // Получаем модель из QTableView
    QAbstractItemModel *model = ui->tableView->model();

    // Получаем данные из выделенной строки
    QString projectName = model->data(model->index(index.row(), 0)).toString();
    QString funding = model->data(model->index(index.row(), 1)).toString();
    QString startDate = model->data(model->index(index.row(), 2)).toString();
    QString endDate = model->data(model->index(index.row(), 3)).toString();
    QString information = model->data(model->index(index.row(), 4)).toString();
    QString stage = model->data(model->index(index.row(), 5)).toString();
    QString students = model->data(model->index(index.row(), 6)).toString();
    QString leaders = model->data(model->index(index.row(), 7)).toString();

    // Создаем форму редактирования и передаем туда данные
    auto *change_t = new change_theme();
    change_t->setAttribute(Qt::WA_DeleteOnClose);
    change_t->setData(projectName, funding, startDate, endDate, information, stage, students, leaders); // Передача данных в форму
    change_t->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}
void List_of_themes::customMenuRequested(QPoint pos) {
    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    int row = selected.first().row();
    QModelIndex index = ui->tableView->model()->index(row, 0);

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
    if(!IS_PROFESSOR){
        QAction *deleteAction = new QAction("Удалить", this);
            QAction *editAction = new QAction("Изменить", this);
            QAction *addStudentAction = new QAction("Добавить студента к проекту", this);
            QAction *addProfessorAction = new QAction("Добавить преподавателя к проекту", this);
            QAction *deleteProfessorAction = new QAction("Удалить преподавателя из проекта", this);
            QAction *deleteStudentAction = new QAction("Удалить студента из проекта", this);

            menu->addAction(deleteAction);
            menu->addAction(editAction);
            menu->addAction(addStudentAction);
            menu->addAction(addProfessorAction);
            menu->addAction(deleteProfessorAction);
            menu->addAction(deleteStudentAction);

            connect(deleteAction, &QAction::triggered, [this, index]() {
                deleteRecord(index);
            });
            connect(editAction, &QAction::triggered, [this, index]() {
                editRecord(index);
            });
            connect(addStudentAction, &QAction::triggered, [this, index]() {
                addStudent(index);
            });
            connect(addProfessorAction, &QAction::triggered, [this, index]() {
                addProfessor(index);
            });
            connect(deleteProfessorAction, &QAction::triggered, [this, index]() {
                deleteProfessor(index);
            });
            connect(deleteStudentAction, &QAction::triggered, [this, index]() {
                deleteStudent(index);
            });
    }
    else{
        QAction *deleteAction = new QAction("Удалить", this);
            QAction *editAction = new QAction("Изменить", this);

            menu->addAction(deleteAction);
            menu->addAction(editAction);

            connect(deleteAction, &QAction::triggered, [this, index]() {
                deleteRecord(index);
            });
            connect(editAction, &QAction::triggered, [this, index]() {
                editRecord(index);
            });
    }



        menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
}

void List_of_themes::on_pushButton_clicked()
{
    IS_TABLE = true;
    auto *add_t = new Add_theme();  // Создать окно логина
    add_t->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    add_t->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

