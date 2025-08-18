#include "MainWidget.h"
#include <QVBoxLayout>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent) {
    // Create a label and a button
    label = new QLabel("Hello, Qt!", this);
    button = new QPushButton("Change Text", this);

    // TODO: Connect the button's clicked signal to the updateLabel() slot

    // Create a vertical layout to organize the widgets
    QVBoxLayout *layout = new QVBoxLayout;

    // TODO: Add the label and button to the layout

    // Set the layout for the widget
    setLayout(layout);
}

void MainWidget::updateLabel() {
    // TODO: Change the label's text when the button is clicked
}
