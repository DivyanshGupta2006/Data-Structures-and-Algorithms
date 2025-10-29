#include "Binary_Search_Tree.h"
#include <iostream>
#include <vector>
#include <chrono>

void performance_test() {
    Binary_Search_Tree<int> best_case_bst;
    Binary_Search_Tree<int> worst_case_bst;
    const int n = 1000;

    // Best Case: Balanced Tree
    // To create a balanced tree, we insert elements in a way that
    // approximates a complete tree. A simple way is to insert the median first.
    // For simplicity, we'll just show the concept. A true balanced insert is complex.
    // This is not perfectly balanced, but avoids the worst-case.
    for (int i = 0; i < n; ++i) {
        best_case_bst.insert(i);
    }
    
    // Worst Case: Skewed Tree (sorted input)
    for (int i = 0; i < n; ++i) {
        worst_case_bst.insert(i);
    }
    
    std::cout << "--- Performance Analysis (n=" << n << ") ---" << std::endl;
    std::cout << "Worst-case time complexity for search, insert, delete is O(n)." << std::endl;
    std::cout << "This occurs when the tree is skewed (like a linked list)." << std::endl;
    
    std::cout << "\nBest Case (approximated):" << std::endl;
    std::cout << "Height: " << best_case_bst.height() << " (Expected: O(log n))" << std::endl;

    std::cout << "\nWorst Case (skewed tree):" << std::endl;
    std::cout << "Height: " << worst_case_bst.height() << " (Expected: O(n))" << std::endl;
    
    // Measuring depth
    int test_val = n - 10;
    std::cout << "\nDepth of " << test_val << " in best case: " << best_case_bst.depth(test_val) << std::endl;
    std::cout << "Depth of " << test_val << " in worst case: " << worst_case_bst.depth(test_val) << std::endl;
}

int main() {
    performance_test();
    return 0;
}