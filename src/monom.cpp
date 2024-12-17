#include "monom.h"

monom::monom(double _co,int pow)
{
    if (pow < 0)
    {
        throw "well, in this universe power cannot be less than zero";
    }
    co = _co;
    int xpow = pow / 100;
    int ypow = (pow / 10) % 10;
    int zpow = pow % 10;
}
monom::monom(std::string mourice)
{
    std::string cost;
    std::string powst;
    int i;
    while (assert(std::stoi(&mourice[i])))
    {}
}