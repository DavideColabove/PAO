#include "Storage.h"

Storage::Storage(QString name, unsigned int capacity, double cost_per_byte): Hardware(name), capacity(capacity), cost_per_byte(cost_per_byte) {}

double Storage::getPrice() const {
    return cost_per_byte * capacity;
}

unsigned int Storage::getCapacity() const {
    return capacity;
}

void Storage::setCapacity(unsigned int capacity) {
    this->capacity = capacity;
}

double Storage::getCostPerByte() const {
    return cost_per_byte;
}

void Storage::setCostPerByte(double cost_per_byte) {
    this->cost_per_byte = cost_per_byte;
}

void Storage::accept(HardwareVisitor *visitor) {
    visitor->visit(this);
}