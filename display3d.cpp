#include "display3d.h"
#include <QDebug>

Display3D::Display3D(QWidget *parent) : QOpenGLWidget(parent) {}

void Display3D::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0, 0.3, 0.6, 1); // 바다색
}

void Display3D::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void Display3D::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 여기에 배, 파도, 비 등 OpenGL로 렌더링
    // 예: 속도에 따라 움직이는 배
}

void Display3D::updateSpeed(int s) {
    speed = s;
    update(); // repaint
}

void Display3D::updateRain(bool r) {
    isRaining = r;
    update();
}

void Display3D::updateBoat(int index) {
    boatType = index;
    update();
}
