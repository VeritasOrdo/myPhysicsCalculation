#include "../BasicMassageOfElectronInElectromagneticField/BasicMassageOfElectronInElectromagneticField.h"
#include "../../../package/include/LorentzVector/LorentzVector.h"
#include "../../../package/include/ParticleState/ParticleState.h"

class ElectronTrajectoryByAnalysisInATimeSlice : public BasicMassageOfElectronInElectromagneticField{
    private:
        double properTimeSlice;
        const Particle electron = Particle("electron");
        ParticleState electronStateInitial;
        ParticleState electronStateFinal;
    public:
        ElectronTrajectoryByAnalysisInATimeSlice();
        ElectronTrajectoryByAnalysisInATimeSlice(double properTimeSlice, ParticleState electronStateInitial, LaserField laserField1, LaserField laserField2);
        ParticleState getElectronStateInitial();
        ParticleState getElectronStateFinal();
        void calculateElectronStateFinal();
        double getProperTimeSlice();
        ~ElectronTrajectoryByAnalysisInATimeSlice();
};