#include "buttonmonitor.h"
#include <wiringPi.h>
#include <QTimer>

ButtonMonitor::ButtonMonitor(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    wiringPiSetupGpio();
    pinMode(Pr1, INPUT);
    pinMode(Pr2, INPUT);
    pinMode(Pr3, INPUT);
    updateValue();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));
    timer->start(T_UPDATE);
}

void ButtonMonitor::updateValue()
{
    if(!(digitalRead(Pr1)))
    {butt1->setText("Button 1 High");
    butt1->setStyleSheet("color:green;background-color:white;font-size:18pt;");}
    else
    {butt1->setText("Button 1 Low");
    butt1->setStyleSheet("color:red;background-color:black;font-size:18pt;");}

    if(!(digitalRead(Pr2)))
    {butt2->setText("Button 2 High");
    butt2->setStyleSheet("color:green;background-color:white;font-size:18pt;");}
    else
    {butt2->setText("Button 2 Low");
    butt2->setStyleSheet("color:red;background-color:black;font-size:18pt;");}

    if(!(digitalRead(Pr3)))
    {butt3->setText("Button 3 High");
    butt3->setStyleSheet("color:green;background-color:white;font-size:18pt;");}
    else
    {butt3->setText("Button 3 Low");
    butt3->setStyleSheet("color:red;background-color:black;font-size:18pt;");}
}
