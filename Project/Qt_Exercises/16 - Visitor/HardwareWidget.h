#ifndef HARDWARE_WIDGET_H
#define HARDWARE_WIDGET_H

#include <QWidget>
#include "HardwareVisitor.h"

class HardwareWidget : public HardwareVisitor {
public:
    QWidget *getWidget();
    virtual void visit(Storage *storage);
    virtual void visit(Cpu *cpu);

private:
    QWidget *widget;
};

#endif