/* Author: Christopher Liudahl-Rackley
 * Date: 12/3/2021
 * Class: CS300
 * Assignment 5
 * Description: This is the class definition to the Queue, which is the line 
 * as a customer gets added to the queue, while in the queue a tranaction can 
 * occur which allows us to update the information that we need.
 */
#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

#include "QueueADT.h"

template <class T>
class Queue: public QueueADT<T>{
    private:
        static const int CAPACITY = 10;
        T items[CAPACITY];
        int front;
        int back;
        int count;
    public:
        Queue();
        void enqueue(const T&);
        void dequeue();
        T& qfront();
        bool isEmpty();
        bool isFull();
};

template <class T>
Queue<T>::Queue():front(0), back(CAPACITY-1), count(0) {}

template <class T>
void Queue<T>::enqueue(const T& newEntry){
    if(count < CAPACITY){
        back = (back + 1) % CAPACITY;
        items[back] = newEntry;
        count++;
    }
}

template <class T>
void Queue<T>::dequeue(){
    if(!isEmpty()){
        front = (front + 1) % CAPACITY;
        count--;
    }
}

template <class T>
T& Queue<T>::qfront() {
    return items[front];
}

template <class T>
bool Queue<T>::isEmpty() {
    return count == 0;
}

template <class T>
bool Queue<T>::isFull() {
    return count == (sizeof(items[CAPACITY]) / sizeof(int));
}

#endif