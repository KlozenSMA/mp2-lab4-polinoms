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
bool polynom::operator==(const polynom& misc)
{
    NODE<monom>* RopeRunner = first;
    NODE<monom>* RopeRunner2 = misc.first;
    while (RopeRunner->next != nullptr)
    {
        if ((RopeRunner != RopeRunner2) || (RopeRunner2 == nullptr))
        {
            return false;
        }
        RopeRunner = RopeRunner->next;
        RopeRunner2 = RopeRunner2->next;
    }
    RopeRunner2 = misc.first;
    RopeRunner = first;
    while (RopeRunner2->next != nullptr)
    {
        if ((RopeRunner != RopeRunner2) || (RopeRunner == nullptr))
        {
            return false;
        }
        RopeRunner = RopeRunner->next;
        RopeRunner2 = RopeRunner2->next;
    }
    return true;
}
bool polynom::operator!=(const polynom& misc)
{
    NODE<monom>* RopeRunner = first;
    NODE<monom>* RopeRunner2 = misc.first;
    while (RopeRunner->next != nullptr)
    {
        if ((RopeRunner != RopeRunner2) || (RopeRunner2 == nullptr))
        {
            return true;
        }
        RopeRunner = RopeRunner->next;
        RopeRunner2 = RopeRunner2->next;
    }
    RopeRunner2 = misc.first;
    RopeRunner = first;
    while (RopeRunner2->next != nullptr)
    {
        if ((RopeRunner != RopeRunner2) || (RopeRunner == nullptr))
        {
            return true;
        }
        RopeRunner = RopeRunner->next;
        RopeRunner2 = RopeRunner2->next;
    }
    return false;
}
polynom polynom::operator+(const polynom& msic)
{
    NODE<monom>* RopeRunner1 = msic.first;
    while (RopeRunner1->next != nullptr)
    {
        bool found = false;
        NODE<monom>* RopeRunner = first;
        while (RopeRunner->next != nullptr) //if found
        {
            if (RopeRunner->val.GetFullPow() == RopeRunner1->val.GetFullPow())
            {
                found = true;
                NODE<monom>* one;
                one->val = monom(RopeRunner->val.GetCo()+RopeRunner1->val.GetCo(),RopeRunner->val.GetFullPow());
                Insert(one,RopeRunner);
            }
            RopeRunner = RopeRunner->next;
        }
        if (last->val.GetFullPow() == RopeRunner1->val.GetFullPow())
            {
                found = true;
                NODE<monom>* one;
                one->val = monom(last->val.GetCo()+RopeRunner1->val.GetCo(),last->val.GetFullPow());
                Insert(one,last);
            }
        if (not(found))
        {
            monom Insertion(RopeRunner1->val.GetCo(),RopeRunner1->val.GetFullPow());
            InsertLast(Insertion);
        }
    }
    Sortishe(*this);
    return *this;
}
polynom polynom::operator+(const monom& msic)
{
    NODE<monom>* RopeRunner = first;
    NODE<monom>* one;
    bool found;
    one->val = msic;
    while (RopeRunner->next != nullptr) //if found
    {
        if (RopeRunner->val.GetFullPow() == one->val.GetFullPow())
        {
            found = true;
            NODE<monom>* that;
            one->val = monom(RopeRunner->val.GetCo()+one->val.GetCo(),RopeRunner->val.GetFullPow());
            Insert(that,RopeRunner);
        }
        RopeRunner = RopeRunner->next;
    }
    if (last->val.GetFullPow() == one->val.GetFullPow())
    {
        found = true;
        NODE<monom>* that;
        one->val = monom(last->val.GetCo()+one->val.GetCo(),last->val.GetFullPow());
        InsertLast(that->val);
    }
    if (not(found))
    {
        monom Insertion(one->val.GetCo(),one->val.GetFullPow());
        InsertLast(Insertion);
    }
    Sortishe(*this);
    return *this;
}
polynom polynom::operator*(double val)
{
    NODE<monom>* RopeRunner = first;
    while (RopeRunner -> next != nullptr)
    {
        NODE<monom>* Enter;
        Enter->val = monom(RopeRunner->val.GetCo()*val,RopeRunner->val.GetFullPow());
        Insert(Enter,RopeRunner);
    }
    last->val = monom(last->val.GetCo()*val,last->val.GetFullPow());
    return *this;
}