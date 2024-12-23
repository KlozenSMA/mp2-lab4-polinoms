// ����� ��� ��������� ������ (double �����������, ����� ��������� �������)
#include <iostream>
class monom
{
    protected:
    double co;
    int pow;
    public:
    //конструкторы и co
    monom(double co,int pow);
    monom(std::string mourice);
    ~monom();

    //работа с аргументами
    double GetCo();
    int GetFullPow();
    int GetPowx();
    int GetPowy();
    int GetPowz();

    //работа с мономом
    bool operator<(const monom& eh);
    bool operator>(const monom& eh);
    bool operator==(const monom& eh);
    bool operator!=(const monom& eh);

    //мы очень спешим
    // friend ostream& operator<<(ostream &ostrich, const monom& m);
    // friend istream& operator<<(istream &istrich, const monom& m);
};