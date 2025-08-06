#include "displaypage.h"
#include "display2d.h"
#include <QVBoxLayout>
#include <QLabel>

DisplayPage::DisplayPage(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Display Page", this);
    display2d = new Display2D(this); // 3D 위젯 생성

    layout->addWidget(label);
    layout->addWidget(display2d);  // 3D 위젯 추가
    layout->addStretch();

    setLayout(layout);
}

Display2D* DisplayPage::get2DWidget() {
    return display2d;
}
