#include "../BasicMassageOfElectronInElectromagneticField/BasicMassageOfElectronInElectromagneticField.h"
#include "../../../package/include/LorentzVector/LorentzVector.h"
#include "../../../package/include/ParticleState/ParticleState.h"

class ElectronTrajectoryByAnalysisInATimeSlice : public BasicMassageOfElectronInElectromagneticField{
    private:
        double properTimeSlice;
        const Particle electron = Particle("electron");
        ParticleState electronStateInitial;
        ParticleState electronStateFinal;
        //Intermediate variables
        double timeCofficient1;
        double timeCofficient2;
        double deltaTimeCofficient;
        double electronEnergy;
        double momentumXPrime;
        double LaserFrequency1;
        double fieldParameter1;
        double fieldParameter2;
        double momentumYPrime;
        double momentumZPrime;
        double electronMass;
    public:
        ElectronTrajectoryByAnalysisInATimeSlice();
        ElectronTrajectoryByAnalysisInATimeSlice(double properTimeSlice, ParticleState electronStateInitial, LaserField laserField1, LaserField laserField2);
        ParticleState getElectronStateInitial();
        ParticleState getElectronStateFinal();
        void calculateElectronStateFinal();
        void setProperTimeSlice(double properTimeSlice);
        double getProperTimeSlice();
        ~ElectronTrajectoryByAnalysisInATimeSlice();
};