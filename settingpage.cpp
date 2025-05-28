#include "settingpage.h"

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




    // Preferences 그룹
    prefGroup = new QGroupBox(this);
    prefGroup -> setTitle("Preferences");
    prefLayout = new QVBoxLayout(prefGroup);


    //Preferences' first layout : 비 상태 점검
    PLayout1 = new QHBoxLayout();

    rain = new QCheckBox("비 켜기", this);

    connect(rain, &QCheckBox::toggled, this, &SettingPage::checkedRain);


    PLayout1->addWidget(rain);
    PLayout1->addStretch();

    prefLayout->addLayout(PLayout1);


    prefGroup->setLayout(prefLayout);



    // 그룹을 메인 레이아웃에 추가
    mainLayout->addWidget(boatGroup);
    mainLayout->addWidget(prefGroup);
    setLayout(mainLayout);
}

void SettingPage::checkedRain(bool check){

}
