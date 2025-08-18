#ifndef TIMERHANDLER_H
#define TIMERHANDLER_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class TimerHandler : public QObject {
    Q_OBJECT

public:
    explicit TimerHandler(QObject *parent = nullptr);

private slots:
    void updateMessage();

private:
    QTimer *timer;
};

#endif // TIMERHANDLER_H
