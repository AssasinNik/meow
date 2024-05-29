#ifndef CHANGE_STUDENT_H
#define CHANGE_STUDENT_H

#include <QWidget>
#include <QWidget>
#include <QtWidgets>
#include <QtSql>
#include <QMouseEvent>
#include <QRegExpValidator>

namespace Ui {
class change_student;
}

class change_student : public QWidget
{
    Q_OBJECT

public:
    explicit change_student(QWidget *parent = nullptr);
    ~change_student();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
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
private:
    Ui::change_student *ui;
    bool m_dragging = false;
    QPoint m_dragPosition;

};

#endif // CHANGE_STUDENT_H
