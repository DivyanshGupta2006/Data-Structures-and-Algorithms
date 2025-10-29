#pragma once
#include "LinkedList.h"
#include <stdexcept>

template<typename T>
class Queue_LinkedList {
private:
    LinkedList<T> list;

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
    T getElementAt(const size_t index);
    int search(const T &data) const;
    void delete_element(const T &data);
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

template<typename T>
T Queue_LinkedList<T>::getElementAt(const size_t index) {
    return list.getElementAt(index);
}

template<typename T>
int Queue_LinkedList<T>::search(const T &data) const {
    return list.search(data);
}

template<typename T>
void Queue_LinkedList<T>::delete_element(const T &data) {
    list.delete_element(data);
}