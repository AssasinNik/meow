#ifndef ADD_THEME_H
#define ADD_THEME_H

#include <QWidget>
#include <QtWidgets>
#include <QtSql>
#include <QMouseEvent>
#include <QRegExpValidator>

namespace Ui {
class Add_theme;
}

class Add_theme : public QWidget
{
    Q_OBJECT

public:
    explicit Add_theme(QWidget *parent = nullptr);
    ~Add_theme();
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

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_lineEdit_6_textChanged(const QString &text);

private:
    Ui::Add_theme *ui;
    bool m_dragging = false;
    QPoint m_dragPosition;
};

#endif // ADD_THEME_H
