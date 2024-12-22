#include "polinom.h"
polynom<monom>::polynom()
{
    first = nullptr;
    last = nullptr;
}
void polynom<monom>::Sortishe(const polynom<monom>& p)
{
    NODE<monom>* tmp = p.first;
    NODE<monom>* runner = p.first;
    while (runner -> next != nullptr)
    {
        while (tmp -> next != nullptr)
        {
            if (tmp->next->val.GetFullPow() < tmp -> val.GetFullPow())
            {
                NODE<monom>* lilone = tmp->next;
                NODE<monom>* lillilone = tmp;
                lillilone -> next = lillilone;
                lillilone = lilone;
            }
            tmp = tmp->next;
        }
        runner = runner -> next;
    }
}
polynom<monom>::polynom(const polynom<monom>& h)
{

}
polynom<monom>::~polynom()
{}