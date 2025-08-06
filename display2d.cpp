// display3d.cpp - 2D 버전
#include "display2d.h"
#include <QPainter>
#include <QRandomGenerator>

Display2D::Display2D(QWidget *parent) : QWidget(parent) {
    setMinimumSize(400, 300);
    rainTimer = new QTimer(this);
    connect(rainTimer, &QTimer::timeout, this, &Display2D::updateRainfall);
    rainTimer->start(100);
}

void Display2D::updateSpeed(int newSpeed) {
    speed = newSpeed;
    update();
}

void Display2D::updateRain(bool rain) {
    isRaining = rain;
    if (isRaining) {
        createRain();
        rainTimer->start();
    } else {
        rainDrops.clear();
        rainTimer->stop();
    }
    update();
}

void Display2D::updateBoat(int index) {
    boatType = index;
    update();
}

void Display2D::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 배 그리기
    painter.setBrush(Qt::blue);
    QRect boatRect(width()/2 - 40, height() - 60, 80, 30);
    painter.drawRect(boatRect);

    // 비 그리기
    if (isRaining) {
        painter.setPen(Qt::gray);
        for (RainDrop* drop : rainDrops)
            drop->draw(painter);
    }
}

void Display2D::createRain() {
    rainDrops.clear();
    for (int i = 0; i < 50; ++i) {
        int x = QRandomGenerator::global()->bounded(width());
        int y = QRandomGenerator::global()->bounded(height());
        rainDrops.append(new RainDrop(x, y));
    }
}
void Display2D::updateRainfall() {
    for (RainDrop* drop : rainDrops)
        drop->fall(width(), height());
    update();
}
