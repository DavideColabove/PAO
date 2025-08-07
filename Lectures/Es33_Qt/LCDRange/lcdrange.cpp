#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>
#include "lcdrange.h"

LCDRange::LCDRange(QWidget *parent) : QWidget(parent), slider = new QSlider(Qt::Horizontal){
    QLCDNumber *lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);
    slider->setRange(0,99);
    slider->setValue(0);
    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
    // connect di un signal UNO ad un altro signal DUE
    // quando viene emesso UNO, viene emesso anche DUE
    connect(slider, SIGNAL(valueChanged(int)), this, SIGNAL(valueChanged(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);
}

int LCDRange::value() const{
    return slider->value();
}

// definizione di slot
void LCDRange::setValue(int value){
    slider->setValue(value);
}