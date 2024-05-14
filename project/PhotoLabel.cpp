#include "PhotoLabel.h"

PhotoLabel::PhotoLabel(QWidget *parent) : QLabel(parent)
{
}

void PhotoLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    }
}
