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
polynom operator==(const polynom);
polynom operator!=(const polynom);
polynom operator+(const polynom& p);
polynom operator+(const monom& m);
polynom operator-(const polynom& p);
polynom operator-(const monom& m);
polynom operator*(double val);
//мы очень спешим
// friend ostream& operator<<(ostream &ostrich, const polynom& m);
// friend istream& operator<<(istream &istrich, const polynom& m);
};