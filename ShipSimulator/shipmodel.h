/*#ifndef SHIPMODEL_H
#define SHIPMODEL_H

#pragma once

#include <QVector>
#include <QVector3D>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QOpenGLFunctions>

struct Vertex { float x,y,z; };

class ShipModel : protected QOpenGLFunctions
{
public:
    ShipModel() {}
    bool load(const QString& path);
    void draw();

private:
    QVector<Vertex> vertices;
    QVector<QVector<int>> faces;
};

#endif // SHIPMODEL_H
*/

#ifndef SHIPMODEL_H
#define SHIPMODEL_H

#include <QString>
#include <QVector>
#include <QVector3D>

struct Vertex {
    QVector3D pos;
};

struct Face {
    int v1, v2, v3;
};

class ShipModel {
public:
    ShipModel() {}
    bool load(const QString& filename);
    void draw() const;

private:
    QVector<Vertex> m_vertices;
    QVector<Face> m_faces;
};

#endif // SHIPMODEL_H
