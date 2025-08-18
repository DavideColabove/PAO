#ifndef STORAGE_H
#define STORAGE_H

#include "Hardware.h"

class Storage: public Hardware {
public:
    Storage(QString name, unsigned int capacity, double cost_per_byte);
    virtual double getPrice() const;
    unsigned int getCapacity() const;
    void setCapacity(unsigned int capacity);
    double getCostPerByte() const;
    void setCostPerByte(double cost_per_byte);
    virtual void accept(HardwareVisitor *visitor);

private:
    unsigned int capacity;
    double cost_per_byte;
};

#endif