#include "mainwindow.h"
#include "settingpage.h"
#include "displaypage.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QScreen>
#include <QGuiApplication>


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

    // 화면 해상도 기반 크기 계산
    QScreen *screen = QGuiApplication::primaryScreen();
    QSize screenSize = screen->availableGeometry().size();

    // 화면의 80%를 기준으로 하되, 10:8 비율 유지
    int width = screenSize.width() * 0.8;
    int height = screenSize.height() * 0.8;  // 10:8 비율

    setFixedSize(width, height);  // 창 크기 고정
    // 메뉴 동작 연결
    connect(settingAction, &QAction::triggered, [=]() {
        stackedWidget->setCurrentIndex(0);
    });

    connect(displayAction, &QAction::triggered, [=]() {
        stackedWidget->setCurrentIndex(1);
    });
}
