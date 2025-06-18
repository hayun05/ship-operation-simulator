#include "displaypage.h"
#include <QVBoxLayout>
#include <QLabel>

DisplayPage::DisplayPage(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Display Page", this);
    display3d = new Display3D(this); // 3D 위젯 생성

    layout->addWidget(label);
    layout->addWidget(display3d);  // 3D 위젯 추가
    layout->addStretch();

    setLayout(layout);
}

Display3D* DisplayPage::get3DWidget() {
    return display3d;
}
