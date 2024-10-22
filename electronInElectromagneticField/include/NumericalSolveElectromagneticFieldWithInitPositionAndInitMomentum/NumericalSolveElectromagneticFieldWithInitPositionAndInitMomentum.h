#include "../../package/include/NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum/NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum.h"

class NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum{
    private:
        double timeBegin; 
        double timeEnd; 
        double stepLength;
        double relativeError=1e-6;
        double absoluteError=1e-6;
        ParticleState particleStateInitial;
        std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> electricField;
        std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> magneticField;
        NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum solveTheMotionEquation;
    public:
        NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum();
        NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum(double timeBegin, double timeEnd, double stepLength, std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> electricField, std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> magneticField, ParticleState particleStateInitial);
        NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum(double timeBegin, double timeEnd, double stepLength, std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> electricField, std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> magneticField, ParticleState particleStateInitial, double relativeError, double absoluteError);
        ParticleState getParticleStateInitial();
        void setParticleStateInitial(ParticleState particleStateInitial);
        std::vector<Dimension3Vector<double>> getPositionList();
        std::vector<Dimension3Vector<double>> getMomentumList();
        std::vector<Dimension3Vector<double>> getVelocityList();
        std::vector<double> getEnergyList();
        std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> getElectricField();
        std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> getMagneticField();
        double getMass();
        void solve();
        ~NumericalSolveElectromagneticFieldWithInitPositionAndInitMomentum();
};