#include "PhotoLabel.h"

PhotoLabel::PhotoLabel(QWidget *parent) : QLabel(parent)
{
    setCursor(Qt::PointingHandCursor); // Установка курсора руки для интерактивности
}

void PhotoLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked(); // Испускание сигнала при клике левой кнопкой мыши
    }
}
