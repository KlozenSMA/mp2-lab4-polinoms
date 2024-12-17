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
    NODE<T>* first; NODE<T>* last;
    public:
    List()
    {
        first.next = &first;
    }
    void Insert(T Val)
    {
        NODE<T>* p = new NODE<T>(Val,nullptr);
        if (last != nullptr)
        {last -> next = p;last = p;}
        else
        {first = p;last = p;}
    }
    void Insert(Node* now, Node* insertion)
    {
        insertion->next=now->next;
        now->next=insertion;
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
    List(const List& b)
    {
        first->val = &b.first->val;
        first->next = &first;
        NODE* q = &first;
	    NODE* p = b.first->next;
        while(p != &b.first)
	    {
            Insert(q, new NODE(p->m));
            p = p->next;
            q = q->next;
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
        first->val = l.first->val;
        first->next = &first;
        NODE* q = &first;
	    NODE* p = b.first->next;
        while(p != &b.first)
	    {
            Insert(q, new NODE(p->m));
            p = p->next;
            q = q->next;
	    }
    }
};