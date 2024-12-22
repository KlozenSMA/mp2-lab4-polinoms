// ����� ������� - ������������� ����������� ������ �������
// ������������ �������� ������, ������� ������, �������� ������,  
// ����� ������, �������� ���������(������� ������������� �������), 
// ��������� ���������

#include "monom.h"
#include "list.h"

template<class T>
class polynom : private List<T>
{
    using List<T>::first;
    using List<T>::last;
public:
// конструктор
polynom();
// конструктор копирования
polynom(const polynom<T>& p);
//деструктор
~polynom();
//функция упорядочивания
void Sortishe(const polynom<T>& p);
//всякие операторы

bool operator==(const polynom<T>& p);
bool operator!=(const polynom<T>& p);
polynom operator+(const polynom<T>& p);
polynom operator+(const monom& m);
polynom operator-(const polynom<T>& p);
polynom operator-(const monom& m);
polynom operator*(double val);
//мы очень спешим
// friend ostream& operator<<(ostream &ostrich, const polynom& m);
// friend istream& operator<<(istream &istrich, const polynom& m);
};