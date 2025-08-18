#ifndef COUNTERWIDGETCOMPOSITION_H
#define COUNTERWIDGETCOMPOSITION_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

// A widget that contains a button and a label to track and display a counter.
class CounterWidgetComposition : public QWidget {
    Q_OBJECT

public:
    explicit CounterWidgetComposition(QWidget *parent = nullptr);

private:
    int counter; // Tracks the current counter value
    QPushButton *button; // Button to increment the counter
    QLabel *label; // Label to display the counter value

private slots:
    void incrementCounter(); // Slot to handle button clicks
};

#endif // COUNTERWIDGETCOMPOSITION_H
