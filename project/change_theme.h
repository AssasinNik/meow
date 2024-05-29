#ifndef CHANGE_THEME_H
#define CHANGE_THEME_H

#include <QWidget>

namespace Ui {
class change_theme;
}

class change_theme : public QWidget
{
    Q_OBJECT

public:
    explicit change_theme(QWidget *parent = nullptr);
    ~change_theme();

private:
    Ui::change_theme *ui;
};

#endif // CHANGE_THEME_H
