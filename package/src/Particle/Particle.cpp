#include "../../include/Particle/Particle.h"

Particle::Particle() {
    this->spin = Spin();
    this->restMass = 0;
}

Particle::Particle(Spin spin,double restMass) {
    this->spin = spin;
    this->restMass = restMass;
}

Particle::Particle(std::string ParticleName) {
    if(ParticleName=="electron"){
        this->spin = Spin(0.5);
        this->restMass = 510998.9461;
    }
}

Particle::Particle(std::string ParticleName,Spin spin) {
    if(ParticleName=="electron"){
        this->spin = spin;
        this->restMass = 510998.9461;
    }
}

Particle::Particle(int ParticleID) {
    if(ParticleID==11){
        this->spin = Spin(0.5);
        this->restMass = 510998.9461;
    }
}

Particle Particle::operator=(const Particle &particle) {
    this->spin = particle.spin;
    this->restMass = particle.restMass;
    return *this;
}

Spin Particle::getSpin() const {
    return this->spin;
}

double Particle::getRestMass() const {
    return this->restMass;
}

Particle::~Particle() {
}

