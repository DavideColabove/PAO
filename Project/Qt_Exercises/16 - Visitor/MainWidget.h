#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "Hardware.h"

class MainWidget : public QWidget {
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    void pushHardware();

private slots:
    void createStorage();
    
    void createCpu();

private:
    Hardware* hardware;
    QVBoxLayout *layout;
    QPushButton *storageButton;
    QPushButton *cpuButton;
};

#endif // MAINWIDGET_H
