/*#include "openglwidget.h"
#include <QtMath>
#include <QTimer>
#include <QMatrix4x4>


OpenGLWidget::OpenGLWidget(QWidget* parent)
    : QOpenGLWidget(parent), m_cameraAngleX(45), m_cameraAngleY(0), m_cameraDistance(30.0f)
{
    m_timer.start();
    m_lastTime = m_timer.elapsed();
    setFocusPolicy(Qt::StrongFocus);

    // 배 OBJ 로드
    m_shipModel.load(":/ship.obj"); // 리소스로 넣거나 절대경로

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this](){ update(); });
    timer->start(16); // 약 60fps
}

OpenGLWidget::~OpenGLWidget() {}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.2f, 0.4f, 0.7f, 1.0f);
}

void OpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    QMatrix4x4 projection;
    projection.perspective(60.0f, float(w)/float(h), 0.1f, 1000.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(projection.constData());
    glMatrixMode(GL_MODELVIEW);
}

float OpenGLWidget::waveHeight(float x, float z, float time)
{
    float h = 0.0f;
    struct Wave { float A, kx, kz, speed; };
    Wave waves[3] = {
        {0.5f, 0.2f, 0.0f, 1.0f},
        {0.3f, 0.0f, 0.15f, 1.2f},
        {0.2f, 0.1f, 0.1f, 0.7f}
    };

    for(int i=0;i<3;i++){
        float phase = waves[i].kx * x + waves[i].kz * z - waves[i].speed * time;
        h += waves[i].A * qSin(phase);
    }
    return h;
}

void OpenGLWidget::waveNormal(float x, float z, float time, float& nx, float& nz)
{
    float dx = 0.01f;
    float dz = 0.01f;
    float hL = waveHeight(x - dx, z, time);
    float hR = waveHeight(x + dx, z, time);
    float hD = waveHeight(x, z - dz, time);
    float hU = waveHeight(x, z + dz, time);

    nx = (hR - hL) / (2*dx);
    nz = (hU - hD) / (2*dz);
}

void OpenGLWidget::drawWater(float size, int grid, float time)
{
    float half = size/2.0f;
    float step = size / grid;

    QVector3D lightDir(0.0f, 1.0f, 1.0f);
    lightDir.normalize();

    for(int i=0;i<grid;i++)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for(int j=0;j<=grid;j++)
        {
            for(int k=0; k<=1; k++)
            {
                float x = -half + (i+k)*step;
                float z = -half + j*step;
                float y = waveHeight(x, z, time);

                float nx, nz;
                waveNormal(x, z, time, nx, nz);
                QVector3D normal(-nx, 1.0f, -nz);
                normal.normalize();

                float t = (y + 1.0f) * 0.5f;
                float intensity = QVector3D::dotProduct(normal, lightDir);
                intensity = qBound(0.0f, intensity, 1.0f);
                intensity = qPow(intensity, 0.5f);

                glColor3f(0.0f, (0.3f+0.5f*t)*intensity, (0.5f+0.5f*t)*intensity);
                glVertex3f(x, y, z);
            }
        }
        glEnd();
    }

    // 물결 경계 강조
    glColor3f(0.0f, 0.3f, 0.5f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    for(int i=0;i<grid;i++)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for(int j=0;j<=grid;j++)
        {
            for(int k=0; k<=1; k++)
            {
                float x = -half + (i+k)*step;
                float z = -half + j*step;
                float y = waveHeight(x, z, time);
                glVertex3f(x, y, z);
            }
        }
        glEnd();
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void OpenGLWidget::paintGL()
{
    qint64 now = m_timer.elapsed();
    float time = now / 1000.0f;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // 카메라
    glTranslatef(0.0f, -2.0f, -m_cameraDistance);
    glRotatef(m_cameraAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(m_cameraAngleY, 0.0f, 1.0f, 0.0f);

    // 물결
    drawWater(80.0f, 80, time);

    // 배 위치
    float waveY = waveHeight(m_shipPos.x(), m_shipPos.z(), time);
    float nx, nz;
    waveNormal(m_shipPos.x(), m_shipPos.z(), time, nx, nz);
    float pitch = -qRadiansToDegrees(qAtan(nx));
    float roll  = qRadiansToDegrees(qAtan(nz));

    // 그림자
    glPushMatrix();
    glTranslatef(m_shipPos.x(), 0.01f, m_shipPos.z());
    glColor4f(0.0f, 0.0f, 0.0f, 0.3f);
    glScalef(1.5f, 0.01f, 1.5f);
    m_shipModel.draw(); // 그림자용 간단 버전
    glPopMatrix();

    // 배 본체
    glPushMatrix();
    glTranslatef(m_shipPos.x(), waveY, m_shipPos.z());
    glRotatef(pitch, 1, 0, 0);
    glRotatef(roll, 0, 0, 1);
    glScalef(0.5f, 0.5f, 0.5f); // 모델 스케일
    glColor3f(1.0f, 1.0f, 1.0f); // 배 색
    m_shipModel.draw();
    glPopMatrix();
}*/

