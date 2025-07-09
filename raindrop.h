#ifndef RAINDROP_H
#define RAINDROP_H

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QPhongMaterial>

class RainDrop : public Qt3DCore::QEntity {
public:
    explicit RainDrop(Qt3DCore::QEntity *parent = nullptr);
    void fall();
    void reset();

private:
    Qt3DCore::QTransform *transform;
    float y;
};

#endif // RAINDROP_H
