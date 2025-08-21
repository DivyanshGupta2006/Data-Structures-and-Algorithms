// Header file containing declarations and definitions of Stack_Array class and all the associated functions and variables

// "include guard" to prevent multiple inclusions in different files that are also included in each other
#pragma once
#include <iostream>
#include <stdexcept>

const int MAX_SIZE = 100;

template<typename T>
class Stack_Array {
private:
    T arr[MAX_SIZE];
    int top;

public:
    Stack_Array();
    void push(const T& data);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();
    void display();
};

template<typename T>
Stack_Array<T>::Stack_Array() {
    top = -1;
}

template<typename T>
void Stack_Array<T>::push(const T& data) {
    if (isFull()) {
        throw std::out_of_range("Stack is full.");
    }
    arr[++top] = data;
}

template<typename T>
T Stack_Array<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty.");
    }
    return arr[top--];
}

template<typename T>
T Stack_Array<T>::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty.");
    }
    return arr[top];
}

template<typename T>
bool Stack_Array<T>::isEmpty() {
    return top == -1;
}

template<typename T>
bool Stack_Array<T>::isFull() {
    return top == MAX_SIZE - 1;
}

template<typename T>
void Stack_Array<T>::display() {
    if (isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    for (int i = top; i >= 0; i--) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}