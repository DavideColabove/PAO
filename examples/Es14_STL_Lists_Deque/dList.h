#include<iostream>

template<class T>
class dList{
    private:
        class nodo{
            public:
                T info;
                nodo *prev, *next;
                nodo(const T&, nodo*, nodo*);
        };
        nodo *first, *last;
        // INV: lista vuota IFF first == nullptr == last
    public:
        dList(unsigned int, const T&);
        dList(const T&);
        dList& operator=(const T&);
        ~dList();
        void insertFront(const T&);
        void insertBack(const T&);
        bool operator<(const dList&) const;
        class const_iterator{
            private:
                nodo* ptr; //ptr al nodo a cui si riferisce il const_iterator
                bool pte;   // true IFF il const_iterator é il past-the-end
            public:
                const T& operator*() const;
                const T* operator->() const;
                const_iterator& operator++();
                const_iterator operator++(int);
                const_iterator& operator--();
                const_iterator operator--(int);
        };
        const_iterator begin() const;
        const_iterator end() const;
};

template <class T>
dList<T>::nodo::nodo(const T &t, nodo *p, nodo *n): info(t), prev(p), next(n){}

template <class T>
dList<T>::dList(unsigned int k, const T &t){

}

template <class T>
dList<T>::dList(const T &d){

}

template <class T>
dList &dList<T>::operator=(const T &d){

}

template <class T>
dList<T>::~dList(){

}

template <class T>
void dList<T>::insertFront(const T &t){

}

template <class T>
void dList<T>::insertBack(const T &t){

}

template <class T>
bool dList<T>::operator<(const dList& t) const{
    
}
