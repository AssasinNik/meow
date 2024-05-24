#ifndef SGREETING_H
#define SGREETING_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class sgreeting;
}

class sgreeting : public QWidget
{
    Q_OBJECT

public:
    explicit sgreeting(QWidget *parent = nullptr);
    ~sgreeting();
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
    Ui::sgreeting *ui;
    bool m_dragging = false;
    QPoint m_dragPosition;
};

#endif // SGREETING_H
