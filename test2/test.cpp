#include "../package/include/Dimension3Vector/Dimension3Vector.h"
#include "../package/include/LorentzVector/LorentzVector.h"
#include "../package/include/ParticleState/ParticleState.h"
#include "../electronInElectromagneticField/include/NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum/NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum.h"
#include "../electronInElectromagneticField/include/ElectronTrajectoryByAnalysisInATimeSlice/ElectronTrajectoryByAnalysisInATimeSlice.h"
#include <iostream>
#include <fstream>
#include <chrono>

/*int main() {
    double fieldParameter1 = 0.3;
    double fieldParameter2 = 2.0;
    double laserFrequency = 1.55;
    double electronMass = 510998.9461;
    double reducedMass = electronMass*std::sqrt(1+fieldParameter1*fieldParameter1+fieldParameter2*fieldParameter2);
    double energyInitial = 30*reducedMass;
    double momentumXPrimdje = 0;
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
}*/

int main(){
    double omega = 1.55;
    double fieldParameter1 = 50;
    double fieldParameter2 = 1;
    double electronMass = 511000;
    double reducedMass = electronMass*std::sqrt(1+fieldParameter1*fieldParameter1+fieldParameter2*fieldParameter2);
    double energyInit = 250*electronMass;
    std::cout<<"energyInit: "<<energyInit<<std::endl;
    double momentumXInit = ((electronMass*fieldParameter1)+(electronMass*fieldParameter2));
    double momentumZInit = std::sqrt((energyInit*energyInit)-(electronMass*electronMass)-(momentumXInit*momentumXInit));
    double momentumZPrime = std::sqrt((energyInit*energyInit)-(reducedMass*reducedMass));
    std::cout<<"momentumZInit: "<<momentumZInit<<std::endl;
    ParticleState particleStateInitial(LorentzVector<double>(energyInit,momentumXInit,0,momentumZInit));
    std::cout<<"particleStateInitialMass: "<<particleStateInitial.getParticleMass()<<std::endl;
    double timeBegin = 0;
    double timeInterval = (M_PI*2)/(omega*(1-momentumZPrime/energyInit));
    std::cout<<"timeInterval: "<<timeInterval<<std::endl;
    double stepLength = timeInterval/20000.0;
    std::cout<<"stepLength: "<<stepLength<<std::endl;
    //time start
    auto start = std::chrono::high_resolution_clock::now();
    //numerical solution of molecule in counterpropagating laser*
    std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> electricField = [omega,fieldParameter1,fieldParameter2](Dimension3Vector<double> y,Dimension3Vector<double> dydt,double t)->Dimension3Vector<double>{  
        Dimension3Vector<double> relatedElectricField1(-fieldParameter1*std::sin(omega*t-omega*y.getZ()),fieldParameter1*std::cos(omega*t-omega*y.getZ()),0);
        Dimension3Vector<double> relatedElectricField2(-fieldParameter2*std::sin(omega*t+omega*y.getZ()),fieldParameter2*std::cos(omega*t+omega*y.getZ()),0);
        return relatedElectricField1+relatedElectricField2;
    };
    std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> magneticField = [omega,fieldParameter1,fieldParameter2](Dimension3Vector<double> y,Dimension3Vector<double> dydt,double t)->Dimension3Vector<double>{  
        Dimension3Vector<double> relatedMagneticField1(0,0,fieldParameter1*std::cos(omega*t-omega*y.getZ()));
        Dimension3Vector<double> relatedMagneticField2(0,0,fieldParameter2*std::cos(omega*t+omega*y.getZ()));
        return relatedMagneticField1+relatedMagneticField2;
    };
    NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum numericalSolutionOfMoleculeInCounterpropagatingLaser(
        timeBegin, timeInterval, stepLength, electricField, magneticField, particleStateInitial);
    numericalSolutionOfMoleculeInCounterpropagatingLaser.solve();
    //time end
    auto end = std::chrono::high_resolution_clock::now();
    //output time by ms
    std::cout<<"Time: "<<std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()<<"ms"<<std::endl;
    auto fileTime = std::chrono::system_clock::now();
    std::fstream file;
    file.open("electronVelocity.txt",std::ios::out);
    std::vector<Dimension3Vector<double>> electronVelocity = numericalSolutionOfMoleculeInCounterpropagatingLaser.getVelocityList();
    for(int i=0;i<electronVelocity.size();i++){
        file<<electronVelocity[i].getX()<<"\t"<<electronVelocity[i].getY()<<"\t"<<electronVelocity[i].getZ()<<std::endl;
    }
    file.close();
    auto fileTime1 = std::chrono::system_clock::now();
    std::cout<<"Time: "<<std::chrono::duration_cast<std::chrono::milliseconds>(fileTime1-fileTime).count()<<"ms"<<std::endl;
    return 0;
}