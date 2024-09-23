#include "../../include/ElectronBase/ElectronBase.h"

ElectronBase::ElectronBase(double energy, Dimension3Vector<double> momentum) {
    this->energy = energy;
    this->momentum = momentum;
    this->position = Dimension3Vector<double>(0, 0, 0);
    this->spin = Spin(0.5);
}

ElectronBase::ElectronBase(double energy, Dimension3Vector<double> momentum, Dimension3Vector<double> position) {
    this->energy = energy;
    this->momentum = momentum;
    this->position = position;
    this->spin = Spin(0.5);
}

ElectronBase::ElectronBase(double energy, Dimension3Vector<double> momentum, Dimension3Vector<double> position, Spin spin) {
    this->energy = energy;
    this->momentum = momentum;
    this->position = position;
    this->spin = spin;
}

double ElectronBase::getEnergy() {
    return this->energy;
}

Dimension3Vector<double> ElectronBase::getMomentum() {
    return this->momentum;
}

Dimension3Vector<double> ElectronBase::getPosition() {
    return this->position;
}

Spin ElectronBase::getSpin() {
    return this->spin;
}

double ElectronBase::getMass() {
    return this->electronMass;
}

ElectronBase::~ElectronBase() {
}

