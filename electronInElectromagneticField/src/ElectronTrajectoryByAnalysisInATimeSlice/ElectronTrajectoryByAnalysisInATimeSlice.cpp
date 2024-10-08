#include "../../include/ElectronTrajectoryByAnalysisInATimeSlice/ElectronTrajectoryByAnalysisInATimeSlice.h"
#include <iostream> 

ElectronTrajectoryByAnalysisInATimeSlice::ElectronTrajectoryByAnalysisInATimeSlice() {
    this->properTimeSlice = 0;
    this->electronStateInitial = ParticleState();
    this->electronStateFinal = ParticleState();
    double electronMass = this->electron.getRestMass();
    LaserField laserField1 = this->getLaserField1();
    LaserField laserField2 = this->getLaserField2();
    double fieldParameter1 = laserField1.getFieldParameter();
    double fieldParameter2 = laserField2.getFieldParameter();
    double LaserFrequency1 = laserField1.getLaserFrequency();
    double LaserFrequency2 = laserField2.getLaserFrequency();
    Dimension3Vector<double> electronVelocity = this->electronStateInitial.getParticleVelocity();
    Dimension3Vector<double> electronMomentum = this->electronStateInitial.getParticleMomentum();
    double electronEnergy = this->electronStateInitial.getParticleEnergy();
    double momentumXPrime = electronMomentum.getX();
    double momentumYPrime = electronMomentum.getY();
    double momentumZPrime = electronMomentum.getZ();
    double electronVelocityZ = electronVelocity.getZ();
    double electronVelocityX = electronVelocity.getX();
    double omega1 = LaserFrequency1*(1-electronVelocityZ);
    double omega2 = LaserFrequency2*(1+electronVelocityZ);
    double deltaOmega = omega1-omega2;
    double timeCofficient1 = (omega1*electronEnergy)/electronMass;
    double timeCofficient2 = (omega2*electronEnergy)/electronMass;
    double deltaTimeCofficient = timeCofficient1-timeCofficient2;
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

void ElectronTrajectoryByAnalysisInATimeSlice::setProperTimeSlice(double properTimeSlice) {
    this->properTimeSlice = properTimeSlice;
}

void ElectronTrajectoryByAnalysisInATimeSlice::calculateElectronStateFinal() {
    double properTime = this->properTimeSlice;
    double phase1 = timeCofficient1*properTime;
    double phase2 = timeCofficient2*properTime;
    double deltaPhase = deltaTimeCofficient*properTime;
    double cosPhase1 = std::cos(phase1);
    double cosPhase2 = std::cos(phase2);
    double sinPhase1 = std::sin(phase1);
    double sinPhase2 = std::sin(phase2);
    double cosDeltaPhase = std::cos(deltaPhase);
    double sinDeltaPhase = std::sin(deltaPhase);
    LorentzVector<double> electronLorentzMomentumFinal = LorentzVector<double>(
        electronEnergy+
        momentumXPrime*LaserFrequency1*(
            (fieldParameter1/timeCofficient1)*cosPhase1+
            (fieldParameter2/timeCofficient2)*cosPhase2
        )
        ,
        momentumXPrime+
        fieldParameter1*electronMass*cosPhase1+fieldParameter2*electronMass*cosPhase2
        ,
        momentumYPrime+
        fieldParameter1*electronMass*sinPhase1+fieldParameter2*electronMass*sinPhase2
        ,
        momentumZPrime+
        momentumXPrime*LaserFrequency1*(
            (fieldParameter1/timeCofficient1)*cosPhase1-
            (fieldParameter2/timeCofficient2)*cosPhase2
        )+
        ((2*electronMass*fieldParameter1*fieldParameter2*LaserFrequency1)/deltaTimeCofficient)*cosDeltaPhase
    );
    /*LorentzVector<double> electronCoordinate = LorentzVector<double>(
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
    );*/
    LorentzVector<double> electronCoordinateFinal = LorentzVector<double>(
        ((electronEnergy)/electronMass)*properTime+
        momentumXPrime*LaserFrequency1*(
            ((fieldParameter1)/(timeCofficient1*timeCofficient1*electronEnergy))*sinPhase1+
            ((fieldParameter2)/(timeCofficient2*timeCofficient2*electronEnergy))*sinPhase2
        )
        ,
        ((momentumXPrime)/electronMass)*properTime+
        ((fieldParameter1)/(timeCofficient1))*sinPhase1+
        ((fieldParameter2)/(timeCofficient2))*sinPhase2
        ,
        ((momentumYPrime)/electronMass)*properTime-
        ((fieldParameter1)/(timeCofficient1))*cosPhase1-
        ((fieldParameter2)/(timeCofficient2))*cosPhase2
        ,
        ((momentumZPrime)/electronMass)*properTime+
        ((momentumXPrime)*LaserFrequency1*(
            ((fieldParameter1)/(timeCofficient1*timeCofficient1*electronEnergy))*sinPhase1-
            ((fieldParameter2)/(timeCofficient2*timeCofficient2*electronEnergy))*sinPhase2
        ))+
        ((2*fieldParameter1*fieldParameter2*LaserFrequency1)/(deltaTimeCofficient*deltaTimeCofficient*electronEnergy))*sinDeltaPhase
    );
    this->electronStateFinal.changeParticleLorentzCoordinate(electronCoordinateFinal);
    this->electronStateFinal.changeParticleLorentzMomentum(electronLorentzMomentumFinal);
}

ElectronTrajectoryByAnalysisInATimeSlice::~ElectronTrajectoryByAnalysisInATimeSlice() {
}


