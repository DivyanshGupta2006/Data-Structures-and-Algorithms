// Header file containing declarations and definitions of Stack_LinkedList class and all the associated functions and variables

// "include guard" to prevent multiple inclusions in different files that are also included in each other
#pragma once
#include "LinkedList.h"
#include <stdexcept>
template<typename T>
class Stack_LinkedList {
private:
    LinkedList<T> list;
    size_t size;

public:
    Stack_LinkedList();

    void push(const T &data);

    T pop();

    T peek() const;

    bool isEmpty() const;

    void display() const;

    size_t getSize() const {
        return size;
    }
};

template<typename T>
Stack_LinkedList<T>::Stack_LinkedList() {
    size = 0;
};

template<typename T>
void Stack_LinkedList<T>::push(const T &data) {
    list.insert_begin(data);
    size++;
}

template<typename T>
T Stack_LinkedList<T>::pop() {
    if (list.isEmpty()) {
        throw std::out_of_range("Stack is empty. Cannot pop.");
    }
    T popped_value = list.head->value;
    list.delete_begin();
    size--;
    return popped_value;
}

template<typename T>
T Stack_LinkedList<T>::peek() const {
    if (list.isEmpty()) {
        throw std::out_of_range("Stack is empty. Cannot peek.");
    }
    return list.head->value;
}

template<typename T>
bool Stack_LinkedList<T>::isEmpty() const {
    return list.isEmpty();
}

template<typename T>
void Stack_LinkedList<T>::display() const {
    if (list.isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    list.display();
}
