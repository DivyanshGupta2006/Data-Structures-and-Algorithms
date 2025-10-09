#include<iostream>
#include "Queue_LinkedList.h"
#include "Queue_Array.h"
#include "Queue_Stack.h"
#include "Double_Queue.h"
#include "Priority_Queue.h"

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

void test_DoubleQueue() {
    pl("Testing functionalities of Double Ended Queue")

    // create a new deque object containing data of int type
    Double_Queue<int> dq;

    pl("------------------------Checking push_front operation------------------------")
    // push elements to the front
    dq.push_front(10);
    dq.push_front(20);
    dq.push_front(30);

    // print deque
    dq.display();

    pl("------------------------Checking push_back operation------------------------")
    // push elements to the back
    dq.push_back(40);
    dq.push_back(50);

    // print deque
    dq.display();

    pl("------------------------Checking pop_front operation------------------------")
    // pop an element from the front
    int front_element = dq.pop_front();
    cout << "Popped from front: " << front_element << endl;

    // print deque
    dq.display();

    pl("------------------------Checking pop_back operation------------------------")
    // pop an element from the back
    int back_element = dq.pop_back();
    cout << "Popped from back: " << back_element << endl;

    // print deque
    dq.display();

    pl("------------------------Checking front and back operations------------------------")
    // peek at the front and back elements
    cout << "Front element is: " << dq.front() << endl;
    cout << "Back element is: " << dq.back() << endl;

    // print deque
    dq.display();

    pl("------------------------Checking isEmpty and getSize------------------------")
    // check if the deque is empty and get its size
    cout << "Is deque empty? " << (dq.isEmpty() ? "Yes" : "No") << endl;
    cout << "Size of deque: " << dq.getSize() << endl;

    pl("------------------------Emptying the deque------------------------")
    // Empty the deque
    while (!dq.isEmpty()) {
        dq.pop_front();
    }
    cout << "Is deque empty after popping all elements? " << (dq.isEmpty() ? "Yes" : "No") << endl;
}

void test_PriorityQueue() {
    pl("Testing functionalities of Priority Queue")

    // create a new priority queue object containing data of int type
    Priority_Queue<int> pq;

    pl("------------------------Checking push operation------------------------")
    // push elements into the priority queue
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);

    pl("------------------------Checking getSize and isEmpty------------------------")
    cout << "Size of priority queue: " << pq.getSize() << endl;
    cout << "Is priority queue empty? " << (pq.isEmpty() ? "Yes" : "No") << endl;

    pl("------------------------Checking top operation------------------------")
    // view the top element
    cout << "Top element is: " << pq.top() << endl;

    pl("------------------------Checking pop operation------------------------")
    // pop elements from the priority queue
    cout << "Popped element: " << pq.pop() << endl;
    cout << "Top element after pop: " << pq.top() << endl;
    cout << "Popped element: " << pq.pop() << endl;
    cout << "Top element after pop: " << pq.top() << endl;

    pl("------------------------Emptying the priority queue------------------------")
    // Empty the priority queue
    while (!pq.isEmpty()) {
        cout << "Popping: " << pq.pop() << endl;
    }
    cout << "Is priority queue empty after popping all elements? " << (pq.isEmpty() ? "Yes" : "No") << endl;
}