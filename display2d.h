#ifndef DISPLAY2D_H
#define DISPLAY2D_H

#include <QWidget>
#include <QTimer>
#include <QList>
#include "raindrop.h"

class Display2D : public QWidget {
    Q_OBJECT

public:
    explicit Display2D(QWidget *parent = nullptr);

public slots:
    void updateSpeed(int speed);
    void updateRain(bool rain);
    void updateBoat(int index);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int speed = 0;
    bool isRaining = false;
    int boatType = 0;

    QList<RainDrop*> rainDrops;
    QTimer *rainTimer;

    void createRain();
    void updateRainfall();
};

#endif // DISPLAY2D_H
