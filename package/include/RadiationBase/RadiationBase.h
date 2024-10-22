#include <complex>
#include <utility>
#include <string>

#pragma once

template <typename T>
class RadiationBase
{
    private:
        double energyInitial;
        double energyLoss;
        T radiationProbabilityAmplitude;
    public:
        RadiationBase();
        RadiationBase(double energyInitial,std::pair<std::string,double> param);
        void setEnergyInitial(double energyInitial);
        void setEnergyLoss(double energyLoss);
        void setEnergyFinal(double energyFinal);
        void setEnergyLossRate(double lossRate);
        void setEnergyRetentionRate(double retentionRate);
        virtual void calculateRadiationProbabilityAmplitude()=0;
        double getEnergyInitial();
        double getEnergyLoss();
        double getEnergyFinal();
        T getRadiationProbabilityAmplitude();
        double getRadiationProbability();
};