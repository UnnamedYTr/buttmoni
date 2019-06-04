#ifndef BUTTONMONITOR_H
#define BUTTONMONITOR_H

#include "ui_buttonmonitor.h"

const int Pr1 = 17;
const int Pr2 = 27;
const int Pr3 = 22;
const int T_UPDATE = 100;

class ButtonMonitor : public QWidget, private Ui::ButtonMonitor
{
    Q_OBJECT

public:
    explicit ButtonMonitor(QWidget *parent = 0);
private slots:
    void updateValue();
};

#endif
