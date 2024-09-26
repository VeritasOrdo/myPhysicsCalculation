#pragma once

class LaserField {
    private:
        double fieldParameter;
        double laserFrequency;
        int rotationDirection;
    public:
        LaserField();
        LaserField(double fieldParameter);
        LaserField(double fieldParameter,double laserFrequency);
        LaserField(double fieldParameter,double laserFrequency,int rotationDirection);
        LaserField(double fieldParameter,int rotationDirection);
        double getFieldParameter();
        double getLaserFrequency();
        double getRotationDirection();
        ~LaserField();
};