#include "MyClass.h"
#include <QDebug>

MyClass::MyClass(QObject *parent) : QObject(parent) {
    button = new QPushButton("Click me!", nullptr);

    // TODO: Connect the button's clicked signal to the handleClick slot
}

void MyClass::showButton() {
    button->show();
}

void MyClass::handleClick() {
    // Print a message to the console when the button is clicked
    qDebug() << "Button was clicked!";
}