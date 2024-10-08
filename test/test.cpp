#include "../package/include/Dimension3Vector/Dimension3Vector.h"
#include "../package/include/LorentzVector/LorentzVector.h"
#include "../electronInElectromagneticField/include/ElectronTrajectoryByAnalysisInATimeSlice/ElectronTrajectoryByAnalysisInATimeSlice.h"
#include <iostream>
#include <chrono>

int main() {
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
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    ElectronTrajectoryByAnalysisInATimeSlice electronTrajectoryByAnalysisInATimeSlice(0,particleStateInitial,laserField1,laserField2);
    for(double properTimeSlice=0;properTimeSlice<100;properTimeSlice+=0.001) {
        electronTrajectoryByAnalysisInATimeSlice.setProperTimeSlice(properTimeSlice);
        electronTrajectoryByAnalysisInATimeSlice.calculateElectronStateFinal();
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << "ms" << std::endl;
    return 0;
}