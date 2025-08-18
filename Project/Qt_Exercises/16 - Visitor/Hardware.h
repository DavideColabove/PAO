#ifndef HARDWARE_H
#define HARDWARE_H

#include <QString>
#include "HardwareVisitor.h"

class Hardware {
private:
    QString name;

public:
    Hardware(QString name);
    virtual ~Hardware();

    QString getName() const;
    void setName(QString name);

    virtual double getPrice() const = 0;

    virtual void accept(HardwareVisitor *visitor) = 0;
};

#endif