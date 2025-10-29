#pragma once
#include "Doubly_LinkedList.h"
#include <stdexcept>

template<typename T>
class Double_Queue {
private:
    Doubly_LinkedList<T> list;

public:
    Double_Queue();
    void push_front(const T& data);
    void push_back(const T& data);
    T pop_front();
    T pop_back();
    T front();
    T back();
    bool isEmpty();
    size_t getSize() {
        return list.getSize();
    }
    void display();
};

template<typename T>
Double_Queue<T>::Double_Queue() {}

template<typename T>
void Double_Queue<T>::push_front(const T& data) {
    list.insert_begin(data);
}

template<typename T>
void Double_Queue<T>::push_back(const T& data) {
    list.insert_end(data);
}

template<typename T>
T Double_Queue<T>::pop_front() {
    if (isEmpty()) {
        throw std::out_of_range("Deque is empty.");
    }
    T value = list.head->value;
    list.delete_begin();
    return value;
}

template<typename T>
T Double_Queue<T>::pop_back() {
    if (isEmpty()) {
        throw std::out_of_range("Deque is empty.");
    }
    T value = list.getValue(list.getSize() - 1); // In a deque, this is the last element
    list.delete_end();
    return value;
}

template<typename T>
T Double_Queue<T>::front() {
    if (isEmpty()) {
        throw std::out_of_range("Deque is empty.");
    }
    return list.head->value;
}

template<typename T>
T Double_Queue<T>::back() {
    if (isEmpty()) {
        throw std::out_of_range("Deque is empty.");
    }
    return list.getValue(list.getSize() - 1); // In a deque, this is the last element
}

template<typename T>
bool Double_Queue<T>::isEmpty() {
    return list.isEmpty();
}

template<typename T>
void Double_Queue<T>::display() {
    list.display();
}