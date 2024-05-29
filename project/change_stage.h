#ifndef CHANGE_STAGE_H
#define CHANGE_STAGE_H

#include <QWidget>

namespace Ui {
class change_stage;
}

class change_stage : public QWidget
{
    Q_OBJECT

public:
    explicit change_stage(QWidget *parent = nullptr);
    ~change_stage();

private:
    Ui::change_stage *ui;
};

#endif // CHANGE_STAGE_H
