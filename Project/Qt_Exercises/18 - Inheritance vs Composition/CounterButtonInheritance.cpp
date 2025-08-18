#include "CounterButtonInheritance.h"

CounterButtonInheritance::CounterButtonInheritance(QWidget *parent)
    : QPushButton(parent), counter(0) {
    // TODO: Set the initial text of the button (e.g., "Count: 0")
    
    // TODO: Connect the button's clicked signal to the incrementCounter slot
}

void CounterButtonInheritance::incrementCounter() {
    // TODO: Increment the counter and update the button's text
}
