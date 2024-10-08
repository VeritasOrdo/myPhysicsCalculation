#include "../LorentzVector/LorentzVector.h"
#include "../Dimension3Vector/Dimension3Vector.h"

#pragma once

class ParticleState {
    private:
        LorentzVector<double> particleLorentzMomentum;
        LorentzVector<double> particleLorentzCoordinate;
        Dimension3Vector<double> particleMomentum;
        Dimension3Vector<double> particleVelocity;
        Dimension3Vector<double> particleCoordinate;
        double particleEnergy;
        double particleTime;
    public:
        ParticleState();
        ParticleState(LorentzVector<double> particleLorentzMomentum);
        ParticleState(LorentzVector<double> particleLorentzMomentum,LorentzVector<double> particleLorentzCoordinate);
        LorentzVector<double> getParticleLorentzMomentum();
        LorentzVector<double> getParticleLorentzCoordinate();
        Dimension3Vector<double> getParticleMomentum();
        Dimension3Vector<double> getParticleVelocity();
        Dimension3Vector<double> getParticleCoordinate();
        void changeParticleLorentzMomentum(LorentzVector<double> particleLorentzMomentum);
        void changeParticleLorentzCoordinate(LorentzVector<double> particleLorentzCoordinate);
        double getParticleEnergy();
        double getParticleMass();
        ~ParticleState();
};
