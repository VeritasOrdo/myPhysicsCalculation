#include "../package/include/Dimension3Vector/Dimension3Vector.h"
#include "../package/include/LorentzVector/LorentzVector.h"
#include "../electronInElectromagneticField/include/ElectronTrajectoryByAnalysisInATimeSlice/ElectronTrajectoryByAnalysisInATimeSlice.h"
#include <iostream>

int main() {
    double propertime = 3;
    double fieldParameter1 = 0.3;
    double fieldParameter2 = 2.0;
    double laserFrequency = 1.55;
    double electronMass = 510998.9461;
    double reducedMass = electronMass*std::sqrt(1+fieldParameter1*fieldParameter1+fieldParameter2*fieldParameter2);
    double energyInitial = 30*reducedMass;
    double momentumXPrime = 0;
    double momentumZPrime = std::sqrt(energyInitial*energyInitial-reducedMass*reducedMass-momentumXPrime*momentumXPrime);
    LorentzVector<double> momentumInitial(energyInitial,momentumXPrime,0,momentumZPrime);
    LaserField laserField1(fieldParameter1,laserFrequency);
    LaserField laserField2(fieldParameter2,laserFrequency);
    ParticleState particleStateInitial(momentumInitial);
    ElectronTrajectoryByAnalysisInATimeSlice electronTrajectoryByAnalysisInATimeSlice(propertime,particleStateInitial,laserField1,laserField2);
    electronTrajectoryByAnalysisInATimeSlice.calculateElectronStateFinal(); 
    std::cout << "electronStateFinal: " << std::endl;
    std::cout << "energy: " << electronTrajectoryByAnalysisInATimeSlice.getElectronStateFinal().getParticleEnergy() << '\t';
    std::cout << "velocityX: " << electronTrajectoryByAnalysisInATimeSlice.getElectronStateFinal().getParticleVelocity().getX() << '\t';
    std::cout << "velocityY: " << electronTrajectoryByAnalysisInATimeSlice.getElectronStateFinal().getParticleVelocity().getY() << '\t';
    std::cout << "velocityZ: " << electronTrajectoryByAnalysisInATimeSlice.getElectronStateFinal().getParticleVelocity().getZ() << std::endl;
}