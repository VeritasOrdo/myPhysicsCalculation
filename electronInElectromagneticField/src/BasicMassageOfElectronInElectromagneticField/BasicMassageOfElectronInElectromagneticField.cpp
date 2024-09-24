#include "../../include/BasicMassageOfElectronInElectromagneticField/BasicMassageOfElectronInElectromagneticField.h"

BasicMassageOfElectronInElectromagneticField::BasicMassageOfElectronInElectromagneticField(double fieldParameter1,double fieldParameter2){
    this->fieldParameter1 = fieldParameter1;
    this->fieldParameter2 = fieldParameter2;
}

double BasicMassageOfElectronInElectromagneticField::getFieldParameter1(){
    return this->fieldParameter1;
}

double BasicMassageOfElectronInElectromagneticField::getFieldParameter2(){
    return this->fieldParameter2;
}

BasicMassageOfElectronInElectromagneticField::~BasicMassageOfElectronInElectromagneticField(){
}