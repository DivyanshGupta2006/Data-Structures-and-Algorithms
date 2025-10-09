#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>

template<typename T, typename Compare = std::less<T>>
class Heap {
private:
    std::vector<T> heap;
    Compare comp;

    void heapify_up(int index) {
        if (index > 0) {
            int parent_index = (index - 1) / 2;
            if (comp(heap[parent_index], heap[index])) {
                std::swap(heap[index], heap[parent_index]);
                heapify_up(parent_index);
            }
        }
    }

    void heapify_down(int index) {
        int left_child_index = 2 * index + 1;
        int right_child_index = 2 * index + 2;
        int target = index;

        if (left_child_index < heap.size() && comp(heap[target], heap[left_child_index])) {
            target = left_child_index;
        }
        if (right_child_index < heap.size() && comp(heap[target], heap[right_child_index])) {
            target = right_child_index;
        }

        if (target != index) {
            std::swap(heap[index], heap[target]);
            heapify_down(target);
        }
    }

public:
    Heap() {}

    void push(const T& data) {
        heap.push_back(data);
        heapify_up(heap.size() - 1);
    }

    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Heap is empty.");
        }
        T top_element = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
        return top_element;
    }

    T top() {
        if (isEmpty()) {
            throw std::out_of_range("Heap is empty.");
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