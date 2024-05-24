#ifndef PGREETING_H
#define PGREETING_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class pgreeting;
}

class pgreeting : public QWidget
{
    Q_OBJECT

public:
    explicit pgreeting(QWidget *parent = nullptr);
    ~pgreeting();
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
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::pgreeting *ui;
    bool m_dragging = false;
    QPoint m_dragPosition;
};

#endif // PGREETING_H
