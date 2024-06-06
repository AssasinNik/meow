#ifndef DELETE_SP_H
#define DELETE_SP_H

#include <QWidget>
#include <QMouseEvent>
#include <QtCore>
#include <QtSql>
#include <QTimer>
#include <QScrollBar>

namespace Ui {
class delete_sp;
}

class delete_sp : public QWidget
{
    Q_OBJECT

public:
    explicit delete_sp(QWidget *parent = nullptr);
    ~delete_sp();
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
public slots:
    void setData(const QString &projectName);
private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::delete_sp *ui;
    bool m_dragging = false;
    QPoint m_dragPosition;
};

#endif // DELETE_SP_H
