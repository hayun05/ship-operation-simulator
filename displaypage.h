#ifndef DISPLAYPAGE_H
#define DISPLAYPAGE_H

class Display2D; // 전방 선언

#include <QWidget>

class DisplayPage : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayPage(QWidget *parent = nullptr);
    Display2D *get2DWidget();  // 외부에서 접근용

private:
    Display2D *display2d;
};

#endif // DISPLAYPAGE_H
