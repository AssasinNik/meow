#ifndef CHANGE_STUDENT_H
#define CHANGE_STUDENT_H

#include <QWidget>

namespace Ui {
class change_student;
}

class change_student : public QWidget
{
    Q_OBJECT

public:
    explicit change_student(QWidget *parent = nullptr);
    ~change_student();

private:
    Ui::change_student *ui;
};

#endif // CHANGE_STUDENT_H
