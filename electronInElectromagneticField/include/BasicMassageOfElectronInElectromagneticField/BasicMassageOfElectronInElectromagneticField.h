#include "../../../package/include/LorentzVector/LorentzVector.h"
#include "../../../package/include/Dimension3Vector/Dimension3Vector.h"
#include "../../../package/include/Spin/Spin.h"
#include "../../../package/include/LaserField/LaserField.h"

#pragma once

class BasicMassageOfElectronInElectromagneticField{
    private:
        Spin electronSpinIn;
        Spin electronSpinOut;
        LaserField laserField1;
        LaserField laserField2;

    public:
        BasicMassageOfElectronInElectromagneticField();
        BasicMassageOfElectronInElectromagneticField(LaserField laserField1, LaserField laserField2);
        BasicMassageOfElectronInElectromagneticField(Spin electronSpinIn, Spin electronSpinOut, LaserField laserField1, LaserField laserField2);
        Spin getElectronSpinIn();
        Spin getElectronSpinOut();
        LaserField getLaserField1();
        LaserField getLaserField2();
        ~BasicMassageOfElectronInElectromagneticField();
};