//Template di classe coda
#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class QueueItem{
    public:
        QueueItem(const T&): info(val), next(nullptr){}
        T info;
        QueueItem* next;
};

template <class T>
class Queue{
    public:
        Queue(): primo(nullptr), ultimo(nullptr){}
        ~Queue();
        Queue(const Queue&);        //copia profonda
        Queue& operator=(const Queue&); //assegnazione profonda
        bool empty() const;
        void add (const T&);
        T remove();
    private:
        QueueItem<T>* primo;        //primo elemento della coda
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




