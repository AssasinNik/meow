#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QWidget>

namespace Ui {
class CustomButton;
}

class CustomButton : public QWidget
{
    Q_OBJECT

public:
    explicit CustomButton(QWidget *parent = nullptr);
    ~CustomButton();

private:
    Ui::CustomButton *ui;
};

#endif // CUSTOMBUTTON_H
