#include<iostream>
using std::cout;
using std::endl;
#include "Queue.h"

int main(){
    Queue<int>* pi = new Queue<int>;
    // vengono istanziati la classe Queue<int> ed il suo costruttore Queue<int>() perche
    // new deve costruire un oggetto della classe

    int i;
    for(i = 0; i < 10; ++i)
        pi->add(i);
    // vengono istanziati i metodi add<int> e empty<int>, la classe QueueItem<int> e il 
    // suo costruttore QueueItem<int>()

    for(i = 0; i < 10; ++i)
        cout << pi->remove() << endl;
    //viene istanziato il metodo remove<int> e il suo distruttore standard ~QueueItem<int>
}