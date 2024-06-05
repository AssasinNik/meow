#include "change_theme.h"
#include "ui_change_theme.h"
#include "add_theme.h"
#include "ui_add_theme.h"
#include "list_of_themes.h"
#include "greeting.h"
#include "pgreeting.h"
#include "sgreeting.h"
#include <QFileDialog>
#include "role_type.h"
#include "iostream"

change_theme::change_theme(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_theme)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QIntValidator *validator = new QIntValidator(0, 400000, this);
    ui->lineEdit_6->setValidator(validator);
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(400000);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSlider_valueChanged(int)));
    connect(ui->lineEdit_6, SIGNAL(textChanged(const QString &)), this, SLOT(on_lineEdit_6_textChanged(const QString &)));
}

change_theme::~change_theme()
{
    delete ui;
}

void change_theme::on_pushButton_2_clicked()
{
    close();
}


void change_theme::on_pushButton_3_clicked()
{
    showMinimized();
}


void change_theme::on_pushButton_4_clicked()
{
      auto *list = new List_of_themes();  // Создать окно логина
      list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
      list->show();
      this->close(); // Скрываем текущее окно вместо закрытия
}



void change_theme::on_lineEdit_6_textChanged(const QString &text)
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
void change_theme::setData(const QString &projectName, const QString &funding, const QString &startDate, const QString &endDate, const QString &information, const QString &stage, const QString &students, const QString &leaders) {
    ui->lineEdit_2->setText(projectName);
    ui->lineEdit_6->setText(funding);
    ui->lineEdit_3->setText(information);
    ui->lineEdit_2->setReadOnly(true); // Устанавливаем атрибут readOnly
    ui->lineEdit_2->setStyleSheet("background-color: #dddddd;"
                                       "border-radius: 15px;"
                                       "font: 14pt \"Karla\";"
                                       "padding-left: 10px;"
                                       "padding-right: 10px;"
                                       "border: 2px solid #6D55FF;");
    // Добавьте установку данных для остальных виджетов, если они есть
    QSqlQuery stageQuery("SELECT DISTINCT stagename, stageid FROM stages");
      QStringList stageNames;
      QMap<int, QString> stageMap; // отображение для связи stageid с stagename
      while (stageQuery.next()) {
          QString stagename = stageQuery.value(0).toString();
          int stageid = stageQuery.value(1).toInt();
          stageNames << stagename;
          stageMap.insert(stageid, stagename);
      }

      // Заполняем comboBox полученными stagename
      ui->comboBox->addItems(stageNames);

      ui->comboBox->setCurrentText(stage);

}
void change_theme::on_horizontalSlider_valueChanged(int value)
{
    ui->lineEdit_6->setText(QString::number(value));
}

void change_theme::on_pushButton_clicked()
{
    IS_TABLE=false;
    // Получаем новые значения описания, финансирования и стадии
        QString newDescription = ui->lineEdit_3->text();
        QString newFunding = ui->lineEdit_6->text();
        QString newStage = ui->comboBox->currentText();

        // Выполняем запрос на обновление данных в таблице projects
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE projects SET information = :description, funding = :funding, stageid = (SELECT stageid FROM stages WHERE stagename = :stage) WHERE projectname = :projectName");
        updateQuery.bindValue(":description", newDescription);
        updateQuery.bindValue(":funding", newFunding);
        updateQuery.bindValue(":stage", newStage);
        updateQuery.bindValue(":projectName", ui->lineEdit_2->text()); // Предполагается, что имя проекта хранится в lineEdit_2
        if (updateQuery.exec()) {
            qDebug() << "Данные успешно обновлены";
            QMessageBox::information(this, "Успех", "Данные успешно обновлены");
        } else {
            qDebug() << "Ошибка обновления данных:" << updateQuery.lastError().text();
            QMessageBox::critical(this, "Ошибка", "Ошибка при обновлении данных: " + updateQuery.lastError().text());
        }
    auto *list = new List_of_themes();  // Создать окно логина
    list->setAttribute(Qt::WA_DeleteOnClose); // Установить атрибут для автоматического удаления при закрытии
    list->show();
    this->close(); // Скрываем текущее окно вместо закрытия
}
