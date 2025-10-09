#include <iostream>
#include <vector>
#include "Sorts.h"

using namespace std;

#define pl(a) cout << a << "\n";

void test_BubbleSort() {
    pl("Testing functionalities of Bubble Sort")
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    vector<int> arr_optimized = arr;

    pl("------------------------Basic Bubble Sort------------------------")
    auto stats_basic = bubble_sort(arr);
    pl("Sorted array:")
    print_vector(arr);
    cout << "Comparisons: " << stats_basic.comparisons << ", Swaps: " << stats_basic.swaps << endl;

    pl("------------------------Optimized Bubble Sort------------------------")
    auto stats_optimized = bubble_sort(arr_optimized, true);
    pl("Sorted array:")
    print_vector(arr_optimized);
    cout << "Comparisons: " << stats_optimized.comparisons << ", Swaps: " << stats_optimized.swaps << endl;
}

void test_SelectionSort() {
    pl("Testing functionalities of Selection Sort")
    vector<int> arr = {64, 25, 12, 22, 11};
    pl("------------------------Selection Sort------------------------")
    auto stats = selection_sort(arr);
    pl("Sorted array:")
    print_vector(arr);
    cout << "Comparisons: " << stats.comparisons << ", Swaps: " << stats.swaps << " (<= n-1)" << endl;
}

void test_InsertionSort() {
    pl("Testing functionalities of Insertion Sort")
    vector<int> arr = {12, 11, 13, 5, 6};
    pl("------------------------Insertion Sort------------------------")
    auto stats = insertion_sort(arr);
    pl("Sorted array:")
    print_vector(arr);
    cout << "Comparisons: " << stats.comparisons << ", Swaps: " << stats.swaps << endl;
}

void test_QuickSort() {
    pl("Testing functionalities of Quick Sort")
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    pl("------------------------Quick Sort (First element pivot)------------------------")
    vector<int> arr_first = arr;
    auto stats_first = QuickSort::quick_sort(arr_first, QuickSort::FIRST);
    pl("Sorted array:")
    print_vector(arr_first);
    cout << "Comparisons: " << stats_first.comparisons << ", Swaps: " << stats_first.swaps << endl;

    pl("------------------------Quick Sort (Last element pivot)------------------------")
    vector<int> arr_last = arr;
    auto stats_last = QuickSort::quick_sort(arr_last, QuickSort::LAST);
    pl("Sorted array:")
    print_vector(arr_last);
    cout << "Comparisons: " << stats_last.comparisons << ", Swaps: " << stats_last.swaps << endl;
    
    pl("------------------------Quick Sort (Random element pivot)------------------------")
    vector<int> arr_random = arr;
    auto stats_random = QuickSort::quick_sort(arr_random, QuickSort::RANDOM);
    pl("Sorted array:")
    print_vector(arr_random);
    cout << "Comparisons: " << stats_random.comparisons << ", Swaps: " << stats_random.swaps << endl;
}

void test_MergeSort() {
    pl("Testing functionalities of Merge Sort")
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    pl("------------------------Merge Sort------------------------")
    auto stats = MergeSort::merge_sort(arr);
    pl("Sorted array:")
    print_vector(arr);
    cout << "Comparisons: " << stats.comparisons << ", Swaps: " << stats.swaps << endl;
}

void test_HeapSort() {
    pl("Testing functionalities of Heap Sort")
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    pl("------------------------Heap Sort------------------------")
    auto stats = HeapSort::heap_sort(arr);
    pl("Sorted array:")
    print_vector(arr);
    cout << "Comparisons: " << stats.comparisons << ", Swaps: " << stats.swaps << endl;
}