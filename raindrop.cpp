#include "raindrop.h"
#include <QRandomGenerator>

RainDrop::RainDrop(Qt3DCore::QEntity *parent)
    : Qt3DCore::QEntity(parent)
{
    auto *mesh = new Qt3DExtras::QCylinderMesh();
    mesh->setRadius(0.02f);
    mesh->setLength(0.4f);
    mesh->setRings(2);
    mesh->setSlices(8);

    auto *material = new Qt3DExtras::QPhongMaterial();
    material->setDiffuse(QColor(200, 200, 255));

    // 정수 범위를 사용하여 랜덤값 생성 후 float으로 변환
    float x = static_cast<float>(QRandomGenerator::global()->bounded(-10000, 10000)) / 1000.0f;
    float z = static_cast<float>(QRandomGenerator::global()->bounded(-10000, 10000)) / 1000.0f;
    y = static_cast<float>(QRandomGenerator::global()->bounded(5000, 15000)) / 1000.0f;

    transform = new Qt3DCore::QTransform();
    transform->setTranslation(QVector3D(x, y, z));

    addComponent(mesh);
    addComponent(material);
    addComponent(transform);
}

void RainDrop::fall() {
    y -= 0.2f;
    if (y < -1.0f)
        reset();
    transform->setTranslation(QVector3D(transform->translation().x(), y, transform->translation().z()));
}

void RainDrop::reset() {
    // y를 다시 랜덤값으로 초기화
    y = static_cast<float>(QRandomGenerator::global()->bounded(5000, 15000)) / 1000.0f;
}
