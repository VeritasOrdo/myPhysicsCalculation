#include "../../include/Spin/Spin.h"

Spin::Spin() {
    this->spinValue = 0.5;
    this->spinX = 0;
    this->spinY = 0;
    this->spinZ = 1;
}

Spin::Spin(double spinValue) {
    this->spinValue = spinValue;
    this->spinX = 0;
    this->spinY = 0;
    this->spinZ = 1;
}

Spin::Spin(double spinValue,double spinX,double spinY,double spinZ) {
    this->spinValue = spinValue;
    this->spinX = spinX;
    this->spinY = spinY;
    this->spinZ = spinZ;
}

Spin::Spin(double spinValue,double azimuthalAngle,double polarAngle) {
    this->spinValue = spinValue;
    this->spinX = sin(polarAngle)*cos(azimuthalAngle);
    this->spinY = sin(polarAngle)*sin(azimuthalAngle);
    this->spinZ = cos(polarAngle);
}

double Spin::getSpinValue() {
    return this->spinValue;
}

double Spin::getSpinX() {
    return this->spinX;
}

double Spin::getSpinY() {
    return this->spinY;
}

double Spin::getSpinZ() {
    return this->spinZ;
}

double Spin::getAzimuthalAngle() {
    return atan2(this->spinY,this->spinX);
}

double Spin::getPolarAngle() {
    return acos(this->spinZ);
}

Spin::~Spin() {
}