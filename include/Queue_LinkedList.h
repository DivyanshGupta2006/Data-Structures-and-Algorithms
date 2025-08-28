#pragma once
#include "Circular_Doubly_LinkedList.h"
#include <stdexcept>

template<typename T>
class Queue_LinkedList {
private:
    Circular_Doubly_LinkedList<T> list;

public:
    Queue_LinkedList();
    size_t getSize() const {
        return list.getSize();
    }
    void enqueue(const T& data);
    T dequeue();
    T peek();
    bool isEmpty();
    void display();
};

template<typename T>
Queue_LinkedList<T>::Queue_LinkedList() {}

template<typename T>
void Queue_LinkedList<T>::enqueue(const T& data) {
    list.insert_end(data);
}

template<typename T>
T Queue_LinkedList<T>::dequeue() {
    if (list.isEmpty()) {
        throw std::out_of_range("Queue is empty.");
    }
    T dequeued_value = list.head->value;
    list.delete_begin();
    return dequeued_value;
}

template<typename T>
T Queue_LinkedList<T>::peek() {
    if (list.isEmpty()) {
        throw std::out_of_range("Queue is empty.");
    }
    return list.head->value;
}

template<typename T>
bool Queue_LinkedList<T>::isEmpty() {
    return list.isEmpty();
}

template<typename T>
void Queue_LinkedList<T>::display() {
    if (list.isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    list.display();
}