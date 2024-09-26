#include "../Spin/Spin.h"
#include <string>

#pragma once

class Particle
{
    private:
        Spin spin;
        double restMass;
    public:
        Particle();
        Particle(Spin spin,double restMass);
        Particle(std::string ParticleName);
        Particle(std::string ParticleName,Spin spin);
        Particle(int ParticleID);
        Particle operator=(const Particle &particle);
        Spin getSpin() const;
        double getRestMass() const;
        ~Particle();
};
