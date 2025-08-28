#pragma once
#include "Stack_LinkedList.h"
#include <stdexcept>

template<typename T>
class Queue_Stack {
private:
    Stack_LinkedList<T> s1;
    Stack_LinkedList<T> s2;

public:
    Queue_Stack();
    void enqueue(const T& data);
    T dequeue();
    T peek();
    bool isEmpty();
    size_t getSize() {
        return s1.getSize() + s2.getSize();
    }
    void display();
};

template<typename T>
Queue_Stack<T>::Queue_Stack() {}

template<typename T>
void Queue_Stack<T>::enqueue(const T& data) {
    s1.push(data);
}

template<typename T>
T Queue_Stack<T>::dequeue() {
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
T Queue_Stack<T>::peek() {
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
bool Queue_Stack<T>::isEmpty() {
    return s1.isEmpty() && s2.isEmpty();
}

template<typename T>
void Queue_Stack<T>::display() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    if (s2.isEmpty()) {
        while (!s1.isEmpty()) {
            s2.push(s1.pop());
        }
    }

    // Print elements from s2, which are now in the correct order
    Stack_LinkedList<T> tempStack;
    while (!s2.isEmpty()) {
        T data = s2.pop();
        std::cout << data << " ";
        tempStack.push(data);
    }
    std::cout << std::endl;

    // Restore s2
    while (!tempStack.isEmpty()) {
        s2.push(tempStack.pop());
    }
}

