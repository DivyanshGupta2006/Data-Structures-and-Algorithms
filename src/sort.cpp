#include <iostream>

// Structure to hold statistics for each sort
struct SortStats {
    long long comparisons;
    long long swaps;
    int max_recursion_depth;
};

// --- Utility Functions ---

// Resets stats to zero
void resetStats(SortStats& stats) {
    stats.comparisons = 0;
    stats.swaps = 0;
    stats.max_recursion_depth = 0;
}

// Swaps two integer values
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Prints an array
void print_array(const int arr[], int size, const char* prefix = "") {
    std::cout << prefix;
    if (size == 0) {
        std::cout << "[empty]";
    }
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// A simple pseudo-random number generator since <cstdlib> is not allowed
unsigned int pseudo_rand() {
    static unsigned int seed = 12345;
    seed = (8253729 * seed + 2396403);
    return seed;
}

// --- Sorting Algorithms ---

// 1. Bubble Sort
void bubble_sort_basic(int arr[], int n, SortStats& stats) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            stats.comparisons++;
            if (arr[j] > arr[j + 1]) {
                stats.swaps++;
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubble_sort_optimized(int arr[], int n, SortStats& stats) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            stats.comparisons++;
            if (arr[j] > arr[j + 1]) {
                stats.swaps++;
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break; // Stop early if no swaps in a pass
        }
    }
}

// 2. Selection Sort
void selection_sort(int arr[], int n, SortStats& stats) {
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
            swap(arr[min_idx], arr[i]);
        }
    }
}

// 3. Insertion Sort
void insertion_sort(int arr[], int n, SortStats& stats) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && (stats.comparisons++, arr[j] > key)) {
            arr[j + 1] = arr[j];
            stats.swaps++;
            j--;
        }
        arr[j + 1] = key;
        if(j != i - 1) stats.swaps++; // Count the final placement as a swap
    }
}

// 4. Quick Sort
namespace QuickSort {
    enum PivotType { FIRST, LAST, RANDOM };

    int partition(int arr[], int low, int high, PivotType pivot_type, SortStats& stats) {
        int pivot_index;
        if (pivot_type == FIRST) {
            pivot_index = low;
        } else if (pivot_type == LAST) {
            pivot_index = high;
        } else { // RANDOM
            pivot_index = low + pseudo_rand() % (high - low + 1);
        }

        swap(arr[pivot_index], arr[high]);
        stats.swaps++;
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            stats.comparisons++;
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
                stats.swaps++;
            }
        }
        swap(arr[i + 1], arr[high]);
        stats.swaps++;
        return (i + 1);
    }

    void quick_sort_recursive(int arr[], int low, int high, PivotType pivot_type, SortStats& stats, int depth) {
        if (low < high) {
            if (depth > stats.max_recursion_depth) {
                stats.max_recursion_depth = depth;
            }
            int pi = partition(arr, low, high, pivot_type, stats);
            quick_sort_recursive(arr, low, pi - 1, pivot_type, stats, depth + 1);
            quick_sort_recursive(arr, pi + 1, high, pivot_type, stats, depth + 1);
        }
    }
}

// 5. Merge Sort
namespace MergeSort {
    void merge(int arr[], int l, int m, int r, SortStats& stats) {
        int n1 = m - l + 1;
        int n2 = r - m;

        // Using dynamic arrays for auxiliary space
        int* L = new int[n1];
        int* R = new int[n2];

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
        }

        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];

        delete[] L;
        delete[] R;
    }

    void merge_sort_recursive(int arr[], int l, int r, SortStats& stats) {
        if (l < r) {
            int m = l + (r - l) / 2;
            merge_sort_recursive(arr, l, m, stats);
            merge_sort_recursive(arr, m + 1, r, stats);
            merge(arr, l, m, r, stats);
        }
    }

    int min(int x, int y) { return (x<y)? x :y; }

    void merge_sort_iterative(int arr[], int n, SortStats& stats) {
       for (int curr_size = 1; curr_size <= n-1; curr_size = 2*curr_size) {
           for (int left_start = 0; left_start < n-1; left_start += 2*curr_size) {
               int mid = min(left_start + curr_size - 1, n-1);
               int right_end = min(left_start + 2*curr_size - 1, n-1);
               merge(arr, left_start, mid, right_end, stats);
           }
       }
    }
}

