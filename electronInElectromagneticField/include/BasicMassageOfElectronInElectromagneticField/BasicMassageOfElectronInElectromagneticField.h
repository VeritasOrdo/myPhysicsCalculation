#include "../../../package/include/LorentzVector/LorentzVector.h"
#include "../../../package/include/Dimension3Vector/Dimension3Vector.h"
#include "../../../package/include/ElectronBase/ElectronBase.h"

#pragma once

class BasicMassageOfElectronInElectromagneticField{
    private:
        double fieldParameter1;
        double fieldParameter2;
    public:
        BasicMassageOfElectronInElectromagneticField(double fieldParameter1,double fieldParameter2);
        double getFieldParameter1();
        double getFieldParameter2();
        ~BasicMassageOfElectronInElectromagneticField();
};