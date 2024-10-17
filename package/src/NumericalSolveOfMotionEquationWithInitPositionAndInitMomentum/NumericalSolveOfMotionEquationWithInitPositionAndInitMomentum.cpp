#include "../../include/NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum/NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum.h"
#include <gsl/gsl_errno.h>
#include <gsl/gsl_odeiv2.h>
#include <iostream>

NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum::NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum() : NumericalSolveOfMotionEquationBase<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)>() {
    this->particleStateInitial = ParticleState();
    int arraySize = (int)((NumericalSolveOfMotionEquationBase::getTimeEnd()-NumericalSolveOfMotionEquationBase::getTimeBegin())/NumericalSolveOfMotionEquationBase::getStepLength())+1;
    this->positionList.reserve(arraySize);
    this->momentumList.reserve(arraySize);
}

NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum::NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum(double timeBegin, double timeEnd, double stepLength, std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> motionEquation, ParticleState particleStateInitial) : NumericalSolveOfMotionEquationBase<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)>(timeBegin,timeEnd,stepLength,motionEquation) {
    this->particleStateInitial = particleStateInitial;
    int arraySize = (int)((timeEnd-timeBegin)/stepLength)+1;
    this->positionList.reserve(arraySize);
    this->momentumList.reserve(arraySize);
}

NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum::NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum(double timeBegin, double timeEnd, double stepLength, std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> motionEquation, ParticleState particleStateInitial, double relativeError, double absoluteError) : NumericalSolveOfMotionEquationBase<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)>(timeBegin,timeEnd,stepLength,motionEquation) {
    this->particleStateInitial = particleStateInitial;
    int arraySize = (int)((timeEnd-timeBegin)/stepLength)+1;
    this->positionList.reserve(arraySize);
    this->momentumList.reserve(arraySize);
    this->relativeError = relativeError;
    this->absoluteError = absoluteError;
}

ParticleState NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum::getParticleStateInitial() {
    return this->particleStateInitial;
}

void NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum::setParticleStateInitial(ParticleState particleStateInitial) {
    this->particleStateInitial = particleStateInitial;
}

std::vector<Dimension3Vector<double>> NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum::getPositionList() {
    return this->positionList;
}

std::vector<Dimension3Vector<double>> NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum::getMomentumList() {
    return this->momentumList;
}

std::vector<Dimension3Vector<double>> NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum::getVelocityList() {
    std::vector<Dimension3Vector<double>> velocityList;
    velocityList.reserve(this->positionList.size());
    const double mass = this->particleStateInitial.getParticleMass();
    for(int i=0;i<this->positionList.size();i++) {
        double energy = sqrt(mass*mass+this->momentumList[i]*this->momentumList[i]);
        velocityList.push_back(this->momentumList[i]/energy);
    }
    return velocityList;
}

std::vector<double> NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum::getEnergyList() {
    std::vector<double> energyList;
    energyList.reserve(this->positionList.size());
    const double mass = this->particleStateInitial.getParticleMass();
    for(int i=0;i<this->positionList.size();i++) {
        double energy = sqrt(mass*mass+this->momentumList[i]*this->momentumList[i]);
        energyList.push_back(energy);
    }
    return energyList;
}

double NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum::getMass() {
    return this->particleStateInitial.getParticleMass();
}

std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum::getMotionEquation() {
    return NumericalSolveOfMotionEquationBase::getMotionEquation();
}

int func(double t,const double y[],double f[],void *params) {
        NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum *p = (NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum *)params;
        double energy = std::sqrt((p->getMass()*p->getMass())+((y[3]*y[3])+(y[4]*y[4])+(y[5]*y[5])));
        /*std::cout<<"y0,y1,y2,y3,y4,y5: "<<std::fixed<<y[0]<<","<<y[1]<<","<<y[2]<<","<<y[3]<<","<<y[4]<<","<<y[5]<<std::endl;
        std::cin.get();
        std::cout<<"f0,f1,f2,f3,f4,f5: "<<std::fixed<<y[0]<<","<<f[0]<<","<<f[1]<<","<<f[2]<<","<<f[3]<<","<<f[4]<<","<<f[5]<<std::endl;
        std::cin.get();*/
        f[0] = y[3]/energy;
        f[1] = y[4]/energy;
        f[2] = y[5]/energy;
        //std::cout<<"t: "<<t<<std::endl;
        //std::cin.get();
        Dimension3Vector<double> acceleration = p->getMotionEquation()(Dimension3Vector<double>(y[0],y[1],y[2]),Dimension3Vector<double>(y[3],y[4],y[5]),t);
        f[3] = acceleration.getX();
        f[4] = acceleration.getY();
        f[5] = acceleration.getZ();
        //std::cout<<"f0,f1,f2,f3,f4,f5: "<<f[0]<<","<<f[1]<<","<<f[2]<<","<<f[3]<<","<<f[4]<<","<<f[5]<<std::endl;
        //std::cin.get();
        return GSL_SUCCESS;
};

void NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum::solve() {
    double t = NumericalSolveOfMotionEquationBase::getTimeBegin();
    std::cout<<"particleStateInitial.getParticleMomentum(): "<<this->particleStateInitial.getParticleMomentum()<<std::endl;
    this->positionList.push_back(this->particleStateInitial.getParticleCoordinate());
    this->momentumList.push_back(this->particleStateInitial.getParticleMomentum());
    double y[6] = {this->particleStateInitial.getParticleCoordinate().getX(), this->particleStateInitial.getParticleCoordinate().getY(), this->particleStateInitial.getParticleCoordinate().getZ(), this->particleStateInitial.getParticleMomentum().getX(), this->particleStateInitial.getParticleMomentum().getY(), this->particleStateInitial.getParticleMomentum().getZ()};
    gsl_odeiv2_system sys = {func, NULL, 6, this};
    gsl_odeiv2_driver *d = gsl_odeiv2_driver_alloc_y_new(&sys, gsl_odeiv2_step_rkf45, NumericalSolveOfMotionEquationBase::getStepLength(), this->relativeError, this->absoluteError);
    for(int i=1;i<this->positionList.capacity();i++){
        double ti = NumericalSolveOfMotionEquationBase::getTimeBegin()+i*NumericalSolveOfMotionEquationBase::getStepLength();
        int status = gsl_odeiv2_driver_apply(d, &t, ti, y);
        if (status != GSL_SUCCESS) {
            std::cout << "error, return value=" << status << std::endl;
            break;
        }
        this->positionList.push_back(Dimension3Vector<double>(y[0],y[1],y[2]));
        this->momentumList.push_back(Dimension3Vector<double>(y[3],y[4],y[5]));
    }
    gsl_odeiv2_driver_free(d);
}

NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum::~NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum() {
    // std::cout << "Destructor of NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum" << std::endl;
}

