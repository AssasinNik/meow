#ifndef PROFIL_H
#define PROFIL_H

#include <QWidget>
#include <QMouseEvent>
#include <QPixmap>
#include <QLabel>
#include "PhotoLabel.h"

namespace Ui {
class profil;
}

class profil : public QWidget
{
    Q_OBJECT

public:
    explicit profil(QWidget *parent = nullptr);
    ~profil();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void changePhoto();

private:
    Ui::profil *ui;
    PhotoLabel *photoLabel;
    QLabel *overlayLabel;
    QLabel *textLabel;
    bool m_dragging = false;
    QPoint m_dragPosition;

    void updatePhotoLabel(const QPixmap &pixmap);
};

#endif // PROFIL_H
