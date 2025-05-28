#include <QObject>

class Controller : public QObject {
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);

public slots:
    void rainChecked(bool checked);  // 슬롯 정의
};
