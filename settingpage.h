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
#include <QMessageBox>
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
    QComboBox* boatSelcet;
    QSlider* boatSpeed;
    QSlider* wind;

    QCheckBox* rain;



signals:
    void onRain(bool check);
    void onSpeedChanged(int speed);
    void onSelectBoat(int index);
    void onSizeChecked(int size);
    void onWind(int wind);

private slots:
    void checkedRain(bool check);
    void speedChanged(int speed);
    void selectBoat(int index);
    void sizeChecked(int size);
    void windChecked(int wind);

};

#endif // SETTINGPAGE_H
