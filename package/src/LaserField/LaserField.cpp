#include "../../include/LaserField/LaserField.h"

LaserField::LaserField() {
    this->fieldParameter = 0;
    this->laserFrequency = 1.55;
    this->rotationDirection = 1;
}

LaserField::LaserField(double fieldParameter) {
    this->fieldParameter = fieldParameter;
    this->laserFrequency = 1.55;
    this->rotationDirection = 1;
}

LaserField::LaserField(double fieldParameter,double laserFrequency) {
    this->fieldParameter = fieldParameter;
    this->laserFrequency = laserFrequency;
    this->rotationDirection = 1;
}

LaserField::LaserField(double fieldParameter,double laserFrequency,int rotationDirection) {
    this->fieldParameter = fieldParameter;
    this->laserFrequency = laserFrequency;
    this->rotationDirection = rotationDirection;
}

LaserField::LaserField(double fieldParameter,int rotationDirection) {
    this->fieldParameter = fieldParameter;
    this->laserFrequency = 1.55;
    this->rotationDirection = rotationDirection;
}

double LaserField::getFieldParameter() {
    return this->fieldParameter;
}

double LaserField::getLaserFrequency() {
    return this->laserFrequency;
}

double LaserField::getRotationDirection() {
    return this->rotationDirection;
}

LaserField::~LaserField() {
}

