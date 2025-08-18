#ifndef HARDWARE_VISIOR_H
#define HARDWARE_VISIOR_H

class Storage;
class Cpu;

class HardwareVisitor {
public:
    virtual void visit(Storage *storage) = 0;
    virtual void visit(Cpu *cpu) = 0;
};

#endif