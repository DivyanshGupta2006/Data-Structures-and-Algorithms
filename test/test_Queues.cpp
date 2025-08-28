#include<iostream>
#include "Queue_LinkedList.h"
#include "Queue_Array.h"
#include "Queue_Stack.h"

using namespace std;

#define pl(a) cout << a << "\n";

void test_ArrayQueue() {
    pl("Testing functionalities of Queue using Array")

    // create a new array-based queue object
    Queue_Array<int> queue;

    pl("------------------------Checking enqueue operation------------------------")
    // enqueue elements into the queue
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // print queue
    queue.display();

    pl("------------------------Checking dequeue operation------------------------")
    // dequeue an element and print the dequeued element
    int dequeued_element = queue.dequeue();
    cout << "Dequeued element: " << dequeued_element << endl;

    // print queue after dequeue
    queue.display();

    pl("------------------------Checking peek operation------------------------")
    // peek at the front element and print it
    int front_element = queue.peek();
    cout << "Front element is: " << front_element << endl;

    // print queue after peek
    queue.display();

    pl("------------------------Checking isEmpty and isFull------------------------")
    // check if the queue is empty and full
    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is queue full? " << (queue.isFull() ? "Yes" : "No") << endl;

    pl("------------------------Enqueuing to full and Dequeuing to empty------------------------")
    // fill the queue to test isFull and potential overflow
    while (!queue.isFull()) {
        queue.enqueue(queue.peek() + 10); // Enqueue some more elements
    }
    cout << "Is queue full? " << (queue.isFull() ? "Yes" : "No") << endl;
    // queue.enqueue(100); // This would throw an exception if uncommented

    // Empty the queue to test isEmpty and potential underflow
    while (!queue.isEmpty()) {
        queue.dequeue();
    }
    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
    // queue.dequeue(); // This would throw an exception if uncommented
}

void test_LinkedListQueue() {
    pl("Testing functionalities of Queue using Linked List")

    // create a new linked list-based queue object
    Queue_LinkedList<int> queue;

    pl("------------------------Checking enqueue operation------------------------")
    // enqueue elements into the queue
    queue.enqueue(100);
    queue.enqueue(200);
    queue.enqueue(300);

    // print queue
    queue.display();

    pl("------------------------Checking dequeue operation------------------------")
    // dequeue an element and print the dequeued element
    int dequeued_element = queue.dequeue();
    cout << "Dequeued element: " << dequeued_element << endl;

    // print queue after dequeue
    queue.display();

    pl("------------------------Checking peek operation------------------------")
    // peek at the front element and print it
    int front_element = queue.peek();
    cout << "Front element is: " << front_element << endl;

    // print queue after peek
    queue.display();

    pl("------------------------Checking isEmpty------------------------")
    // check if the queue is empty
    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    pl("------------------------Dequeuing all elements------------------------")
    // Empty the queue
    while (!queue.isEmpty()) {
        queue.dequeue();
    }
    cout << "Is queue empty after dequeuing all elements? " << (queue.isEmpty() ? "Yes" : "No") << endl;
    // queue.dequeue(); // This would throw an exception if uncommented
}

void test_StackQueue() {
    pl("Testing functionalities of Queue using Stack")

    // create a new linked list-based queue object
    Queue_Stack<int> queue;

    pl("------------------------Checking enqueue operation------------------------")
    // enqueue elements into the queue
    queue.enqueue(100);
    queue.enqueue(200);
    queue.enqueue(300);

    // print queue
    queue.display();

    pl("------------------------Checking dequeue operation------------------------")
    // dequeue an element and print the dequeued element
    int dequeued_element = queue.dequeue();
    cout << "Dequeued element: " << dequeued_element << endl;

    // print queue after dequeue
    queue.display();

    pl("------------------------Checking peek operation------------------------")
    // peek at the front element and print it
    int front_element = queue.peek();
    cout << "Front element is: " << front_element << endl;

    // print queue after peek
    queue.display();

    pl("------------------------Checking isEmpty------------------------")
    // check if the queue is empty
    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    pl("------------------------Dequeuing all elements------------------------")
    // Empty the queue
    while (!queue.isEmpty()) {
        queue.dequeue();
    }
    cout << "Is queue empty after dequeuing all elements? " << (queue.isEmpty() ? "Yes" : "No") << endl;
    // queue.dequeue(); // This would throw an exception if uncommented
}
