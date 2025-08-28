#pragma once
#include "Queue_LinkedList.h"
#include <stdexcept>

template<typename T>
class Stack_Queue {
private:
    Queue_LinkedList<T> q1;
    Queue_LinkedList<T> q2;

public:
    Stack_Queue();
    size_t getSize() const {
        return q1.getSize();
    }
    void push(const T& data);
    T pop();
    T peek();
    bool isEmpty();
    void display();
};

template<typename T>
Stack_Queue<T>::Stack_Queue() {}

template<typename T>
void Stack_Queue<T>::push(const T& data) {
    q2.enqueue(data);
    while (!q1.isEmpty()) {
        q2.enqueue(q1.dequeue());
    }
    std::swap(q1, q2);
}

template<typename T>
T Stack_Queue<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty.");
    }
    return q1.dequeue();
}

template<typename T>
T Stack_Queue<T>::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty.");
    }
    return q1.peek();
}

template<typename T>
bool Stack_Queue<T>::isEmpty() {
    return q1.isEmpty();
}

template<typename T>
void Stack_Queue<T>::display() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }

        // Use a temporary queue for display
        Queue_LinkedList<T> tempQueue;

        while (!q1.isEmpty()) {
            T data = q1.dequeue();
            std::cout << data << " ";
            tempQueue.enqueue(data);
        }
        std::cout << std::endl;

        // Restore the main queue
        while (!tempQueue.isEmpty()) {
            q1.enqueue(tempQueue.dequeue());
        }
}

