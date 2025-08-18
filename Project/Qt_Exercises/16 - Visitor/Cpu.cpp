#include "Cpu.h"

Cpu::Cpu(QString name, double price, unsigned int frequency): Hardware(name), price(price), frequency(frequency) {}

double Cpu::getPrice() const {
    return price;
}

void Cpu::setPrice(double price) {
    this->price = price;
}

unsigned int Cpu::getFrequency() const {
    return frequency;
}

void Cpu::setFrequency(unsigned int frequency) {
    this->frequency = frequency;
}

void Cpu::accept(HardwareVisitor *visitor) {
    visitor->visit(this);
}