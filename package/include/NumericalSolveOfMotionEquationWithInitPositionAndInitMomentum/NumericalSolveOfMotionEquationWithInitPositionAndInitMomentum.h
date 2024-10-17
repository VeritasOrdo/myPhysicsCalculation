#include "../NumericalSolveOfMotionEquationBase/NumericalSolveOfMotionEquationBase.h"
#include "../ParticleState/ParticleState.h"

class NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum : public NumericalSolveOfMotionEquationBase<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> {
    private:
        ParticleState particleStateInitial;
        std::vector<Dimension3Vector<double>> positionList;
        std::vector<Dimension3Vector<double>> momentumList;
        std::vector<Dimension3Vector<double>> velocityList;
        std::vector<double> energyList;
        double relativeError = 1e-6;
        double absoluteError = 1e-6;
    public:
        NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum();
        NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum(double timeBegin, double timeEnd, double stepLength, std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> motionEquation, ParticleState particleStateInitial);
        NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum(double timeBegin, double timeEnd, double stepLength, std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> motionEquation, ParticleState particleStateInitial, double relativeError, double absoluteError);
        ParticleState getParticleStateInitial();
        void setParticleStateInitial(ParticleState particleStateInitial);
        std::vector<Dimension3Vector<double>> getPositionList();
        std::vector<Dimension3Vector<double>> getMomentumList();
        std::vector<Dimension3Vector<double>> getVelocityList();
        std::vector<double> getEnergyList();
        std::function<Dimension3Vector<double>(Dimension3Vector<double>,Dimension3Vector<double>,double)> getMotionEquation();
        double getMass();
        void solve();
        ~NumericalSolveOfMotionEquationWithInitPositionAndInitMomentum();
};