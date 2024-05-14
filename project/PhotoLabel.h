#ifndef PHOTOLABEL_H
#define PHOTOLABEL_H

#include <QLabel>
#include <QMouseEvent>

class PhotoLabel : public QLabel
{
    Q_OBJECT

public:
    explicit PhotoLabel(QWidget *parent = nullptr);

signals:
    void clicked(); // Объявление сигнала

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // PHOTOLABEL_H
