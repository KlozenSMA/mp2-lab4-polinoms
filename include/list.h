#include <iostream>

template<class T>
struct NODE
{
    T val;
    NODE<T>* next;
    NODE(T _val, NODE* _next)
    {
        _val = val;
        _next = next;
    }
};

template<class T>
class List
{
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
    void Insert(NODE<T>* now, NODE<T>* insertion)
    {
        if (insertion == nullptr)
        {
            throw "Node you're tryinng to insert does not exist";
        }
        //finding previous element
        NODE<T>* Runner = first;
        bool sflag = false;
        NODE<T>* previous;
        while (Runner != nullptr)
        {
            if (Runner -> next == now)
            {
                previous = Runner;
                Runner = nullptr;
                sflag = true;
            }
        }
        if (not(sflag))
        {
            throw "your node-destination not exist in this universe";
        }
        NODE<T>* innit = now;
        previous->next = insertion;
        insertion->next = innit;
    }
    void InsertFirst(T Val)
    {
        NODE<T>* p = new NODE(Val,first);
        if (first == nullptr && last == nullptr)
        {
            first = p;
            last = p;
        }
        else 
        {
            if (first -> next == nullptr)
            {
                first -> next = first;
                last = first->next;
                first = p;
            }
            else
            {
                NODE<T>* tmp = first;
                tmp->next = first -> next;
                p->next = tmp;
                first = nullptr;
                first = p;
            }
        }
    }
    void InsertLast(T Val)
    {
        NODE<T>* p = new NODE<T>(Val,nullptr);
        NODE<T>* tmp = first;
        if (tmp == nullptr)
        {
            first = p;
            first->next = nullptr;
            last = p;
            last->next = nullptr;
        }
        else
        {
            while(tmp->next!=nullptr)
            {
                tmp = tmp->next;
                tmp->next = p;
            }
        }
    }
    void DeleteAll()
    {
        if (first -> next != nullptr)
        {
            NODE<T>* tmp = first;
            while (first->next != nullptr)
            {
                first = tmp->next;
                tmp = nullptr;
                tmp = first;
            }
            first = nullptr;
        }
        else{first = nullptr;}
    }
    List(const List& b)
    {
        if (b.first == nullptr)
        {
            first = nullptr;
            last = first;
        }
        else
        {
            if (b.first-> next != nullptr)
            {
                first = b.first;
                first->next = b.first->next;
                NODE<T>* tmp = b.first->next;
                NODE<T>* tmp1 = first->next;
                while (tmp -> next != nullptr)
                {
                    NODE<T>* nns = tmp;
                    NODE<T>* nns1 = tmp1;
                    nns1 = nns;
                    nns1 -> next = nns -> next;
                    tmp = tmp -> next;
                }
                last->val = b.last->val;
            }
            else
            {
                first = b.first;
                last = b.first;
            }
        }

    }
    ~List()
    {
        DeleteAll();
    }
    void Print()
    {
        NODE<T>* p = first;
        while (p -> next != nullptr)
        {
            std::cout << p -> val << " ";
            p = p -> next;
        }
        std::cout << p -> val;
    }
    // returns first node with that value
    NODE<T>* GeNode(T vali)
    {
        NODE<T>* p = first;
        while (p -> next != nullptr)
        {
            if (p->val == vali)
            {
                return p;
            }
            p = p->next;
        }
        throw "This Element does not exist";
    }
    void DeleteTheNext(NODE<T>* that)
    {
        if (that -> next != nullptr || that != nullptr)
        {
            throw "There is nothing next or you're givin' wrong pointer";
        }
        if (that -> next -> next != nullptr)
        {
            NODE<T>* tmp = that->next;
            that -> next = nullptr;
            delete tmp;
        }
        NODE<T>* temp = that -> next;
        that -> next = that -> next -> next;
        delete temp;
    }
    List<T> operator=(const List<T>& l)
    {
        this->DeleteAll();
        if (l.first->next != nullptr)
        {
            first = l.first;
            first->next = l.first->next;
            NODE<T>* tmp = l.first->next;
            NODE<T>* tmp1 = first->next;
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
            first = l.first;
            last = l.first;
        }
        return *this;
    }
    bool operator==(const List<T>& l) const
    {
        NODE<T>* runner = first;
        NODE<T>* runner1 = l.first;
        while (runner -> next != nullptr && runner1 -> next != nullptr)
        {
            if ((runner->next->val != runner1->next->val) || (runner == nullptr || runner1 == nullptr))
            {
                return false;
            }
            runner = runner->next;
            runner1 = runner1->next;
        }
        if (last->val == l.last->val)
        {
            return true;
        }
        return false;
    }
    bool operator!=(const List<T>& l) const
    {
        NODE<T>* runner = first;
        NODE<T>* runner1 = l.first;
        while (runner -> next != nullptr && runner1 -> next != nullptr)
        {
            if ((runner->next->val != runner1->next->val) || (runner == nullptr || runner1 == nullptr))
            {
                return true;
            }
            runner = runner->next;
            runner1 = runner1->next;
        }
        if (last->val == l.last->val)
        {
            return false;
        }
        return true;
    }
};