#include "settingpage.h"

SettingPage::SettingPage(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // === Boat Settings ===
    boatGroup = new QGroupBox("Boat Setting", this);
    boatLayout = new QVBoxLayout(boatGroup);

    // Boat Type
    BLayout1 = new QHBoxLayout();
    Blb1 = new QLabel("배 종류 선택", this);
    boatSelect = new QComboBox(this);
    boatSelect->addItems({"고속정", "어선", "잠수함"});
    BLayout1->addWidget(Blb1);
    BLayout1->addWidget(boatSelect);
    BLayout1->addStretch();
    boatLayout->addLayout(BLayout1);

    // Boat Size
    BLayout2 = new QHBoxLayout();
    Blb2 = new QLabel("배 크기 조정", this);
    boatSize = new QSpinBox(this);
    BLayout2->addWidget(Blb2);
    BLayout2->addWidget(boatSize);
    BLayout2->addStretch();
    boatLayout->addLayout(BLayout2);

    // Boat Speed
    BLayout3 = new QHBoxLayout();
    Blb3 = new QLabel("배 속도 조정", this);
    boatSpeed = new QSlider(Qt::Horizontal, this);
    boatSpeed->setRange(1, 100);
    boatSpeed->setValue(20);
    BLayout3->addWidget(Blb3);
    BLayout3->addWidget(boatSpeed);
    BLayout3->addStretch();
    boatLayout->addLayout(BLayout3);

    boatGroup->setLayout(boatLayout);


    // === Preferences ===
    prefGroup = new QGroupBox("Preferences", this);
    prefLayout = new QVBoxLayout(prefGroup);

    // Rain Checkbox
    PLayout1 = new QHBoxLayout();
    rain = new QCheckBox("비 켜기", this);
    PLayout1->addWidget(rain);
    PLayout1->addStretch();
    prefLayout->addLayout(PLayout1);

    // Wind Slider
    PLayout2 = new QHBoxLayout();
    Plb1 = new QLabel("바람 세기", this);
    wind = new QSlider(Qt::Horizontal, this);
    wind->setRange(0, 100);
    wind->setValue(0);
    PLayout2->addWidget(Plb1);
    PLayout2->addWidget(wind);
    PLayout2->addStretch();
    prefLayout->addLayout(PLayout2);

    prefGroup->setLayout(prefLayout);

    // === Connections ===
    connect(rain, &QCheckBox::toggled, this, &SettingPage::handleRain);
    connect(boatSpeed, &QSlider::valueChanged, this, &SettingPage::handleSpeed);
    connect(boatSelect, &QComboBox::currentIndexChanged, this, &SettingPage::handleBoatType);
    connect(boatSize, QOverload<int>::of(&QSpinBox::valueChanged), this, &SettingPage::handleSize);
    connect(wind, &QSlider::valueChanged, this, &SettingPage::handleWind);

    // Add to main layout
    mainLayout->addWidget(boatGroup);
    mainLayout->addWidget(prefGroup);
    setLayout(mainLayout);
}


// === 슬롯 구현 ===
void SettingPage::handleRain(bool checked) {
    emit rainToggled(checked);
}

void SettingPage::handleSpeed(int speed) {
    emit speedValueChanged(speed);
}

void SettingPage::handleBoatType(int index) {
    emit boatTypeChanged(index);
}

void SettingPage::handleSize(int size) {
    emit sizeValueChanged(size);
}

void SettingPage::handleWind(int value) {
    emit windValueChanged(value);
}
