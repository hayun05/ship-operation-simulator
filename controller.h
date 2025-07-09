#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject {
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);

public slots:
    void onRain(bool checked);  // 슬롯 정의
    void onSpeedChanged(int speed);  // 오타 수정
    void onSelectBoat(int index);
    void onSizeChecked(int size);
    void onWind(int wind);
};

#endif // CONTROLLER_H