#include "OpenGLWidget.h"
#include <QtMath>
#include <QTimer>
#include <QMatrix4x4>
#include <GL/gl.h>

OpenGLWidget::OpenGLWidget(QWidget* parent)
    : QOpenGLWidget(parent), m_cameraAngleX(45), m_cameraAngleY(0), m_cameraDistance(30.0f)
{
    m_timer.start();
    m_lastTime = m_timer.elapsed();
    setFocusPolicy(Qt::StrongFocus);

    m_shipModel.load(":/ship.obj"); // 프로젝트 내 리소스 또는 절대경로

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this](){ update(); });
    timer->start(16); // 약 60fps
}

OpenGLWidget::~OpenGLWidget() {}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.2f, 0.4f, 0.7f, 1.0f);
}

void OpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    QMatrix4x4 projection;
    projection.perspective(60.0f, float(w)/float(h), 0.1f, 1000.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(projection.constData());
    glMatrixMode(GL_MODELVIEW);
}

float OpenGLWidget::waveHeight(float x, float z, float time)
{
    float h = 0.0f;
    struct Wave { float A, kx, kz, speed; };
    Wave waves[3] = {
        {0.5f, 0.2f, 0.0f, 1.0f},
        {0.3f, 0.0f, 0.15f, 1.2f},
        {0.2f, 0.1f, 0.1f, 0.7f}
    };
    for(int i=0;i<3;i++){
        float phase = waves[i].kx * x + waves[i].kz * z - waves[i].speed * time;
        h += waves[i].A * qSin(phase);
    }
    return h;
}

void OpenGLWidget::waveNormal(float x, float z, float time, float& nx, float& nz)
{
    float dx = 0.01f;
    float dz = 0.01f;
    float hL = waveHeight(x - dx, z, time);
    float hR = waveHeight(x + dx, z, time);
    float hD = waveHeight(x, z - dz, time);
    float hU = waveHeight(x, z + dz, time);

    nx = (hR - hL) / (2*dx);
    nz = (hU - hD) / (2*dz);
}

void OpenGLWidget::drawWater(float size, int grid, float time)
{
    float half = size/2.0f;
    float step = size / grid;
    QVector3D lightDir(0.0f, 1.0f, 1.0f);
    lightDir.normalize();

    for(int i=0;i<grid;i++)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for(int j=0;j<=grid;j++)
        {
            for(int k=0;k<=1;k++)
            {
                float x = -half + (i+k)*step;
                float z = -half + j*step;
                float y = waveHeight(x, z, time);

                float nx, nz;
                waveNormal(x, z, time, nx, nz);
                QVector3D normal(-nx, 1.0f, -nz);
                normal.normalize();

                float t = (y + 1.0f) * 0.5f;
                float intensity = QVector3D::dotProduct(normal, lightDir);
                intensity = qBound(0.0f, intensity, 1.0f);
                intensity = qPow(intensity, 0.5f);

                glColor3f(0.0f, (0.3f+0.5f*t)*intensity, (0.5f+0.5f*t)*intensity);
                glVertex3f(x, y, z);
            }
        }
        glEnd();
    }
}

void OpenGLWidget::paintGL()
{
    qint64 now = m_timer.elapsed();
    float time = now / 1000.0f;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // 카메라
    glTranslatef(0.0f, -2.0f, -m_cameraDistance);
    glRotatef(m_cameraAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(m_cameraAngleY, 0.0f, 1.0f, 0.0f);

    // 물
    drawWater(80.0f, 80, time);

    // 배
    glPushMatrix();
    glTranslatef(m_shipPos.x(), waveHeight(m_shipPos.x(), m_shipPos.z(), time), m_shipPos.z());
    m_shipModel.draw();
    glPopMatrix();
}

