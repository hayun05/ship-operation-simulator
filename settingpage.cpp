#include "settingpage.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>

SettingPage::SettingPage(QWidget *parent)
    : QWidget(parent)
{
    // 메인 레이아웃
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Boat Setting 그룹
    QGroupBox *boatGroup = new QGroupBox(this);
    boatGroup -> setTitle("Boat Setting")
    QVBoxLayout *boatLayout = new QVBoxLayout(boatGroup);
    
    // TODO: 여기에 보트 관련 설정 위젯 추가
    boatGroup->setLayout(boatLayout);

    // Preferences 그룹
    QGroupBox *prefGroup = new QGroupBox(this);
    prefGroup -> setTitle("Preferences")
    QVBoxLayout *prefLayout = new QVBoxLayout(prefGroup);
    // TODO: 여기에 환경 설정 위젯 추가
    prefGroup->setLayout(prefLayout);

    // 그룹을 메인 레이아웃에 추가
    mainLayout->addWidget(boatGroup);
    mainLayout->addWidget(prefGroup);
    setLayout(mainLayout);
}
