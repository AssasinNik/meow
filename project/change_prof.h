#ifndef CHANGE_PROF_H
#define CHANGE_PROF_H

#include <QWidget>

namespace Ui {
class change_prof;
}

class change_prof : public QWidget
{
    Q_OBJECT

public:
    explicit change_prof(QWidget *parent = nullptr);
    ~change_prof();

private:
    Ui::change_prof *ui;
};

#endif // CHANGE_PROF_H
