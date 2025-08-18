#ifndef CPU_H
#define CPU_H

#include "Hardware.h"

class Cpu: public Hardware {
public:
    Cpu(QString name, double price, unsigned int frequency);
    virtual double getPrice() const;
    void setPrice(double price);
    unsigned int getFrequency() const;
    void setFrequency(unsigned int frequency);
    virtual void accept(HardwareVisitor *visitor);

private:
    double price;
    unsigned int frequency;
};

#endif