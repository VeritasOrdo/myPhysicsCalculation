#include "../../include/ParticleState/ParticleState.h"

ParticleState::ParticleState() {
    this->particleLorentzMomentum = LorentzVector<double>();
    this->particleLorentzCoordinate = LorentzVector<double>();
    this->particleMomentum = Dimension3Vector<double>();
    this->particleVelocity = Dimension3Vector<double>();
    this->particleCoordinate = Dimension3Vector<double>();
    this->particleEnergy = this->particleLorentzMomentum[0];
    this->particleTime = this->particleLorentzCoordinate[0];
}

ParticleState::ParticleState(LorentzVector<double> particleLorentzMomentum) {
    this->particleLorentzMomentum = particleLorentzMomentum;
    this->particleLorentzCoordinate = LorentzVector<double>();
    this->particleMomentum = Dimension3Vector<double>(particleLorentzMomentum[1],particleLorentzMomentum[2],particleLorentzMomentum[3]);
    this->particleVelocity = Dimension3Vector<double>(particleLorentzMomentum[1]/particleLorentzMomentum[0],particleLorentzMomentum[2]/particleLorentzMomentum[0],particleLorentzMomentum[3]/particleLorentzMomentum[0]);
    this->particleCoordinate = Dimension3Vector<double>();
    this->particleEnergy = particleLorentzMomentum[0];
    this->particleTime = this->particleLorentzCoordinate[0];
}   

ParticleState::ParticleState(LorentzVector<double> particleLorentzMomentum,LorentzVector<double> particleLorentzCoordinate) {
    this->particleLorentzMomentum = particleLorentzMomentum;
    this->particleLorentzCoordinate = particleLorentzCoordinate;
    this->particleMomentum = Dimension3Vector<double>(particleLorentzMomentum[1],particleLorentzMomentum[2],particleLorentzMomentum[3]);
    this->particleVelocity = Dimension3Vector<double>(particleLorentzMomentum[1]/particleLorentzMomentum[0],particleLorentzMomentum[2]/particleLorentzMomentum[0],particleLorentzMomentum[3]/particleLorentzMomentum[0]);
    this->particleCoordinate = Dimension3Vector<double>(particleLorentzCoordinate[1],particleLorentzCoordinate[2],particleLorentzCoordinate[3]);
    this->particleEnergy = particleLorentzMomentum[0];
    this->particleTime = particleLorentzCoordinate[0];
}

void ParticleState::changeParticleLorentzMomentum(LorentzVector<double> particleLorentzMomentum) {
    this->particleLorentzMomentum = particleLorentzMomentum;
    this->particleMomentum = Dimension3Vector<double>(particleLorentzMomentum[1],particleLorentzMomentum[2],particleLorentzMomentum[3]);
    this->particleVelocity = Dimension3Vector<double>(particleLorentzMomentum[1]/particleLorentzMomentum[0],particleLorentzMomentum[2]/particleLorentzMomentum[0],particleLorentzMomentum[3]/particleLorentzMomentum[0]);
    this->particleEnergy = particleLorentzMomentum[0];
}

void ParticleState::changeParticleLorentzCoordinate(LorentzVector<double> particleLorentzCoordinate) {
    this->particleLorentzCoordinate = particleLorentzCoordinate;
    this->particleCoordinate = Dimension3Vector<double>(particleLorentzCoordinate[1],particleLorentzCoordinate[2],particleLorentzCoordinate[3]);
    this->particleTime = particleLorentzCoordinate[0];
}

LorentzVector<double> ParticleState::getParticleLorentzMomentum() {
    return this->particleLorentzMomentum;
}

LorentzVector<double> ParticleState::getParticleLorentzCoordinate() {
    return this->particleLorentzCoordinate;
}

Dimension3Vector<double> ParticleState::getParticleMomentum() {
    return this->particleMomentum;
}

Dimension3Vector<double> ParticleState::getParticleVelocity() {
    return this->particleVelocity;
}

Dimension3Vector<double> ParticleState::getParticleCoordinate() {
    return this->particleCoordinate;
}

double ParticleState::getParticleEnergy() {
    return this->particleEnergy;
}

double ParticleState::getParticleMass() {
    return this->particleEnergy;
}

ParticleState::~ParticleState() {
}
    