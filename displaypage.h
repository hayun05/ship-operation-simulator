#ifndef DISPLAYPAGE_H
#define DISPLAYPAGE_H

class Display3D; // 전방 선언

#include <QWidget>

class DisplayPage : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayPage(QWidget *parent = nullptr);
    Display3D *get3DWidget();  // 외부에서 접근용

private:
    Display3D *display3d;
};

#endif // DISPLAYPAGE_H
