#ifndef SETTINGPAGE_H
#define SETTINGPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QComboBox>
#include <QSpacerItem>
#include <QSpinBox>
#include <QCheckBox>
#include <QSlider>

class SettingPage : public QWidget
{
    Q_OBJECT

public:
    explicit SettingPage(QWidget *parent = nullptr);

private:
    QGroupBox *boatGroup;
    QGroupBox *prefGroup;

    QVBoxLayout *boatLayout;
    QVBoxLayout *prefLayout;

    QHBoxLayout* BLayout1;
    QHBoxLayout* BLayout2;
    QHBoxLayout* BLayout3;

    QHBoxLayout* PLayout1;
    QHBoxLayout* PLayout2;

    QLabel* Blb1;
    QLabel* Blb2;
    QLabel* Blb3;
    QLabel* Plb1;

    QSpinBox* boatSize;
    QComboBox* boatSelect;
    QSlider* boatSpeed;
    QSlider* wind;
    QCheckBox* rain;

signals:
    void rainToggled(bool);
    void speedValueChanged(int);
    void boatTypeChanged(int);
    void sizeValueChanged(int);
    void windValueChanged(int);

private slots:
    void handleRain(bool checked);
    void handleSpeed(int speed);
    void handleBoatType(int index);
    void handleSize(int size);
    void handleWind(int value);

};


#endif // SETTINGPAGE_H
