#include "mainwindow.h"
#include "openglwidget.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), glWidget(new OpenGLWidget(this)) {
    setCentralWidget(glWidget);
    resize(1200, 800);
}


MainWindow::~MainWindow() {}
