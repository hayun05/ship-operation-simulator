#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>


class OpenGLWidget;


class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();


private:
    OpenGLWidget* glWidget;
};


#endif // MAINWINDOW_H
