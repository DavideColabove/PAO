#ifndef COUNTERBUTTONINHERITANCE_H
#define COUNTERBUTTONINHERITANCE_H

#include <QPushButton>

// A button that keeps track of a counter and updates its text when clicked.
class CounterButtonInheritance : public QPushButton {
    Q_OBJECT

public:
    explicit CounterButtonInheritance(QWidget *parent = nullptr);

private:
    int counter; // Tracks the current counter value

private slots:
    void incrementCounter(); // Slot to handle button clicks
};

#endif // COUNTERBUTTONINHERITANCE_H
