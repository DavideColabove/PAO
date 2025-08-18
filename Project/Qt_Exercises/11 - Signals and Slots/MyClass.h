#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QPushButton>

class MyClass : public QObject {
    Q_OBJECT

public:
    explicit MyClass(QObject *parent = nullptr);
    void showButton();

public slots:
    void handleClick();

private:
    QPushButton *button;
};

#endif // MYCLASS_H