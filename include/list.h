#include <iostream>

template<class T>
struct NODE
{
    T val;
    NODE* next;
    NODE(T val; NODE* next);
};

template<class T>
class List
{
    protected:
    NODE<T>* first; NODE<T>* last;
    public:
    List()
    {
        first = nullptr;
        last = nullptr;
    }
    void Insert(T Val)
    {
        NODE<T>* p = new NODE<T>(Val,nullptr);
        if (last != nullptr)
        {last -> next = p;last = p;}
        else
        {first = p;last = p;}
    }
    void Insert(NODE* now, NODE* insertion)
    {
        if (now -> next != nullptr)
        {
            insertion-> next = now -> next;
            insertion-> val = now -> val;
        }
        else
        {
            last->val = insertion -> val;
        }
    }
    void InsertFirst(T Val)
    {
        NODE<T>* p = new NODE(Val,first);
        first = p;
        if (last == nullptr)
        {
            last = p;
        }
    }
    void InsertLast(T Val)
    {
        NODE<T>* p = new NODE(Val,nullptr);
        NODE<T>* tmp;
        tmp = first;
        while(tmp->next!=nullptr)
        {
            tmp = tmp->next;
            tmp->next = p;
        }
    }
    void DeleteAll()
    {
        if (first != nullptr)
        {
            NODE<T>* tmp = first;
            while (first->next != nullptr)
            {
                first = tmp->next;
                delete tmp;
                tmp = first;
            }
            delete first;
        }
    }
    List(const List& b)
    {
        DeleteAll();
        if (b.first->next != nullptr)
        {
            first = b.first;
            first->next = b.first->next;
            NODE* tmp = b.first->next;
            NODE* tmp1 = first->next;
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
            first = b.first;
            last = b.first;
        }

    }
    ~List()
    {
        DeleteAll();
    }
    NODE* RetFirst()
    {
        return &first;
    }
    void Print()
    {
        NODE* P = first;
        while (p -> next != nullptr)
        {
            cout << p -> val << " ";
            p = p -> next;
        }
        cout << p -> val;
    }
    void DeleteTheNext(NODE* that)
    {
        NODE* temp = that -> next;
        that - > next = that -> next -> next;
        delete temp;
    }
    List operator=(const List& l)
    {
        if (&l == *this)
        {
            return this;
        }
        this->DeleteAll();
        if (b.first->next != nullptr)
        {
            first = b.first;
            first->next = b.first->next;
            NODE* tmp = b.first->next;
            NODE* tmp1 = first->next;
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
            first = b.first;
            last = b.first;
        }
    }
};