#pragma once
#include "Stack_LinkedList.h"
#include <stdexcept>

template<typename T>
class QueueUsingStack {
private:
    Stack_LinkedList<T> s1;
    Stack_LinkedList<T> s2;

public:
    QueueUsingStack();
    void enqueue(const T& data);
    T dequeue();
    T peek();
    bool isEmpty();
    size_t getSize() {
        return s1.getSize() + s2.getSize();
    }
};

template<typename T>
QueueUsingStack<T>::QueueUsingStack() {}

template<typename T>
void QueueUsingStack<T>::enqueue(const T& data) {
    s1.push(data);
}

template<typename T>
T QueueUsingStack<T>::dequeue() {
    if (s1.isEmpty() && s2.isEmpty()) {
        throw std::out_of_range("Queue is empty.");
    }
    if (s2.isEmpty()) {
        while (!s1.isEmpty()) {
            s2.push(s1.pop());
        }
    }
    return s2.pop();
}

template<typename T>
T QueueUsingStack<T>::peek() {
    if (s1.isEmpty() && s2.isEmpty()) {
        throw std::out_of_range("Queue is empty.");
    }
    if (s2.isEmpty()) {
        while (!s1.isEmpty()) {
            s2.push(s1.pop());
        }
    }
    return s2.peek();
}

template<typename T>
bool QueueUsingStack<T>::isEmpty() {
    return s1.isEmpty() && s2.isEmpty();
}