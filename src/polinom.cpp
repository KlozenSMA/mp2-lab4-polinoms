#include "polinom.h"
polynom::polynom()
{
    first = nullptr;
    last = nullptr;
}
void polynom::Sortishe(const polynom& p)
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
polynom::polynom(const polynom& h)
{
    DeleteAll();
        if (h.first->next != nullptr)
        {
            first = h.first;
            first->next = h.first->next;
            NODE<monom>* tmp = h.first->next;
            NODE<monom>* tmp1 = first->next;
            while (tmp -> next != nullptr)
            {
                tmp1 -> next = tmp -> next;
                tmp = tmp -> next;
                tmp1 = tmp1 -> next;
            }
            last->val = tmp->val;
        }
        else
        {
            first = h.first;
            last = h.first;
        }
}
polynom::~polynom()
{
    DeleteAll();
}
