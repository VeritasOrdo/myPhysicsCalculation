#include "../../include/ElectronTrajectoryByAnalysisInATimeSlice/ElectronTrajectoryByAnalysisInATimeSlice.h"

ElectronTrajectoryByAnalysisInATimeSlice::ElectronTrajectoryByAnalysisInATimeSlice() {
    this->properTimeSlice = 0;
    this->electronStateInitial = ParticleState();
    this->electronStateFinal = ParticleState();
}

ElectronTrajectoryByAnalysisInATimeSlice::ElectronTrajectoryByAnalysisInATimeSlice(double properTimeSlice, ParticleState electronStateInitial, LaserField laserField1, LaserField laserField2) : BasicMassageOfElectronInElectromagneticField(laserField1,laserField2) {
    this->properTimeSlice = properTimeSlice;
    this->electronStateInitial = electronStateInitial;
    this->electronStateFinal = ParticleState();
}

ParticleState ElectronTrajectoryByAnalysisInATimeSlice::getElectronStateInitial() {
    return this->electronStateInitial;
}

ParticleState ElectronTrajectoryByAnalysisInATimeSlice::getElectronStateFinal() {
    return this->electronStateFinal;
}

double ElectronTrajectoryByAnalysisInATimeSlice::getProperTimeSlice() {
    return this->properTimeSlice;
}

void ElectronTrajectoryByAnalysisInATimeSlice::calculateElectronStateFinal() {
    double electronMass = this->electron.getRestMass();
    LaserField laserField1 = this->getLaserField1();
    LaserField laserField2 = this->getLaserField2();
    double fieldParameter1 = laserField1.getFieldParameter();
    double fieldParameter2 = laserField2.getFieldParameter();
    double LaserFrequency1 = laserField1.getLaserFrequency();
    double LaserFrequency2 = laserField2.getLaserFrequency();
    double properTime = this->properTimeSlice;
    Dimension3Vector<double> electronVelocity = this->electronStateInitial.getParticleVelocity();
    double electronEnergy = this->electronStateInitial.getParticleEnergy();
    double momentumZPrime = electronVelocity.getZ();
    double momentumXPrime = electronVelocity.getX();
    double phase1 = ((LaserFrequency1*electronEnergy*(1-electronVelocity.getZ()))/electronMass)*properTime;
    double phase2 = ((LaserFrequency2*electronEnergy*(1+electronVelocity.getZ()))/electronMass)*properTime;
    LorentzVector<double> electronLorentzMomentum = LorentzVector<double>(
        electronEnergy+
        momentumXPrime*LaserFrequency1*(
            ((electronMass*fieldParameter1)/(LaserFrequency1*electronEnergy*(1-electronVelocity.getZ())))*std::cos(phase1)+
            ((electronMass*fieldParameter2)/(LaserFrequency2*electronEnergy*(1+electronVelocity.getZ())))*std::cos(phase2)
        )
        ,
        momentumXPrime+
        electronMass*fieldParameter1*std::cos(phase1)+electronMass*fieldParameter2*std::cos(phase2)
        ,
        electronVelocity.getY()+
        electronMass*fieldParameter1*std::sin(phase1)+electronMass*fieldParameter2*std::sin(phase2)
        ,
        momentumZPrime+
        momentumXPrime*LaserFrequency1*(
            ((electronMass*fieldParameter1)/(LaserFrequency1*electronEnergy*(1-electronVelocity.getZ())))*std::cos(phase1)-
            ((electronMass*fieldParameter2)/(LaserFrequency2*electronEnergy*(1+electronVelocity.getZ())))*std::cos(phase2)
        )+
        ((2*electronMass*electronMass*fieldParameter1*fieldParameter2*LaserFrequency1)/(-2*LaserFrequency1*electronEnergy*electronVelocity.getZ()))*std::cos(phase1-phase2)
    );
    LorentzVector<double> electronCoordinate = LorentzVector<double>(
        ((electronEnergy)/electronMass)*properTime+
        momentumXPrime*LaserFrequency1*(
            ((electronMass*fieldParameter1)/((LaserFrequency1*electronEnergy*(1-electronVelocity.getZ()))*(LaserFrequency1*electronEnergy*(1-electronVelocity.getZ()))))*std::sin(phase1)+
            ((electronMass*fieldParameter2)/((LaserFrequency2*electronEnergy*(1+electronVelocity.getZ()))*(LaserFrequency2*electronEnergy*(1+electronVelocity.getZ()))))*std::sin(phase2)
        )
        ,
        ((momentumXPrime)/electronMass)*properTime+
        ((electronMass*fieldParameter1)/(LaserFrequency1*((electronEnergy))*(1-electronVelocity.getZ())))*std::sin(phase1)+
        ((electronMass*fieldParameter1)/(LaserFrequency1*((electronEnergy))*(1+electronVelocity.getZ())))*std::sin(phase2)
        ,
        -((electronMass*fieldParameter1)/(LaserFrequency1*(electronEnergy))*(1-electronVelocity.getZ()))*std::cos(phase1)-
        ((electronMass*fieldParameter2)/(LaserFrequency2*(electronEnergy))*(1+electronVelocity.getZ()))*std::cos(phase2)
        ,
        ((momentumZPrime)/electronMass)*properTime+
        ((2*electronMass*electronMass*fieldParameter1*fieldParameter2*LaserFrequency1)/((-2*LaserFrequency1*electronEnergy*electronVelocity.getZ())*(-2*LaserFrequency1*electronEnergy*electronVelocity.getZ())))*std::sin(phase1-phase2)+
        ((momentumXPrime)*LaserFrequency1*(
            ((electronMass*fieldParameter1)/((LaserFrequency1*electronEnergy*(1-electronVelocity.getZ()))*(LaserFrequency1*((electronEnergy))*(1-electronVelocity.getZ()))))*std::sin(phase1)-
            ((electronMass*fieldParameter2)/((LaserFrequency2*electronEnergy*(1+electronVelocity.getZ()))*(LaserFrequency2*((electronEnergy))*(1+electronVelocity.getZ()))))*std::sin(phase2)
        ))
    );
    this->electronStateFinal = ParticleState(electronLorentzMomentum,electronCoordinate);
}

ElectronTrajectoryByAnalysisInATimeSlice::~ElectronTrajectoryByAnalysisInATimeSlice() {
}


