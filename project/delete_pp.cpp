#include "delete_pp.h"
#include "ui_delete_pp.h"
#include "list_of_themes.h"
#include <QStandardItemModel>
#include <QMessageBox>
#include <QHeaderView>
#include <iostream>

delete_pp::delete_pp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::delete_pp)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
void delete_pp::setData(const QString &projectName){

    ui->label_2->setText(projectName);

    QSqlQuery query;

    // Находим id проекта по его названию
    int projectId = -1;
    QSqlQuery projectIdQuery;
    projectIdQuery.prepare("SELECT projectid FROM projects WHERE projectname = :projectname");
    projectIdQuery.bindValue(":projectname", projectName);
    if (!projectIdQuery.exec() || !projectIdQuery.next()) {
        qDebug() << "Ошибка при получении id проекта:" << projectIdQuery.lastError().text();
        return;
    } else {
        projectId = projectIdQuery.value(0).toInt();
    }

    if (!query.exec(QString("SELECT leadername, email FROM leaders WHERE leaderid IN (SELECT leaderid FROM projectleaders WHERE projectid = %1)").arg(projectId))) {
        std::cerr << "Ошибка выполнения запроса: " << query.lastError().text().toStdString() << std::endl;
    }
    else {
        std::cout << "Запрос выполнен успешно" << std::endl;

        // Создание модели для TableView
        QStandardItemModel *model = new QStandardItemModel();
        model->setColumnCount(query.record().count());

        // Установка заголовков столбцов
        QStringList headers;
        headers << "Преподаватель" << "Почта преподавателя";
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
delete_pp::~delete_pp()
{
    delete ui;
}

void delete_pp::on_pushButton_3_clicked()
{
    showMinimized();
}


void delete_pp::on_pushButton_2_clicked()
{
    close();
}


void delete_pp::on_pushButton_4_clicked()
{
    auto *list = new List_of_themes();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}


void delete_pp::on_pushButton_clicked()
{
    QString newProjectName = ui->label_2->text();

    int projectId = -1;
    QSqlQuery projectIdQuery;
    projectIdQuery.prepare("SELECT projectid FROM projects WHERE projectname = :projectname");
    projectIdQuery.bindValue(":projectname", newProjectName);
    if (!projectIdQuery.exec() || !projectIdQuery.next()) {
        qDebug() << "Ошибка при получении id проекта:" << projectIdQuery.lastError().text();
        return;
    } else {
        projectId = projectIdQuery.value(0).toInt();
    }

    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    int row = selected.first().row();
    QModelIndex index = ui->tableView->model()->index(row, 0);
    if (!index.isValid())
        return;

    // Получаем модель из QTableView
    QAbstractItemModel *model = ui->tableView->model();

    // Получаем данные из выделенной строки
    QString leaderName = model->data(model->index(index.row(), 0)).toString();
    qDebug()<<leaderName;

    int leaderId = -1;
    QSqlQuery leaderIdQuery;
    leaderIdQuery.prepare("SELECT leaderid FROM leaders WHERE leadername = :leadername");
    leaderIdQuery.bindValue(":leadername", leaderName);
    if (!leaderIdQuery.exec() || !leaderIdQuery.next()) {
        qDebug() << "Ошибка при получении id имени:" << projectIdQuery.lastError().text();
        return;
    } else {
        leaderId = leaderIdQuery.value(0).toInt();
    }

    QSqlQuery insertQuery;
    insertQuery.prepare("DELETE FROM ProjectLeaders WHERE ProjectID = :projectID AND LeaderID = :leaderID");
    insertQuery.bindValue(":projectID", projectId);
    insertQuery.bindValue(":leaderID", leaderId);
    if (insertQuery.exec()) {
        qDebug() << "Данные успешно обновлены";
        QMessageBox::information(this, "Успех", "Данные успешно обновлены");
    } else {
        qDebug() << "Ошибка обновления данных:" << insertQuery.lastError().text();
        QMessageBox::critical(this, "Ошибка", "Ошибка при обновлении данных: " + insertQuery.lastError().text());
    }
    //удаление
    auto *list = new List_of_themes();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}

