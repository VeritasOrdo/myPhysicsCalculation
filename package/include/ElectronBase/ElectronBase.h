#include "../Spin/Spin.h"
#include "../Dimension3Vector/Dimension3Vector.h"

class ElectronBase
{
    private:
        Spin spin;
        const double electronMass = 510998.9461;
        double energy;
        Dimension3Vector<double> momentum;
        Dimension3Vector<double> position;
    public:
        ElectronBase(double energy, Dimension3Vector<double> momentum);
        ElectronBase(double energy, Dimension3Vector<double> momentum, Dimension3Vector<double> position);
        ElectronBase(double energy, Dimension3Vector<double> momentum, Dimension3Vector<double> position, Spin spin);
        double getEnergy();
        Dimension3Vector<double> getMomentum();
        Dimension3Vector<double> getPosition();
        Spin getSpin();
        double getMass();
        ~ElectronBase();
};