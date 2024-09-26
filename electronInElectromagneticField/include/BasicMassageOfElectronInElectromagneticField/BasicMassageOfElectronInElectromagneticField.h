#include "../../../package/include/LorentzVector/LorentzVector.h"
#include "../../../package/include/Dimension3Vector/Dimension3Vector.h"
#include "../../../package/include/Particle/Particle.h"
#include "../../../package/include/LaserField/LaserField.h"

#pragma once

class BasicMassageOfElectronInElectromagneticField{
    private:
        Particle electronBaseIn;
        Particle electronBaseOut;
        LaserField laserField1;
        LaserField laserField2;

    public:
        BasicMassageOfElectronInElectromagneticField();
        BasicMassageOfElectronInElectromagneticField(LaserField laserField1, LaserField laserField2);
        BasicMassageOfElectronInElectromagneticField(Particle electronBaseIn, Particle electronBaseOut, LaserField laserField1, LaserField laserField2);
        Particle getElectronBaseIn();
        Particle getElectronBaseOut();
        LaserField getLaserField1();
        LaserField getLaserField2();
        ~BasicMassageOfElectronInElectromagneticField();
};