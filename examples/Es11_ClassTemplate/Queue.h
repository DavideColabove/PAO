//Template di classe coda
#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H

template <class T> class Queue;
template <class T> std::ostream& operator<< (std::ostream& os, const Queue<T>&);

template <class T>
class Queue{
    // NON agisce da dichiarazione di template di funzione
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
    private:
        // template di classe annidato associato
        class QueueItem{    // QueueItem<T> é un tipo implicito in quanto non é un tipo completamente definito ma dipende impliciatamente dai parametri di tipo di Queue<T>  
            friend class Queue<T>;
            friend std::ostream& operator<< <T> (std::ostream&, const Queue<T>&);
            // agisce da dichiarazione di template di funzione
            friend std::ostream& operator<< <T> (std::ostream&, const typename Queue<T>::QueueItem&);
            public:
                QueueItem(const T& val): info(val), next(nullptr){}
                T info;
                QueueItem* next;  
        };
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
std::ostream& operator<< <T> (std::ostream& os, const typename Queue<T>::QueueItem& qi){
    os << qi.info;
    return os;
}

template <class T>
std::ostream& operator<< <T> (std::ostream& os, const Queue<T>& q){
    os << " (";
    QueueItem<T>* p = q.primo;      // amicizia con Queue
    for (; p!= 0; p = p->next){     // amicizia con QueueItem
        os << *p  << " ";       // operator<< per il tipo QueuItem
    }
    os << ") " << std::endl;
    return os;
}

template <class T>
int Queue<T>::contatore =0;

#endif