#include <cmath>

#pragma once

class Spin {
    private:
        double spinValue;
        double spinX;
        double spinY;
        double spinZ;
    public:
        Spin(double spinValue);
        Spin(double spinValue,double spinX,double spinY,double spinZ);
        Spin(double spinValue,double azimuthalAngle,double polarAngle);
        double getSpinValue();
        double getSpinX();
        double getSpinY();
        double getSpinZ();
        double getAzimuthalAngle();
        double getPolarAngle();
        ~Spin();
};

