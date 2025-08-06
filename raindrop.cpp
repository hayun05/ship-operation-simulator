#include "raindrop.h"

RainDrop::RainDrop(int x, int y)
    : x(x), y(y) {
    speed = QRandomGenerator::global()->bounded(5, 15);
}

void RainDrop::fall(int maxWidth, int maxHeight) {
    y += speed;
    if (y > maxHeight) {
        y = QRandomGenerator::global()->bounded(-10, 0);
        x = QRandomGenerator::global()->bounded(maxWidth);
        speed = QRandomGenerator::global()->bounded(5, 15);
    }
}

void RainDrop::draw(QPainter &painter) const {
    painter.drawLine(x, y, x, y + 10);
}
