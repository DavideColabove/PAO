//Template di classe coda
#include <iostream>

template <class T>
class QueueItem{
    public:
        QueueItem(const T&);
        T info;
        QueueItem* next;
};

template <class T>
class Queue{
    public:
        Queue();
        ~Queue();
        Queue(const Queue&);        //copia profonda
        Queue& operator=(const Queue&); //assegnazione profonda
        bool empty() const;
        void add (const T&);
        T remove();
    private:
        QueueItem<T>* primo;
        QueueItem<T>* ultimo;
};

template <class T>
Queue<T>::Queue() : primo(0), ultimo(0){}

int main(){
    //SOLO istanziazione ESPLICITA
    Queue<int> qi;
    Queue<boolletta> qb;
    Queue<string> qs;
}

