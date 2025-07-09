#include "display3d.h"
#include <Qt3DRender/QCamera>

Display3D::Display3D(QWidget *parent) : QWidget(parent) {
    view = new Qt3DExtras::Qt3DWindow();
    container = QWidget::createWindowContainer(view);
    container->setMinimumSize(400, 300);
    container->setFocusPolicy(Qt::StrongFocus);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(container);
    setLayout(layout);

    rootEntity = new Qt3DCore::QEntity();
    view->setRootEntity(rootEntity);

    // Camera
    Qt3DRender::QCamera *camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.0f, 4.0f / 3.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 5, 20));
    camera->setViewCenter(QVector3D(0, 0, 0));

    // Camera control
    auto *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setCamera(camera);

    createScene();
}

void Display3D::createScene() {
    // 기본 박스 배
    boatEntity = new Qt3DCore::QEntity(rootEntity);

    auto *mesh = new Qt3DExtras::QCuboidMesh();
    auto *material = new Qt3DExtras::QPhongMaterial();
    material->setDiffuse(Qt::red);

    boatEntity->addComponent(mesh);
    boatEntity->addComponent(material);
}

void Display3D::createRain() {
    for (int i = 0; i < 100; ++i) {
        RainDrop *drop = new RainDrop(rootEntity);
        rainDrops.append(drop);
    }

    rainTimer = new QTimer(this);
    connect(rainTimer, &QTimer::timeout, this, &Display3D::updateRainfall);
    rainTimer->start(30);
}

void Display3D::updateRainfall() {
    for (RainDrop *drop : rainDrops) {
        drop->fall();
    }
}

void Display3D::updateSpeed(int s) {
    speed = s;
    // 추후 이동 처리 가능
}

void Display3D::updateRain(bool r) {
    isRaining = r;
    if (isRaining) {
        if (rainDrops.isEmpty())
            createRain();
        rainTimer->start();
    } else {
        rainTimer->stop();
        for (RainDrop *drop : rainDrops)
            drop->setEnabled(false);
    }
}

void Display3D::updateBoat(int index) {
    boatType = index;
    // 추후 보트 변경
}
