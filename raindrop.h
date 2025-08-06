#ifndef RAINDROP_H
#define RAINDROP_H

#include <QPainter>
#include <QRandomGenerator>

class RainDrop {
public:
    RainDrop(int x, int y);
    void fall(int maxWidth, int maxHeight);
    void draw(QPainter &painter) const;

private:
    int x, y;
    int speed;
};

#endif // RAINDROP_H
