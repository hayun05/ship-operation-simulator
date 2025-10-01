#pragma once

#ifndef SHIP_H
#define SHIP_H


#include <QVector3D>


class Ship {
public:
    Ship();


    void update(float deltaTime);


    void setThrottle(float t);
    void setRudder(float r);


    QVector3D position() const { return m_position; }
    float heading() const { return m_heading; }


    void setWaveOffset(float y, float pitch, float roll);
    float pitch() const { return m_pitch; }
    float roll() const { return m_roll; }


private:
    QVector3D m_position;
    float m_heading;
    float m_speed;
    float m_throttle;
    float m_rudder;


    // 파도에 따른 자세
    float m_waveOffsetY;
    float m_pitch;
    float m_roll;
};


#endif // SHIP_H
