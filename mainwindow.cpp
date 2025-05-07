#include "mainwindow.h"
#include "settingpage.h"
#include "displaypage.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 메뉴 생성
    QMenu *menu = menuBar()->addMenu("Menu");
    QAction *settingAction = new QAction("Setting", this);
    QAction *displayAction = new QAction("Display", this);
    menu->addAction(settingAction);
    menu->addAction(displayAction);

    // 페이지 생성
    SettingPage *settingPage = new SettingPage(this);
    DisplayPage *displayPage = new DisplayPage(this);

    // QStackedWidget 설정
    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(settingPage);   // index 0
    stackedWidget->addWidget(displayPage);   // index 1
    stackedWidget->setCurrentIndex(1);       // ⭐ 기본 화면을 Display로 설정
    setCentralWidget(stackedWidget);

    setWindowTitle("Multi-Page MainWindow");
    resize(600, 400);

    // 메뉴 동작 연결
    connect(settingAction, &QAction::triggered, [=]() {
        stackedWidget->setCurrentIndex(0);
    });

    connect(displayAction, &QAction::triggered, [=]() {
        stackedWidget->setCurrentIndex(1);
    });
}
