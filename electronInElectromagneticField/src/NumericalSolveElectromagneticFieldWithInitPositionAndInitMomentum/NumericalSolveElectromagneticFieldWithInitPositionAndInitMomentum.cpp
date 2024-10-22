#include "../../include/NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum/NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum.h"

NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum::NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum() {
    this->timeBegin = 0;
    this->timeEnd = 0;
    this->stepLength = 0;
    this->relativeError = 0;
    this->absoluteError = 0;
    this->particleStateInitial = ParticleState();
    this->electricField = nullptr;
    this->magneticField = nullptr;
    this->solveTheMotionEquation = NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum();
}

NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum::NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum(double timeBegin, double timeEnd, double stepLength, std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> electricField, std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> magneticField, ParticleState particleStateInitial) {
    this->timeBegin = timeBegin;
    this->timeEnd = timeEnd;
    this->stepLength = stepLength;
    this->relativeError = 0;
    this->absoluteError = 0;
    this->particleStateInitial = particleStateInitial;
    this->electricField = electricField;
    this->magneticField = magneticField;
    this->solveTheMotionEquation = NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum(timeBegin, timeEnd, stepLength, [electricField,magneticField](Dimension3Vector<double> y,Dimension3Vector<double> dydt,double t)->Dimension3Vector<double>{
        double lorentzFactor = 1/std::sqrt(1-dydt*dydt);
        return (electricField(y,dydt,t)+dydt^magneticField(y,dydt,t))*lorentzFactor;
    }
    , particleStateInitial);
}

NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum::NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum(double timeBegin, double timeEnd, double stepLength, std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> electricField, std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> magneticField, ParticleState particleStateInitial, double relativeError, double absoluteError) {
    this->timeBegin = timeBegin;
    this->timeEnd = timeEnd;
    this->stepLength = stepLength;
    this->relativeError = relativeError;
    this->absoluteError = absoluteError;
    this->particleStateInitial = particleStateInitial;
    this->electricField = electricField;
    this->magneticField = magneticField;
    this->solveTheMotionEquation = NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum(timeBegin, timeEnd, stepLength, [electricField,magneticField](Dimension3Vector<double> y,Dimension3Vector<double> dydt,double t)->Dimension3Vector<double>{
        double lorentzFactor = 1/std::sqrt(1-dydt*dydt);
        return (electricField(y,dydt,t)+dydt^magneticField(y,dydt,t))*lorentzFactor;
    }
    , particleStateInitial, relativeError, absoluteError);
}


ParticleState NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum::getParticleStateInitial() {
    return this->particleStateInitial;
}

void NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum::setParticleStateInitial(ParticleState particleStateInitial) {
    this->particleStateInitial = particleStateInitial;
}

std::vector<Dimension3Vector<double>> NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum::getPositionList() {
    return this->solveTheMotionEquation.getPositionList();
}

std::vector<Dimension3Vector<double>> NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum::getMomentumList() {
    return this->solveTheMotionEquation.getMomentumList();
}

std::vector<Dimension3Vector<double>> NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum::getVelocityList() {
    return this->solveTheMotionEquation.getVelocityList();
}

std::vector<double> NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum::getEnergyList() {
    return this->solveTheMotionEquation.getEnergyList();
}

std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum::getElectricField() {
    return this->electricField;
}

std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum::getMagneticField() {
    return this->magneticField;
}

double NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum::getMass() {
    return this->particleStateInitial.getParticleMass();
}

void NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum::solve() {
    this->solveTheMotionEquation.solve();
}

NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum::~NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum() {
    this->timeBegin = 0;
    this->timeEnd = 0;
    this->stepLength = 0;
    this->relativeError = 0;
    this->absoluteError = 0;
    this->particleStateInitial = ParticleState();
    this->electricField = nullptr;
    this->magneticField = nullptr;
    this->solveTheMotionEquation = NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum();
}

