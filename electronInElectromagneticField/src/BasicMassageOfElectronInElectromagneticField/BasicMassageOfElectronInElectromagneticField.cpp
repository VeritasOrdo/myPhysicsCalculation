#include "../../include/BasicMassageOfElectronInElectromagneticField/BasicMassageOfElectronInElectromagneticField.h"

BasicMassageOfElectronInElectromagneticField::BasicMassageOfElectronInElectromagneticField() {
    this->electronBaseIn = Particle("electron");
    this->electronBaseOut = Particle("electron");
    this->laserField1 = LaserField();
    this->laserField2 = LaserField();
}

BasicMassageOfElectronInElectromagneticField::BasicMassageOfElectronInElectromagneticField(LaserField laserField1, LaserField laserField2) {
    this->electronBaseIn = Particle("electron");
    this->electronBaseOut = Particle("electron");
    this->laserField1 = laserField1;
    this->laserField2 = laserField2;
}

BasicMassageOfElectronInElectromagneticField::BasicMassageOfElectronInElectromagneticField(Particle electronBaseIn, Particle electronBaseOut, LaserField laserField1, LaserField laserField2) {
    this->electronBaseIn = electronBaseIn;
    this->electronBaseOut = electronBaseOut;
    this->laserField1 = laserField1;
    this->laserField2 = laserField2;
}

Particle BasicMassageOfElectronInElectromagneticField::getElectronBaseIn() {
    return this->electronBaseIn;
}

Particle BasicMassageOfElectronInElectromagneticField::getElectronBaseOut() {
    return this->electronBaseOut;
}

LaserField BasicMassageOfElectronInElectromagneticField::getLaserField1() {
    return this->laserField1;
}

LaserField BasicMassageOfElectronInElectromagneticField::getLaserField2() {
    return this->laserField2;
}

BasicMassageOfElectronInElectromagneticField::~BasicMassageOfElectronInElectromagneticField() {
    this->electronBaseIn.~Particle();
    this->electronBaseOut.~Particle();
    this->laserField1.~LaserField();
    this->laserField2.~LaserField();
}