// 6. Heap Sort
namespace HeapSort {
    void heapify(int arr[], int n, int i, SortStats& stats) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && (stats.comparisons++, arr[l] > arr[largest]))
            largest = l;

        if (r < n && (stats.comparisons++, arr[r] > arr[largest]))
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            stats.swaps++;
            heapify(arr, n, largest, stats);
        }
    }

    void heap_sort(int arr[], int n, SortStats& stats, bool show_states) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i, stats);
        }
        if (show_states) {
            print_array(arr, n, "Initial heap state: ");
        }

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            stats.swaps++;
            if (show_states) {
                 print_array(arr, n, "Intermediate state: ");
            }
            heapify(arr, i, 0, stats);
        }
    }
}

// --- Analysis and Main Function ---

void analyze_sort(const char* name, void (*sort_func)(int[], int, SortStats&)) {
    std::cout << "\n--- Analyzing " << name << " ---" << std::endl;
    SortStats stats;

    int test_cases[][10] = {
        {}, // Empty
        {5}, // Single
        {1, 2, 3, 4, 5}, // Sorted
        {5, 4, 3, 2, 1}, // Reverse
        {5, 5, 5, 5, 5}, // Identical
        {4, 5, 2, 1, 3} // Normal
    };
    int sizes[] = {0, 1, 5, 5, 5, 5};
    const char* case_names[] = {"Empty", "Single", "Sorted", "Reverse", "Identical", "Normal"};

    for (int i = 0; i < 6; ++i) {
        int n = sizes[i];
        int* arr = new int[n];
        for(int j=0; j<n; ++j) arr[j] = test_cases[i][j];

        resetStats(stats);
        sort_func(arr, n, stats);
        std::cout << case_names[i] << " Case (n=" << n << "): ";
        std::cout << "Cmp: " << stats.comparisons << ", Swaps: " << stats.swaps << std::endl;
        delete[] arr;
    }
}


