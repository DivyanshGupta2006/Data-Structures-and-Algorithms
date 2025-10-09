#include<iostream>
#include "Heap.h"

using namespace std;

#define pl(a) cout << a << "\n";

void test_Heap() {
    pl("Testing functionalities of Heap")

    pl("------------------------Testing Max-Heap------------------------")
    // create a new max-heap object (default behavior)
    Heap<int> max_heap;

    // push elements into the max-heap
    max_heap.push(30);
    max_heap.push(10);
    max_heap.push(50);
    max_heap.push(20);
    max_heap.push(40);

    cout << "Size of max-heap: " << max_heap.getSize() << endl;
    cout << "Top element is: " << max_heap.top() << endl;

    cout << "Popping elements from max-heap: ";
    while (!max_heap.isEmpty()) {
        cout << max_heap.pop() << " ";
    }
    cout << "\n";
    cout << "Is max-heap empty? " << (max_heap.isEmpty() ? "Yes" : "No") << endl;


    pl("------------------------Testing Min-Heap------------------------")
    // create a new min-heap object using std::greater
    Heap<int, std::greater<int>> min_heap;

    // push elements into the min-heap
    min_heap.push(30);
    min_heap.push(10);
    min_heap.push(50);
    min_heap.push(20);
    min_heap.push(40);

    cout << "Size of min-heap: " << min_heap.getSize() << endl;
    cout << "Top element is: " << min_heap.top() << endl;

    cout << "Popping elements from min-heap: ";
    while (!min_heap.isEmpty()) {
        cout << min_heap.pop() << " ";
    }
    cout << "\n";
    cout << "Is min-heap empty? " << (min_heap.isEmpty() ? "Yes" : "No") << endl;
}