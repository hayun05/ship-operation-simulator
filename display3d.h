#ifndef DISPLAY3D_H
#define DISPLAY3D_H

#include <QWidget>
#include <QTimer>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DCore/QEntity>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QCuboidMesh>

#include "raindrop.h"

class Display3D : public QWidget {
    Q_OBJECT

public:
    explicit Display3D(QWidget *parent = nullptr);

public slots:
    void updateSpeed(int speed);
    void updateRain(bool rain);
    void updateBoat(int index);

private:
    Qt3DExtras::Qt3DWindow *view;
    QWidget *container;
    Qt3DCore::QEntity *rootEntity;
    Qt3DCore::QEntity *boatEntity;

    int speed = 0;
    bool isRaining = false;
    int boatType = 0;

    QList<RainDrop*> rainDrops;
    QTimer *rainTimer;

    void createScene();
    void createRain();
    void updateRainfall();
};

#endif // DISPLAY3D_H
