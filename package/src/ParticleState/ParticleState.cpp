#include "../../include/ParticleState/ParticleState.h"

ParticleState::ParticleState() {
    this->particleLorentzMomentum = LorentzVector<double>();
    this->particleLorentzCoordinate = LorentzVector<double>();
}

ParticleState::ParticleState(LorentzVector<double> particleLorentzMomentum) {
    this->particleLorentzMomentum = particleLorentzMomentum;
    this->particleLorentzCoordinate = LorentzVector<double>();
}   

ParticleState::ParticleState(LorentzVector<double> particleLorentzMomentum,LorentzVector<double> particleLorentzCoordinate) {
    this->particleLorentzMomentum = particleLorentzMomentum;
    this->particleLorentzCoordinate = particleLorentzCoordinate;
}

ParticleState::ParticleState(Particle particle,Dimension3Vector<double> particleMomentum) {
    this->particleLorentzMomentum = LorentzVector<double>(std::sqrt(particleMomentum*particleMomentum+particle.getRestMass()*particle.getRestMass()),particleMomentum.getX(),particleMomentum.getY(),particleMomentum.getZ());
    this->particleLorentzCoordinate = LorentzVector<double>();
}

ParticleState::ParticleState(Particle particle,Dimension3Vector<double> particleMomentum,LorentzVector<double> particleLorentzCoordinate) {
    this->particleLorentzMomentum = LorentzVector<double>(std::sqrt(particleMomentum*particleMomentum+particle.getRestMass()*particle.getRestMass()),particleMomentum.getX(),particleMomentum.getY(),particleMomentum.getZ());
    this->particleLorentzCoordinate = particleLorentzCoordinate;
}

void ParticleState::changeParticleLorentzMomentum(LorentzVector<double> particleLorentzMomentum) {
    this->particleLorentzMomentum = particleLorentzMomentum;
}

void ParticleState::changeParticleLorentzCoordinate(LorentzVector<double> particleLorentzCoordinate) {
    this->particleLorentzCoordinate = particleLorentzCoordinate;
}

LorentzVector<double> ParticleState::getParticleLorentzMomentum() {
    return this->particleLorentzMomentum;
}

LorentzVector<double> ParticleState::getParticleLorentzCoordinate() {
    return this->particleLorentzCoordinate;
}

Dimension3Vector<double> ParticleState::getParticleMomentum() {
    return Dimension3Vector<double>(this->particleLorentzMomentum.getX(),this->particleLorentzMomentum.getY(),this->particleLorentzMomentum.getZ());
}

Dimension3Vector<double> ParticleState::getParticleVelocity() {
    return Dimension3Vector<double>(this->particleLorentzMomentum.getX()/this->particleLorentzMomentum.getT(),this->particleLorentzMomentum.getY()/this->particleLorentzMomentum.getT(),this->particleLorentzMomentum.getZ()/this->particleLorentzMomentum.getT());
}

Dimension3Vector<double> ParticleState::getParticleCoordinate() {
    return Dimension3Vector<double>(this->particleLorentzCoordinate.getX(),this->particleLorentzCoordinate.getY(),this->particleLorentzCoordinate.getZ());
}

double ParticleState::getParticleEnergy() {
    return this->particleLorentzMomentum.getT();
}

double ParticleState::getParticleMass() {
    return std::sqrt(this->particleLorentzMomentum*this->particleLorentzMomentum);
}

ParticleState::~ParticleState() {
}
    