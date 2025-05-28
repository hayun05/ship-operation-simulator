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
    QHBoxLayout* PLayout1;

    QLabel* Blb1;
    QLabel* Blb2;

    QLabel* Plb1;

    QSpinBox* boatSize;
    QComboBox* boatSelcet;

    QCheckBox* rain;


signals:
    void checkedRain(bool checked);
};

#endif // SETTINGPAGE_H
