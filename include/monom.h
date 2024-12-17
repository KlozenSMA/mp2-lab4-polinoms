// ����� ��� ��������� ������ (double �����������, ����� ��������� �������)
#include <cassert>
//#include "list.h"
#include <iostream>
class monom
{
    private:
    double co;
    int pow;
    public:
    //конструкторы и co
    monom(double co,int pow);
    monom(std::string mourice);
    ~monom();

    //работа с аргументами
    double GetCo(const monom& eh);
    int GetPowx(const monom& eh);
    int GetPowy(const monom& eh);
    int GetPowz(const monom& eh);

    //работа с мономом
    bool operator<(const monom& eh);
    bool operator>(const monom& eh);
    bool operator==(const monom& eh);
    bool operator!=(const monom& eh);
};