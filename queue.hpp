//
//  queue.hpp
//  youssef
//
//  Created by on 26/03/2023.
//
#ifndef queue_hpp
#define queue_hpp

#include <iostream>
#include "mechanic.hpp"
#include "customer.hpp"

using namespace std;

template <class X>
class Queue{
private:

    int head;

    int tail;

    int count;

    X array[5]; // it's assumed that there are a maximum of 5 customer and Mechanics
public:

    Queue(){head = 0; //implemnted a circular queue

        tail = -1;

        count = 0;};

    void enqueue(X element);

    X dequeue();

    int getCount();
};


#endif /* queue_hpp */
