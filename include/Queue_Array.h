#pragma once
#include <iostream>
#include <stdexcept>
#include "constants.h"

template<typename T>
class Queue_Array {
private:
    T arr[MAX_SIZE];
    int front;
    int rear;
    size_t current_size;

public:
    Queue_Array();

    void enqueue(const T &data);

    size_t getSize() const {
        return current_size;
    }

    T dequeue();

    T peek();

    bool isEmpty();

    bool isFull();

    void display();
};

template<typename T>
Queue_Array<T>::Queue_Array() {
    front = 0;
    rear = -1;
    current_size = 0;
}

template<typename T>
void Queue_Array<T>::enqueue(const T &data) {
    if (isFull()) {
        throw std::out_of_range("Queue is full.");
    }
    rear = (rear + 1) % MAX_SIZE;
    arr[rear] = data;
    current_size++;
}

template<typename T>
T Queue_Array<T>::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty.");
    }
    T dequeued_value = arr[front];
    front = (front + 1) % MAX_SIZE;
    current_size--;
    return dequeued_value;
}

template<typename T>
T Queue_Array<T>::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty.");
    }
    return arr[front];
}

template<typename T>
bool Queue_Array<T>::isEmpty() {
    return current_size == 0;
}

template<typename T>
bool Queue_Array<T>::isFull() {
    return current_size == MAX_SIZE;
}

template<typename T>
void Queue_Array<T>::display() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    int count = 0;
    int i = front;
    while (count < current_size) {
        std::cout << arr[i] << " ";
        i = (i + 1) % MAX_SIZE;
        count++;
    }
    std::cout << std::endl;
}