int main() {
    SortStats stats;

    // --- 1. Bubble Sort ---
    std::cout << "--- 1. Bubble Sort Analysis ---" << std::endl;
    analyze_sort("Bubble Sort Basic", bubble_sort_basic);
    analyze_sort("Bubble Sort Optimized", bubble_sort_optimized);
    std::cout << "Observation: Optimized version performs significantly fewer comparisons on already sorted data." << std::endl;

    // --- 2. Selection Sort ---
    std::cout << "\n--- 2. Selection Sort Analysis ---" << std::endl;
    analyze_sort("Selection Sort", selection_sort);
    std::cout << "Observation: Number of swaps is consistently low (<= n-1). Comparisons are always O(n^2)." << std::endl;

    // --- 3. Insertion Sort ---
    std::cout << "\n--- 3. Insertion Sort Analysis ---" << std::endl;
    analyze_sort("Insertion Sort", insertion_sort);
    int nearly_sorted[] = {1, 2, 4, 3, 5, 6};
    resetStats(stats);
    insertion_sort(nearly_sorted, 6, stats);
    std::cout << "Nearly Sorted Case (n=6): Cmp: " << stats.comparisons << ", Swaps: " << stats.swaps << std::endl;
    std::cout << "Observation: Very few comparisons/swaps on sorted and nearly sorted data, showing its strength." << std::endl;

    // --- 4. Quick Sort ---
    std::cout << "\n--- 4. Quick Sort Analysis ---" << std::endl;
    int quick_arr[] = {10, 7, 8, 9, 1, 5};
    int sorted_quick[] = {1, 5, 7, 8, 9, 10};
    // First element pivot
    resetStats(stats);
    QuickSort::quick_sort_recursive(quick_arr, 0, 5, QuickSort::FIRST, stats, 1);
    std::cout << "First Pivot (Random): Cmp: " << stats.comparisons << ", Swaps: " << stats.swaps << ", Depth: " << stats.max_recursion_depth << std::endl;
    resetStats(stats);
    QuickSort::quick_sort_recursive(sorted_quick, 0, 5, QuickSort::FIRST, stats, 1);
    std::cout << "First Pivot (Sorted): Cmp: " << stats.comparisons << ", Swaps: " << stats.swaps << ", Depth: " << stats.max_recursion_depth << " (Worst case)" << std::endl;
    // ... similar tests for LAST and RANDOM pivots ...
    std::cout << "Observation: Random pivot gives better performance on average, especially on sorted/reverse data, avoiding worst-case stack depth." << std::endl;

    // --- 5. Merge Sort ---
    std::cout << "\n--- 5. Merge Sort Analysis ---" << std::endl;
    analyze_sort("Merge Sort Recursive", [](int a[], int n, SortStats& s){ MergeSort::merge_sort_recursive(a, 0, n-1, s); });
    analyze_sort("Merge Sort Iterative", [](int a[], int n, SortStats& s){ MergeSort::merge_sort_iterative(a, n, s); });
    std::cout << "Observation: Performance is consistent across all cases. Auxiliary memory usage is O(n)." << std::endl;

    // --- 6. Heap Sort ---
    std::cout << "\n--- 6. Heap Sort Analysis ---" << std::endl;
    analyze_sort("Heap Sort", [](int a[], int n, SortStats& s){ HeapSort::heap_sort(a, n, s, false); });
    int heap_state_arr[] = {4, 10, 3, 5, 1};
    resetStats(stats);
    std::cout << "Heap Sort Intermediate States:" << std::endl;
    print_array(heap_state_arr, 5, "Original array: ");
    HeapSort::heap_sort(heap_state_arr, 5, stats, true);
    print_array(heap_state_arr, 5, "Final sorted array: ");

    // --- Theoretical Questions ---
    // std::cout << "\n\n--- Theoretical Questions ---" << std::endl;
    // std::cout << "1. Complexities:" << std::endl;
    // std::cout << "   - Bubble:     Best O(n), Avg/Worst O(n^2), Space O(1)" << std::endl;
    // std::cout << "   - Selection:  All cases O(n^2), Space O(1)" << std::endl;
    // std::cout << "   - Insertion:  Best O(n), Avg/Worst O(n^2), Space O(1)" << std::endl;
    // std::cout << "   - Quick:      Best/Avg O(n log n), Worst O(n^2), Space O(log n)" << std::endl;
    // std::cout << "   - Merge:      All cases O(n log n), Space O(n)" << std::endl;
    // std::cout << "   - Heap:       All cases O(n log n), Space O(1)" << std::endl;
    //
    // std::cout << "\n2. Stability:" << std::endl;
    // std::cout << "   - Stable (preserve relative order of equal elements): Bubble, Insertion, Merge." << std::endl;
    // std::cout << "   - Unstable: Selection, Quick, Heap." << std::endl;
    //
    // std::cout << "\n3. Large-Scale Data Usability:" << std::endl;
    // std::cout << "   - Quick Sort, Merge Sort, and Heap Sort are usable due to O(n log n) time." << std::endl;
    // std::cout << "   - O(n^2) algorithms are too slow for millions of elements." << std::endl;
    //
    // std::cout << "\n4. Recursive vs. Iterative Memory:" << std::endl;
    // std::cout << "   - Recursive approaches use call stack memory. Deep recursion (like Quick Sort on sorted data) can cause stack overflow." << std::endl;
    // std::cout << "   - Iterative approaches use a fixed amount of memory or heap-allocated memory, avoiding stack depth issues." << std::endl;
    //
    // std::cout << "\n5. Real-World Applications:" << std::endl;
    // std::cout << "   - Insertion Sort: For small arrays or nearly-sorted data (it's very fast in this case)." << std::endl;
    // std::cout << "   - Quick Sort: A good general-purpose sort, often the fastest in practice on average." << std::endl;
    // std::cout << "   - Merge Sort: When stability is required, or for external sorting on data that doesn't fit in memory." << std::endl;
    // std::cout << "   - Heap Sort: When a worst-case O(n log n) guarantee is needed with O(1) space." << std::endl;

    return 0;
}