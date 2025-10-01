/*#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QElapsedTimer>
#include <QVector3D>
#include "ship.h"
#include "ShipModel.h"

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLWidget(QWidget* parent = nullptr);
    ~OpenGLWidget();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    float waveHeight(float x, float z, float time);
    void waveNormal(float x, float z, float time, float& nx, float& nz);

    //void drawCube(float size);
    void drawWater(float size, int grid, float time);

private:
    QElapsedTimer m_timer;
    qint64 m_lastTime;

    Ship m_ship;
    ShipModel m_shipModel;
    QVector3D m_shipPos = {0,0,0};

    float m_cameraAngleX;
    float m_cameraAngleY;
    float m_cameraDistance;
};
*/

#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QElapsedTimer>
#include <QVector3D>
#include "ShipModel.h"

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLWidget(QWidget* parent = nullptr);
    ~OpenGLWidget();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    float waveHeight(float x, float z, float time);
    void waveNormal(float x, float z, float time, float& nx, float& nz);
    void drawWater(float size, int grid, float time);

private:
    QElapsedTimer m_timer;
    qint64 m_lastTime;

    ShipModel m_shipModel;      // 배 OBJ 모델
    QVector3D m_shipPos = {0,0,0};

    float m_cameraAngleX;
    float m_cameraAngleY;
    float m_cameraDistance;
};
