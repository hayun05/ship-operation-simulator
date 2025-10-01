#include "ship.h"
#include <QtMath>


Ship::Ship() : m_position(0, 0, 0), m_heading(0), m_speed(0), m_throttle(0), m_rudder(0), m_waveOffsetY(0), m_pitch(0), m_roll(0) {}


void Ship::update(float deltaTime) {
    float accel = m_throttle * 2.0f;
    m_speed += accel * deltaTime;
    m_speed *= 0.99f;


    m_heading += m_rudder * m_speed * 0.1f * deltaTime;


    m_position.setX(m_position.x() + qCos(qDegreesToRadians(m_heading)) * m_speed * deltaTime);
    m_position.setZ(m_position.z() + qSin(qDegreesToRadians(m_heading)) * m_speed * deltaTime);


    // y 좌표는 파도 offset으로 결정
    m_position.setY(m_waveOffsetY);
}


void Ship::setThrottle(float t) {
    m_throttle = qBound(-1.0f, t, 1.0f);
}


void Ship::setRudder(float r) {
    m_rudder = qBound(-1.0f, r, 1.0f);
}


void Ship::setWaveOffset(float y, float pitch, float roll) {
    m_waveOffsetY = y;
    m_pitch = pitch;
    m_roll = roll;
}
