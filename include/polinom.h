// ����� ������� - ������������� ����������� ������ �������
// ������������ �������� ������, ������� ������, �������� ������,  
// ����� ������, �������� ���������(������� ������������� �������), 
// ��������� ���������

#include "monom.h"
#include "list.h"

class polynom : private List<monom>
{
    using List<monom>::first;
    using List<monom>::last;
public:
// конструктор
polynom();
// конструктор копирования
polynom(const polynom& p);
//деструктор
~polynom();
//функция упорядочивания
void Sortishe(const polynom& p);
//всякие операторы
using List<monom>::operator=;
bool operator==(const polynom& ah);
bool operator!=(const polynom& ah);
polynom operator+(const polynom& p);
polynom operator+(const monom& m);
//не совсем уверен нужна ли эта штука
// polynom operator-(const polynom& p);
// polynom operator-(const monom& m);
polynom operator*(double val);
polynom operator*(const monom& p);
polynom operator*(const polynom& p);
//мы очень спешим
// friend ostream& operator<<(ostream &ostrich, const polynom& m);
// friend istream& operator<<(istream &istrich, const polynom& m);
};