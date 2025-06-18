#ifndef DISPLAY3D_H
#define DISPLAY3D_H

// display3d.h
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class Display3D : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT
public:
    explicit Display3D(QWidget *parent = nullptr);

public slots:
    void updateSpeed(int speed);
    void updateRain(bool rain);
    void updateBoat(int index);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

private:
    int speed = 0;
    bool isRaining = false;
    int boatType = 0;
};
