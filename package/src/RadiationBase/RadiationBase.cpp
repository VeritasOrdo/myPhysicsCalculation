#include "../../include/RadiationBase/RadiationBase.h"

template <typename T>
RadiationBase<T>::RadiationBase()
{
    energyInitial = 0;
    energyLoss = 0;
    radiationProbabilityAmplitude = 0;
}

template <typename T>
RadiationBase<T>::RadiationBase(double energyInitial,std::pair<std::string,double> param)
{
    energyInitial = energyInitial;
    if(param.first=="energyLoss")
    {
        energyLoss = param.second;
    }
    else if(param.first=="energyFinal")
    {
        energyLoss = energyInitial-param.second;
    }
    else if(param.first=="lossRate")
    {
        energyLoss = energyInitial*param.second;
    }
    else if(param.first=="retentionRate")
    {
        energyLoss = energyInitial*(1-param.second);
    }
    else
    {
        throw std::invalid_argument("Invalid parameter name");
    }
}

template <typename T>
void RadiationBase<T>::setEnergyInitial(double energyInitial)
{
    this->energyInitial = energyInitial;
}

template <typename T>
void RadiationBase<T>::setEnergyLoss(double energyLoss)
{
    this->energyLoss = energyLoss;
}

template <typename T>
void RadiationBase<T>::setEnergyLossRate(double lossRate)
{
    this->energyLoss = energyInitial*lossRate;
}

template <typename T>
void RadiationBase<T>::setEnergyRetentionRate(double retentionRate)
{
    this->energyLoss = energyInitial*(1-retentionRate);
}

template <typename T>
void RadiationBase<T>::setEnergyFinal(double energyFinal)
{
    this->energyLoss = energyInitial-energyFinal;
}

template <typename T>
double RadiationBase<T>::getEnergyInitial()
{
    return energyInitial;
}

template <typename T>
double RadiationBase<T>::getEnergyLoss()
{
    return energyLoss;
}

template <typename T>
double RadiationBase<T>::getEnergyFinal()
{
    return energyInitial-energyLoss;
}

template <typename T>
T RadiationBase<T>::getRadiationProbabilityAmplitude()
{
    return radiationProbabilityAmplitude;
}

template <typename T>
double RadiationBase<T>::getRadiationProbability()
{
    return std::norm(radiationProbabilityAmplitude);
}

template class RadiationBase<std::complex<double>>;
template class RadiationBase<double>;