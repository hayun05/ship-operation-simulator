#include "controller.h"
#include "settingpage.h"

#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent) {}


void Controller::onSpeedChanged(int speed)
{
    qDebug() << "Speed:"<< speed << '\n';
}

void Controller::onRain(bool checked) {

    if (checked)
        qDebug() << "Checkbox is checked!" << '\n';
    else
        qDebug() << "Checkbox is unchecked!" << '\n';
}

void Controller::onSelectBoat(int index){
    qDebug() << "Select Number:" << index << '\n';
}

void Controller::onSizeChecked(int size){
    qDebug() << "boat Size : " <<size << '\n';
}

void Controller::onWind(int wind){
    qDebug() << "WIND" << wind << '\n';
}
