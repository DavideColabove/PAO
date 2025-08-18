#include "Hardware.h"

Hardware::Hardware(QString name): name(name) {
}

Hardware::~Hardware() {}

QString Hardware::getName() const {
    return name;
}

void Hardware::setName(QString name) {
    this->name = name;
}