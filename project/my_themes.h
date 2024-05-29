#ifndef MY_THEMES_H
#define MY_THEMES_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class my_themes;
}

class my_themes : public QWidget
{
    Q_OBJECT

public:
    explicit my_themes(QWidget *parent = nullptr);
    ~my_themes();
protected:
    void mousePressEvent(QMouseEvent *event) override {
        // Р вЂ”Р В°Р С—Р С•Р СР Р…Р С‘РЎвЂљРЎРЉ Р Р…Р В°РЎвЂЎР В°Р В»РЎРЉР Р…РЎС“РЎР‹ Р С—Р С•Р В·Р С‘РЎвЂ Р С‘РЎР‹ Р С—РЎР‚Р С‘ Р Р…Р В°Р В¶Р В°РЎвЂљР С‘Р С‘ Р Р…Р В° Р С”Р Р…Р С•Р С—Р С”РЎС“ Р СРЎвЂ№РЎв‚¬Р С‘
        if (event->button() == Qt::LeftButton) {
            m_dragging = true;
            m_dragPosition = event->globalPos() - frameGeometry().topLeft();
            event->accept();
        }
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        // Р СџР ВµРЎР‚Р ВµР СР ВµРЎвЂ°Р В°РЎвЂљРЎРЉ Р С•Р С”Р Р…Р С• Р С—РЎР‚Р С‘ Р В·Р В°Р В¶Р В°РЎвЂљР С•Р в„– Р В»Р ВµР Р†Р С•Р в„– Р С”Р Р…Р С•Р С—Р С”Р Вµ Р СРЎвЂ№РЎв‚¬Р С‘
        if (event->buttons() & Qt::LeftButton && m_dragging) {
            move(event->globalPos() - m_dragPosition);
            event->accept();
        }
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        // Р С›РЎРѓРЎвЂљР В°Р Р…Р С•Р Р†Р С‘РЎвЂљРЎРЉ Р С—Р ВµРЎР‚Р ВµР СР ВµРЎвЂ°Р ВµР Р…Р С‘Р Вµ Р С•Р С”Р Р…Р В° Р С—РЎР‚Р С‘ Р С•РЎвЂљР С—РЎС“РЎРѓР С”Р В°Р Р…Р С‘Р С‘ Р С”Р Р…Р С•Р С—Р С”Р С‘ Р СРЎвЂ№РЎв‚¬Р С‘
        if (event->button() == Qt::LeftButton) {
            m_dragging = false;
            event->accept();
        }
    }
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::my_themes *ui;
    bool m_dragging = false;
    QPoint m_dragPosition;
};

#endif // MY_THEMES_H
