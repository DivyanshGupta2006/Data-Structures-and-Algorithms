#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>

template<typename T>
struct SortStats {
    long long comparisons = 0;
    long long swaps = 0;
};

template<typename T>
void print_vector(const std::vector<T>& arr) {
    for (const auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

// Bubble Sort
template<typename T>
SortStats<T> bubble_sort(std::vector<T>& arr, bool optimized = false) {
    SortStats<T> stats;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            stats.comparisons++;
            if (arr[j] > arr[j + 1]) {
                stats.swaps++;
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (optimized && !swapped) {
            break;
        }
    }
    return stats;
}

// Selection Sort
template<typename T>
SortStats<T> selection_sort(std::vector<T>& arr) {
    SortStats<T> stats;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            stats.comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            stats.swaps++;
            std::swap(arr[min_idx], arr[i]);
        }
    }
    return stats;
}

// Insertion Sort
template<typename T>
SortStats<T> insertion_sort(std::vector<T>& arr) {
    SortStats<T> stats;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && (stats.comparisons++, arr[j] > key)) {
            stats.swaps++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return stats;
}

// Quick Sort
namespace QuickSort {
    enum PivotType { FIRST, LAST, RANDOM };

    template<typename T>
    int partition(std::vector<T>& arr, int low, int high, PivotType pivot_type, SortStats<T>& stats) {
        int pivot_index;
        if (pivot_type == FIRST) {
            pivot_index = low;
        } else if (pivot_type == LAST) {
            pivot_index = high;
        } else {
            pivot_index = low + rand() % (high - low + 1);
        }
        stats.swaps++;
        std::swap(arr[pivot_index], arr[high]);
        T pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            stats.comparisons++;
            if (arr[j] < pivot) {
                i++;
                stats.swaps++;
                std::swap(arr[i], arr[j]);
            }
        }
        stats.swaps++;
        std::swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    template<typename T>
    void quick_sort_recursive(std::vector<T>& arr, int low, int high, PivotType pivot_type, SortStats<T>& stats) {
        if (low < high) {
            int pi = partition(arr, low, high, pivot_type, stats);
            quick_sort_recursive(arr, low, pi - 1, pivot_type, stats);
            quick_sort_recursive(arr, pi + 1, high, pivot_type, stats);
        }
    }

    template<typename T>
    SortStats<T> quick_sort(std::vector<T>& arr, PivotType pivot_type) {
        SortStats<T> stats;
        quick_sort_recursive(arr, 0, arr.size() - 1, pivot_type, stats);
        return stats;
    }
}

// Merge Sort
namespace MergeSort {
    template<typename T>
    void merge(std::vector<T>& arr, int l, int m, int r, SortStats<T>& stats) {
        int n1 = m - l + 1;
        int n2 = r - m;
        std::vector<T> L(n1), R(n2);

        for (int i = 0; i < n1; i++) L[i] = arr[l + i];
        for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            stats.comparisons++;
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
            stats.swaps++; 
        }

        while (i < n1) {
            arr[k++] = L[i++];
            stats.swaps++;
        }
        while (j < n2) {
            arr[k++] = R[j++];
            stats.swaps++;
        }
    }

    template<typename T>
    void merge_sort_recursive(std::vector<T>& arr, int l, int r, SortStats<T>& stats) {
        if (l < r) {
            int m = l + (r - l) / 2;
            merge_sort_recursive(arr, l, m, stats);
            merge_sort_recursive(arr, m + 1, r, stats);
            merge(arr, l, m, r, stats);
        }
    }

    template<typename T>
    SortStats<T> merge_sort(std::vector<T>& arr) {
        SortStats<T> stats;
        merge_sort_recursive(arr, 0, arr.size() - 1, stats);
        return stats;
    }
}

// Heap Sort
namespace HeapSort {
    template<typename T>
    void heapify(std::vector<T>& arr, int n, int i, SortStats<T>& stats) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        stats.comparisons++;
        if (l < n && arr[l] > arr[largest]) largest = l;
        
        stats.comparisons++;
        if (r < n && arr[r] > arr[largest]) largest = r;
        
        if (largest != i) {
            stats.swaps++;
            std::swap(arr[i], arr[largest]);
            heapify(arr, n, largest, stats);
        }
    }

    template<typename T>
    SortStats<T> heap_sort(std::vector<T>& arr) {
        SortStats<T> stats;
        int n = arr.size();

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i, stats);
        }

        for (int i = n - 1; i > 0; i--) {
            stats.swaps++;
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0, stats);
        }
        return stats;
    }
}