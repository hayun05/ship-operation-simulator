#include "settingpage.h"
#include "controller.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QComboBox>
#include <QSpacerItem>
#include <QSpinBox>
#include <QCheckBox>
#include <QMessageBox>

SettingPage::SettingPage(QWidget *parent)
    : QWidget(parent)
{
    // 메인 레이아웃
    QVBoxLayout *mainLayout = new QVBoxLayout(this);


    // Boat Setting 그룹
    boatGroup = new QGroupBox(this);
    boatGroup -> setTitle("Boat Setting");


    boatLayout = new QVBoxLayout(boatGroup);



    //boatSetting first layout : 배 종류 선택
    BLayout1 = new QHBoxLayout();


    Blb1= new QLabel("배 종류 선택", this);
    boatSelcet = new QComboBox(this);

    boatSelcet->addItems({"고속정", "어선", "잠수함"});

    BLayout1->addWidget(Blb1);
    BLayout1->addWidget(boatSelcet);
    BLayout1->addStretch(); // 수평 스페이서 추가

    boatLayout->addLayout(BLayout1);


    //boatSetting second layout : 배 크기 조정
    BLayout2 = new QHBoxLayout();

    Blb2 = new QLabel("배 크기 조정", this);
    boatSize = new QSpinBox(this);

    BLayout2->addWidget(Blb2);
    BLayout2->addWidget(boatSize);
    BLayout2->addStretch(); // 수평 스페이서 추가

    boatLayout ->addLayout(BLayout2);

    //boatSetting Ending
    boatGroup->setLayout(boatLayout);


    //boatSetting second layout : 배 속도 조정
    BLayout3 = new QHBoxLayout();

    Blb3 = new QLabel("배 속도 조정", this);

    boatSpeed = new QSlider(Qt::Horizontal, this);

    boatSpeed->setMaximum(100);
    boatSpeed->setMinimum(1);
    boatSpeed->setValue(20);

    BLayout3->addWidget(Blb3);
    BLayout3->addWidget(boatSpeed);
    BLayout3->addStretch(); // 수평 스페이서 추가

    boatLayout ->addLayout(BLayout3);


    //boatSetting Ending
    boatGroup->setLayout(boatLayout);




    // Preferences 그룹
    prefGroup = new QGroupBox(this);
    prefGroup -> setTitle("Preferences");
    prefLayout = new QVBoxLayout(prefGroup);


    //Preferences' first layout : 비 상태 점검
    PLayout1 = new QHBoxLayout();

    rain = new QCheckBox("비 켜기", this);

    PLayout1->addWidget(rain);
    PLayout1->addStretch();

    prefLayout->addLayout(PLayout1);

    PLayout1 = new QHBoxLayout();

    rain = new QCheckBox("비 켜기", this);



    //Preferences' second layout : 비 상태 점검
    PLayout2 = new QHBoxLayout();
    Plb1 = new QLabel("바람 세기");

    wind = new QSlider(Qt::Horizontal ,this);

    wind->setMinimum(0);
    wind->setMaximum(100);
    wind->setValue(0);

    PLayout2->addWidget(Plb1);
    PLayout2->addWidget(wind);
    PLayout2->addStretch();

    prefLayout->addLayout(PLayout2);

    prefGroup->setLayout(prefLayout);


    connect(rain, &QCheckBox::toggled, this, &SettingPage::checkedRain);
    connect(boatSpeed, &QSlider::valueChanged, this, &SettingPage::speedChanged);
    connect(boatSelcet, &QComboBox::currentIndexChanged, this, &SettingPage::selectBoat);
    connect(boatSize, &QSpinBox::valueChanged, this, &SettingPage::sizeChecked);
    connect(wind, &QSlider::valueChanged, this, &SettingPage::windChecked);

    // 그룹을 메인 레이아웃에 추가
    mainLayout->addWidget(boatGroup);
    mainLayout->addWidget(prefGroup);
    setLayout(mainLayout);


    
}

void SettingPage::checkedRain(bool check){
    emit onRain(check);
}

void SettingPage::speedChanged(int speed){
    emit onSpeedChanged(speed);
}

void SettingPage::selectBoat(int index){
    emit onSelectBoat(index);
}

void SettingPage::sizeChecked(int size){
    emit onSizeChecked(size);
}

void SettingPage::windChecked(int wind){
    emit onWind(wind);
}
