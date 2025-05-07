#include "settingpage.h"
#include <QVBoxLayout>
#include <QLabel>

SettingPage::SettingPage(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("This is the Setting Page", this);
    layout->addWidget(label);
    setLayout(layout);
}
