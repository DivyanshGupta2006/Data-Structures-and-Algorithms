#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

template<typename T>
class Priority_Queue {
private:
    std::vector<T> heap;

    void heapify_up(int index) {
        if (index > 0) {
            int parent_index = (index - 1) / 2;
            if (heap[index] > heap[parent_index]) {
                std::swap(heap[index], heap[parent_index]);
                heapify_up(parent_index);
            }
        }
    }

    void heapify_down(int index) {
        int left_child_index = 2 * index + 1;
        int right_child_index = 2 * index + 2;
        int largest = index;

        if (left_child_index < heap.size() && heap[left_child_index] > heap[largest]) {
            largest = left_child_index;
        }
        if (right_child_index < heap.size() && heap[right_child_index] > heap[largest]) {
            largest = right_child_index;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapify_down(largest);
        }
    }

public:
    Priority_Queue() {}

    void push(const T& data) {
        heap.push_back(data);
        heapify_up(heap.size() - 1);
    }

    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Priority Queue is empty.");
        }
        T top_element = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
        return top_element;
    }

    T top() {
        if (isEmpty()) {
            throw std::out_of_range("Priority Queue is empty.");
        }
        return heap.front();
    }

    bool isEmpty() {
        return heap.empty();
    }

    size_t getSize() {
        return heap.size();
    }
};