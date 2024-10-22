#include "../../include/BasicMassageOfElectronInElectromagneticField/BasicMassageOfElectronInElectromagneticField.h"

BasicMassageOfElectronInElectromagneticField::BasicMassageOfElectronInElectromagneticField() {
    this->electronSpinIn = Spin();
    this->electronSpinOut = Spin();
    this->laserField1 = LaserField();
    this->laserField2 = LaserField();
}

BasicMassageOfElectronInElectromagneticField::BasicMassageOfElectronInElectromagneticField(LaserField laserField1, LaserField laserField2) {
    this->electronSpinIn = Spin();
    this->electronSpinOut = Spin();
    this->laserField1 = laserField1;
    this->laserField2 = laserField2;
}

BasicMassageOfElectronInElectromagneticField::BasicMassageOfElectronInElectromagneticField(Spin electronBaseIn, Spin electronBaseOut, LaserField laserField1, LaserField laserField2) {
    this->electronSpinIn = electronBaseIn;
    this->electronSpinOut = electronBaseOut;
    this->laserField1 = laserField1;
    this->laserField2 = laserField2;
}

Spin BasicMassageOfElectronInElectromagneticField::getElectronSpinIn() {
    return this->electronSpinIn;
}

Spin BasicMassageOfElectronInElectromagneticField::getElectronSpinOut() {
    return this->electronSpinOut;
}

LaserField BasicMassageOfElectronInElectromagneticField::getLaserField1() {
    return this->laserField1;
}

LaserField BasicMassageOfElectronInElectromagneticField::getLaserField2() {
    return this->laserField2;
}

BasicMassageOfElectronInElectromagneticField::~BasicMassageOfElectronInElectromagneticField() {
    this->electronSpinIn.~Spin();
    this->electronSpinOut.~Spin();
    this->laserField1.~LaserField();
    this->laserField2.~LaserField();
}
