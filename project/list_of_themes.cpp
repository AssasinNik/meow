#include "list_of_themes.h"
#include "ui_list_of_themes.h"
#include "greeting.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QStandardItemModel>
#include <QTableView>
#include <iostream>

List_of_themes::List_of_themes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::List_of_themes)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Выполнение запроса
    QSqlQuery query;
    if (!query.exec(R"(
        SELECT
            p.ProjectID,
            p.ProjectName,
            p.Funding,
            p.Start_date,
            p.End_date,
            p.Information,
            s.StageName AS Stage,
            string_agg(DISTINCT st.StudentName, ', ' ORDER BY st.StudentName) AS Students,
            string_agg(DISTINCT l.LeaderName, ', ' ORDER BY l.LeaderName) AS Leaders
        FROM
            Projects p
        JOIN
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
            p.ProjectID;
    )")) {
        std::cerr << "Ошибка выполнения запроса: " << query.lastError().text().toStdString() << std::endl;
    }
    else {
        std::cout << "Запрос выполнен успешно" << std::endl;

        // Создание модели для TableView
        QStandardItemModel *model = new QStandardItemModel();
        model->setColumnCount(query.record().count());

        // Установка заголовков столбцов
        QStringList headers;
        headers << "ID проекта" << "Название проекта" << "Финансирование" << "Дата начала" << "Дата окончания" << "Информация" << "Стадия" << "Студенты" << "Руководители";
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
    auto *greeting = new Greeting();
    greeting->setAttribute(Qt::WA_DeleteOnClose);
    greeting->show();
    this->close();
}
