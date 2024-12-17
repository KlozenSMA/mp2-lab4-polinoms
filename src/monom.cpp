#include "monom.h"

monom::monom(double _co,int pow)
{
    co = _co;
}
monom::monom(std::string mourice)
{
    std::string cost;
    std::string powst;
    int i = 0;
    if (&mourice[0] == "x" || &mourice[0] == ".")
    {
        cost = "1";
    }
    else
    {
        while (&mourice[i] == "." || &mourice[i] == "0" || &mourice[i] == "1" || &mourice[i] == "2" || &mourice[i] == "3" || &mourice[i] == "4" || &mourice[i] == "5" || &mourice[i] == "6" || &mourice[i] == "7" || &mourice[i] == "8" || &mourice[i] == "9")
        {
            cost += mourice[i];
            i++;
        }
    }
    powst += mourice[i+1];
    powst += mourice[i+3];
    powst += mourice[i+5];
    co = std::stod(cost);
    pow = std::stoi(powst);
}
monom::~monom()
{}

double monom::GetCo(const monom& eh)
{
    return co;
}
int monom::GetPowx(const monom& eh)
{
    return pow / 100;
}
int monom::GetPowy(const monom& eh)
{
    return (pow / 10) % 10;
}
int monom::GetPowz(const monom& eh)
{
    return pow % 10;
}
bool monom::operator==(const monom& eh)
{
    if (pow == eh.pow && co == eh.co)
    {
        return true;
    }
    else {return false;}
}
bool monom::operator!=(const monom& eh)
{
    if (pow == eh.pow && co == eh.co)
    {
        return false;
    }
    else {return true;}
}
bool monom::operator>(const monom& eh)
{
    if (pow == eh.pow && co > eh.co)
    {
        return true;
    }
    else {return false;}
}
bool monom::operator<(const monom& eh)
{
    if (pow == eh.pow && co < eh.co)
    {
        return true;
    }
    else {return false;}
}