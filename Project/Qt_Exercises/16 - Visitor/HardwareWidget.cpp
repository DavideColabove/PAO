#include "HardwareWidget.h"

QWidget* HardwareWidget::getWidget() {
    return widget;
}

void HardwareWidget::visit(Storage *storage) {
    // TODO: Build a widget suitable to display a storage
}

void HardwareWidget::visit(Cpu *cpu) {
    // TODO: Build a widget suitable to display a CPU
}