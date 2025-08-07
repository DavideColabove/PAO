#include<iostream>

template<class T>
class dList{
    private:
        class nodo{
            public:
                T info;
                nodo *prev, *next;
                nodo(const T&, nodo* = 0, nodo* = 0);
        };
        // INV: lista vuota IFF first == nullptr == last
        nodo *last, *first;
        static nodo* copia(nodo*, nodo*&);
        static bool smallerThan(nodo*, nodo*);
        static void distruggi(nodo*);
    public:
        dList(unsigned int k = 0, const T& t = T()): last(nullptr), first(nullptr){
            for(; k>0; --k)
                insertFront(t);
        }
        dList(const T&);
        dList& operator=(const T&);
        ~dList();
        void insertFront(const T&);
        void insertBack(const T&);
        bool operator<(const dList&) const;
        class const_iterator{
            friend class dList<T>;
            private:
                nodo* ptr; //ptr al nodo a cui si riferisce il const_iterator
                bool pte;   // true IFF il const_iterator é il past-the-end
                const_iterator(nodo*, bool = false);
            public:
                const_iterator(): ptr(nullptr), pte(false){}
                const T& operator*() const;
                const T* operator->() const;
                const_iterator& operator++();
                const_iterator operator++(int);
                const_iterator& operator--();
                const_iterator operator--(int);
                bool operator==(const const_iterator&) const;
                bool operator!=(const const_iterator&) const;
        };
        const_iterator begin() const;
        const_iterator end() const;
};

template <class T>
dList<T>::nodo::nodo(const T &t, nodo *p, nodo *n): info(t), prev(p), next(n){}

template <class T>
typename dList<T>::nodo *dList<T>::copia(nodo *f, nodo *&last){
    if(f == nullptr)
        return last = nullptr;
    nodo* first = new nodo(f->info, nullptr, nullptr);
    nodo* current = first;
    while(f->next != nullptr){
        current = new nodo(f->next->info, current, nullptr);
        current->prev->next = current;
        f = f->next;
    }
    last = current;
    return first;
}

template <class T>
bool dList<T>::smallerThan(nodo* a, nodo* b){
    if(b == nullptr)
        return false;
    if(a == nullptr)
        return true;
    return (a->info < b->info) || ((a->info == b->info) && smallerThan(a->next,b->next));
}

template <class T>
void dList<T>::distruggi(nodo *f){
    if(f!= nullptr){
        distruggi(f->next);
        delete  f;
    }
}

template <class T>
dList<T>::dList(const T &d): last(nullptr), first(copia(d.first, last)){}

template <class T>
dList<T>& dList<T>::operator=(const T &d){
    if(this != &d){
        distruggi(first);
        first = copia(d.first,last);
    }
    return *this;
}

template <class T>
dList<T>::~dList(){
    if(first)
        distruggi(first);
}

template <class T>
void dList<T>::insertFront(const T &t){
    first = new nodo(t, nullptr, first);
    if(last == nullptr)
        last = first;
    else    // la lista di invocazione era non vuota, quindi first->next != 0
        first->next->prev = first;
}

template <class T>
void dList<T>::insertBack(const T &t){
    last = new nodo(t, last, nullptr);
    if(first == nullptr)
        first = last;
    else
        last->prev->next = last;
}

template <class T>
bool dList<T>::operator<(const dList& t) const{
    return smallerThan(first, t.first);
}

template <class T>
typename dList<T>::const_iterator dList<T>::begin() const{
    return first;
}

template <class T>
typename dList<T>::const_iterator dList<T>::end() const{
    if(first == nullptr)
        return const_iterator(nullptr,false);
    return const_iterator(last+1, true);
}

template <class T>
dList<T>::const_iterator::const_iterator(nodo* p, bool b): ptr(p), pte(b){}

template <class T>
const T &dList<T>::const_iterator::operator*() const{
    return ptr->info;
}

template <class T>
const T *dList<T>::const_iterator::operator->() const{
    return &(ptr->info);
}

template <class T>
typename dList<T>::const_iterator& dList<T>::const_iterator::operator++(){
    if(!ptr && !pte){
        if(ptr->next == nullptr){
            ptr += 1;
            pte = true;
        }
        else
            ptr = ptr->next;
    }
    return *this;
}

template <class T>
typename dList<T>::const_iterator& dList<T>::const_iterator::operator--(){
    if(ptr){
        if(pte){
            ptr -= 1;
            pte = false;
        }
        else
            ptr = ptr->prev;
    }
    return *this;
}

template <class T>
bool dList<T>::const_iterator::operator==(const const_iterator &cit) const{
    return ptr == cit.ptr;
}

template <class T>
bool dList<T>::const_iterator::operator!=(const const_iterator &cit) const{
    return ptr != cit.ptr;
}
