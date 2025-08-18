#include "StyledWidget.h"
#include <QVBoxLayout>

StyledWidget::StyledWidget(QWidget *parent) : QWidget(parent) {
    setupUI();

    // TODO: Apply a style sheet to this widget to customize its appearance
}

void StyledWidget::setupUI() {
    label = new QLabel("Custom Label", this);
    lineEdit = new QLineEdit(this);
    button = new QPushButton("Hover Me", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addWidget(button);
}
