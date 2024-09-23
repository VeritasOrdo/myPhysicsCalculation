#include "../package/include/Dimension3Vector/Dimension3Vector.h"
#include "../package/include/LorentzVector/LorentzVector.h"
#include "../package/include/ElectronBase/ElectronBase.h"
#include <iostream>

int main() {
    /*LorentzVector<double> v1(1, 2, 3, 4);
    LorentzVector<double> v2(5, 6, 7, 8);
    LorentzVector<double> v3 = v1 + v2;
    std::cout << v3 << std::endl;*/
    /*Dimension3Vector<double> v1(1, 2, 3);
    Dimension3Vector<double> v2(4, 5, 6);
    Dimension3Vector<double> v3 = v1 + v2;
    std::cout << v3 << std::endl;*/
    ElectronBase electron(1, Dimension3Vector<double>(1, 2, 3));
    std::cout << electron.getEnergy() << std::endl;
    std::cout << electron.getMomentum() << std::endl;
    std::cout << electron.getPosition() << std::endl;
    std::cout << electron.getSpin().getSpinValue() << std::endl;
    return 0;
}