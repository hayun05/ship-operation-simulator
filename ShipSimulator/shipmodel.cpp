/*#include "ShipModel.h"

bool ShipModel::load(const QString& path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
        return false;

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        if(line.startsWith("v "))
        {
            QStringList parts = line.split(" ", Qt::SkipEmptyParts);
            vertices.append({parts[1].toFloat(), parts[2].toFloat(), parts[3].toFloat()});
        }
        else if(line.startsWith("f "))
        {
            QStringList parts = line.split(" ", Qt::SkipEmptyParts);
            QVector<int> face;
            for(int i=1;i<parts.size();i++)
            {
                QString vert = parts[i].split("/")[0];
                face.append(vert.toInt()-1); // OBJ는 1-based
            }
            faces.append(face);
        }
    }
    return true;
}

void ShipModel::draw()
{
    glBegin(GL_TRIANGLES);
    for(auto &f: faces)
    {
        for(int idx: f)
        {
            Vertex v = vertices[idx];
            glVertex3f(v.x, v.y, v.z);
        }
    }
    glEnd();
}
*/


#include "ShipModel.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <GL/gl.h>

bool ShipModel::load(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open OBJ file:" << filename;
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.startsWith("v ")) {
            QStringList parts = line.split(' ', Qt::SkipEmptyParts);
            if (parts.size() >= 4) {
                Vertex v;
                v.pos.setX(parts[1].toFloat());
                v.pos.setY(parts[2].toFloat());
                v.pos.setZ(parts[3].toFloat());
                m_vertices.append(v);
            }
        } else if (line.startsWith("f ")) {
            QStringList parts = line.split(' ', Qt::SkipEmptyParts);
            if (parts.size() >= 4) {
                Face f;
                f.v1 = parts[1].split('/')[0].toInt() - 1;
                f.v2 = parts[2].split('/')[0].toInt() - 1;
                f.v3 = parts[3].split('/')[0].toInt() - 1;
                m_faces.append(f);
            }
        }
    }

    return true;
}

void ShipModel::draw() const
{
    glBegin(GL_TRIANGLES);
    for (const Face& f : m_faces) {
        glVertex3f(m_vertices[f.v1].pos.x(), m_vertices[f.v1].pos.y(), m_vertices[f.v1].pos.z());
        glVertex3f(m_vertices[f.v2].pos.x(), m_vertices[f.v2].pos.y(), m_vertices[f.v2].pos.z());
        glVertex3f(m_vertices[f.v3].pos.x(), m_vertices[f.v3].pos.y(), m_vertices[f.v3].pos.z());
    }
    glEnd();
}
