#include "controller.h"
#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent) {}

void Controller::rainChecked(bool checked) {
    if (checked)
        qDebug() << "Checkbox is checked!";
    else
        qDebug() << "Checkbox is unchecked!";
}
