//Template di classe coda
#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class QueueItem{
    friend class QueueItem<T>;
    friend std::ostream& operator<< <T> (std::ostream&, const QueueItem<T>&);
    private:
        T info;
        QueueItem* next;
        QueueItem(const T& val): info(val), next(nullptr){}
};

template <class T>
class Queue{
    friend std::ostream& operator<< <T> (std::ostream&, const Queue<T>&);
    public:
        Queue(): primo(nullptr), ultimo(nullptr){}
        bool empty() const;
        void add (const T&);
        T remove();
        /* Distruttore, costruttore di copia, asssegnazione profondi!*/
        ~Queue();
        Queue(const Queue&);        //copia profonda
        Queue& operator=(const Queue&); //assegnazione profonda
        
        template <class T>
        std::ostream& operator<<(std::ostream&, const Queue<T>&);

    private:
        static int contatore;
        QueueItem<T>* primo;         //primo elemento della coda
        QueueItem<T>* ultimo;       //ultimo elemento della coda
};

template <class T>
bool Queue<T>::empty() const{
    return (primo == nullptr);
}

template <class T>
void Queue<T>::add(const T& val){
    if(empty())
        primo = ultimo = new QueueItem<T>(val);
    else{       //aggiunge in coda
        ultimo->next = new QueueItem<T>(val);
        ultimo = ultimo->next;
    }
}

template <class T>
T Queue<T>::remove(){
    if(empty()){
        std::cerr << "remove() su coda vuota" << std::endl;
        exit(1);    // BAD PRACTICE, eccezione preferibile
    }
    QueueItem<T>* p = primo;
    primo = primo->next;
    T aux = p->info;
    delete p;   // rimuovo garbage
    return aux;
}

template <class T>
Queue<T>::~Queue(){     // distruzione profonda
    while(!empty())
        remove();
}

template <class T>
std::ostream& operator<<(std::ostream& os, const QueueItem<T>& qi){
    os << qi.info;
    return os;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q){
    os << " (";
    QueueItem<T>* p = q.primo;      // amicizia con Queue
    for (; p!= 0; p = p->next){     // amicizia con QueueItem
        os << *p  << " ";       // operator<< per il tipo QueuItem
    }
    os << ")" << std::endl;
    return os;
}

template <class T>
int Queue<T>::contatore =0;

#endif