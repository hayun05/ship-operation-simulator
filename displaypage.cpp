#include "displaypage.h"
#include <QVBoxLayout>
#include <QLabel>

DisplayPage::DisplayPage(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Display Page", this);
    layout->addWidget(label);
    layout->addStretch();

    setLayout(layout);
}
