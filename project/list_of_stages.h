#ifndef LIST_OF_STAGES_H
#define LIST_OF_STAGES_H

#include <QWidget>
#include <QMouseEvent>
#include <QtCore>
#include <QtSql>
#include <QTimer>
#include <QScrollBar>

namespace Ui {
class list_of_stages;
}

class list_of_stages : public QWidget
{
    Q_OBJECT

public:
    explicit list_of_stages(QWidget *parent = nullptr);
    ~list_of_stages();
protected:
    void mousePressEvent(QMouseEvent *event) override {
        // Запомнить начальную позицию при нажатии на кнопку мыши
        if (event->button() == Qt::LeftButton) {
            m_dragging = true;
            m_dragPosition = event->globalPos() - frameGeometry().topLeft();
            event->accept();
        }
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        // Перемещать окно при зажатой левой кнопке мыши
        if (event->buttons() & Qt::LeftButton && m_dragging) {
            move(event->globalPos() - m_dragPosition);
            event->accept();
        }
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        // Остановить перемещение окна при отпускании кнопки мыши
        if (event->button() == Qt::LeftButton) {
            m_dragging = false;
            event->accept();
        }
    }
private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
public slots:
    void customMenuRequested(QPoint pos);
    void editRecord(QModelIndex index);
    void deleteRecord(QModelIndex index);
private:
    Ui::list_of_stages *ui;
    bool m_dragging = false;
    QPoint m_dragPosition;
};

#endif // LIST_OF_STAGES_H
