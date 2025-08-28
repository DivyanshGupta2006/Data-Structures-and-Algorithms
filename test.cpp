#include<iostream>
#include "LinkedList.h"
#include "Doubly_LinkedList.h"
#include "Circular_LinkedList.h"
#include "Circular_Doubly_LinkedList.h"
#include "Queue_Array.h"
#include "Queue_LinkedList.h"
#include "Stack_Array.h"
#include "Stack_LinkedList.h"
#include "Stack_Queue.h"

using namespace std;

#define pl(a) cout << a << "\n";

void test_LinkedList() {
    pl("Testing functionalities of Singly Linked List")

    // create a new singly linked list object containing data of int type
    LinkedList<int> list;

    pl("------------------------Checking insertion at beginning------------------------")
    // insert two elements at beginning
    list.insert_begin(1);
    list.insert_begin(2);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking insertion at end------------------------")
    // insert two elements at end
    list.insert_end(3);
    list.insert_end(4);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking insertion at index------------------------")
    // insert two elements at index 2
    list.insert_at(5, 2);
    list.insert_at(6, 2);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion at beginning------------------------")
    // delete an element from beginning
    list.delete_begin();

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion at end------------------------")
    // delete an element from end
    list.delete_end();

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion at index------------------------")
    // delete an element at index 1
    list.delete_at(1);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion by elements------------------------")
    // delete elements present and not present in list
    list.delete_element(5);
    list.delete_element(0);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking searching------------------------")
    // search elements present and not present in list
    cout << "The pointer to Node containing '3' is " << list.find(3) << endl;
    cout << "The index of Node containing '3' is " << list.search(3) << endl;
    cout << "The pointer to Node containing '6' is " << list.find(6) << endl;
    cout << "The index of Node containing '6' is " << list.search(6) << endl;

    // create another list to merge
    LinkedList<int> add;
    add.insert_begin(5);
    add.insert_begin(4);
    add.insert_begin(0);
    add.insert_begin(2);

    pl("------------------------Checking merging------------------------")

    pl("Trying to merge:")
    list.display();
    pl("With:")
    add.display();

    // merge add to list
    pl("Resulting:")
    list.merge(add);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking min and max finding------------------------")
    // finding min and max
    cout << "The min value is " << list.findMin()->value << endl;
    cout << "The max value is " << list.findMax()->value << endl;

    pl("------------------------Checking if the list is circular------------------------")
    cout << "The list is circular: " << list.isCircular() << endl;

    pl("------------------------Checking reversing------------------------")
    // reversing the list
    list.reverse();

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking sorting------------------------")
    // sorting the list
    list.sort();

    // print list and size
    list.display();
    pl(list.getSize())
}

void test_Circular_LinkedList() {
    pl("Testing functionalities of Circular Singly Linked List")

    // create a new circular linked list object containing data of int type
    Circular_LinkedList<int> list;

    pl("------------------------Checking insertion at beginning------------------------")
    // insert two elements at beginning
    list.insert_begin(1);
    list.insert_begin(2);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking insertion at end------------------------")
    // insert two elements at end
    list.insert_end(3);
    list.insert_end(4);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking insertion at index------------------------")
    // insert two elements at index 2
    list.insert_at(5, 2);
    list.insert_at(6, 2);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion at beginning------------------------")
    // delete an element from beginning
    list.delete_begin();

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion at end------------------------")
    // delete an element from end
    list.delete_end();

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion at index------------------------")
    // delete an element at index 1
    list.delete_at(1);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion by elements------------------------")
    // delete elements present and not present in list
    list.delete_element(5);
    list.delete_element(0);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking searching------------------------")
    // search elements present and not present in list
    cout << "The pointer to Node containing '3' is " << list.find(3) << endl;
    cout << "The index of Node containing '3' is " << list.search(3) << endl;
    cout << "The pointer to Node containing '6' is " << list.find(6) << endl;
    cout << "The index of Node containing '6' is " << list.search(6) << endl;

    // create another list to merge
    Circular_LinkedList<int> add;
    add.insert_begin(5);
    add.insert_begin(4);
    add.insert_begin(0);
    add.insert_begin(2);

    pl("------------------------Checking merging------------------------")

    pl("Trying to merge:")
    list.display();
    pl("With:")
    add.display();

    // merge add to list
    pl("Resulting:")
    list.merge(add);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking min and max finding------------------------")
    // finding min and max
    cout << "The min value is " << list.findMin()->value << endl;
    cout << "The max value is " << list.findMax()->value << endl;

    pl("------------------------Checking if the list is circular------------------------")
    cout << "The list is circular: " << list.isCircular() << endl;

    pl("------------------------Checking reversing------------------------")
    // reversing the list
    list.reverse();

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking sorting------------------------")
    // sorting the list
    list.sort();

    // print list and size
    list.display();
    pl(list.getSize())
}

void test_Doubly_LinkedList() {
    pl("Testing functionalities of Doubly Linked List")

    // create a new doubly linked list object containing data of int type
    Doubly_LinkedList<int> list;

    pl("------------------------Checking insertion at beginning------------------------")
    // insert two elements at beginning
    list.insert_begin(1);
    list.insert_begin(2);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking insertion at end------------------------")
    // insert two elements at end
    list.insert_end(3);
    list.insert_end(4);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking insertion at index------------------------")
    // insert two elements at index 2
    list.insert_at(5, 2);
    list.insert_at(6, 2);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion at beginning------------------------")
    // delete an element from beginning
    list.delete_begin();

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion at end------------------------")
    // delete an element from end
    list.delete_end();

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion at index------------------------")
    // delete an element at index 1
    list.delete_at(1);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion by elements------------------------")
    // delete elements present and not present in list
    list.delete_element(5);
    list.delete_element(0);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking searching------------------------")
    // search elements present and not present in list
    cout << "The pointer to Node containing '3' is " << list.find(3) << endl;
    cout << "The index of Node containing '3' is " << list.search(3) << endl;
    cout << "The pointer to Node containing '6' is " << list.find(6) << endl;
    cout << "The index of Node containing '6' is " << list.search(6) << endl;

    // create another list to merge
    Doubly_LinkedList<int> add;
    add.insert_begin(5);
    add.insert_begin(4);
    add.insert_begin(0);
    add.insert_begin(2);

    pl("------------------------Checking merging------------------------")

    pl("Trying to merge:")
    list.display();
    pl("With:")
    add.display();

    // merge add to list
    pl("Resulting:")
    list.merge(add);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking min and max finding------------------------")
    // finding min and max
    cout << "The min value is " << list.findMin()->value << endl;
    cout << "The max value is " << list.findMax()->value << endl;

    pl("------------------------Checking if the list is circular------------------------")
    cout << "The list is circular: " << list.isCircular() << endl;

    pl("------------------------Checking reversing------------------------")
    // reversing the list
    list.reverse();

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking sorting------------------------")
    // sorting the list
    list.sort();

    // print list and size
    list.display();
    pl(list.getSize())
}

void test_Circular_Doubly_LinkedList() {
    pl("Testing functionalities of Circular Doubly Linked List")

    // create a new circular doubly linked list object containing data of int type
    Circular_Doubly_LinkedList<int> list;

    pl("------------------------Checking insertion at beginning------------------------")
    // insert two elements at beginning
    list.insert_begin(1);
    list.insert_begin(2);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking insertion at end------------------------")
    // insert two elements at end
    list.insert_end(3);
    list.insert_end(4);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking insertion at index------------------------")
    // insert two elements at index 2
    list.insert_at(5, 2);
    list.insert_at(6, 2);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion at beginning------------------------")
    // delete an element from beginning
    list.delete_begin();

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion at end------------------------")
    // delete an element from end
    list.delete_end();

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion at index------------------------")
    // delete an element at index 1
    list.delete_at(1);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking deletion by elements------------------------")
    // delete elements present and not present in list
    list.delete_element(5);
    list.delete_element(0);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking searching------------------------")
    // search elements present and not present in list
    cout << "The pointer to Node containing '3' is " << list.find(3) << endl;
    cout << "The index of Node containing '3' is " << list.search(3) << endl;
    cout << "The pointer to Node containing '6' is " << list.find(6) << endl;
    cout << "The index of Node containing '6' is " << list.search(6) << endl;

    // create another list to merge
    Circular_Doubly_LinkedList<int> add;
    add.insert_begin(5);
    add.insert_begin(4);
    add.insert_begin(0);
    add.insert_begin(2);

    pl("------------------------Checking merging------------------------")

    pl("Trying to merge:")
    list.display();
    pl("With:")
    add.display();

    // merge add to list
    pl("Resulting:")
    list.merge(add);

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking min and max finding------------------------")
    // finding min and max
    cout << "The min value is " << list.findMin()->value << endl;
    cout << "The max value is " << list.findMax()->value << endl;

    pl("------------------------Checking if the list is circular------------------------")
    cout << "The list is circular: " << list.isCircular() << endl;

    pl("------------------------Checking reversing------------------------")
    // reversing the list
    list.reverse();

    // print list and size
    list.display();
    pl(list.getSize())

    pl("------------------------Checking sorting------------------------")
    // sorting the list
    list.sort();

    // print list and size
    list.display();
    pl(list.getSize())
}

void test_ArrayStack() {
    pl("Testing functionalities of Stack using Linked List")

    // create a new array-based stack object
    Stack_Array<int> stack;

    pl("------------------------Checking push operation------------------------")
    // push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // print stack
    stack.display();

    pl("------------------------Checking pop operation------------------------")
    // pop an element and print the popped element
    int popped_element = stack.pop();
    cout << "Popped element: " << popped_element << endl;

    // print stack after pop
    stack.display();

    pl("------------------------Checking peek operation------------------------")
    // peek at the top element and print it
    int top_element = stack.peek();
    cout << "Top element is: " << top_element << endl;

    // print stack after peek
    stack.display();

    pl("------------------------Checking isEmpty and isFull------------------------")
    // check if the stack is empty and full
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (stack.isFull() ? "Yes" : "No") << endl;
}

void test_LinkedListStack() {
    pl("Testing functionalities of Stack using Array")

    // create a new array-based stack object
    Stack_LinkedList<int> stack;

    pl("------------------------Checking push operation------------------------")
    // push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // print stack
    stack.display();

    pl("------------------------Checking pop operation------------------------")
    // pop an element and print the popped element
    int popped_element = stack.pop();
    cout << "Popped element: " << popped_element << endl;

    // print stack after pop
    stack.display();

    pl("------------------------Checking peek operation------------------------")
    // peek at the top element and print it
    int top_element = stack.peek();
    cout << "Top element is: " << top_element << endl;

    // print stack after peek
    stack.display();

    pl("------------------------Checking isEmpty------------------------")
    // check if the stack is empty and full
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
}

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

void test_QueueStack() {
    pl("Testing functionalities of Stack using Queue")

    // create a new array-based stack object
    Stack_Queue<int> stack;

    pl("------------------------Checking push operation------------------------")
    // push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // print stack
    stack.display();

    pl("------------------------Checking pop operation------------------------")
    // pop an element and print the popped element
    int popped_element = stack.pop();
    cout << "Popped element: " << popped_element << endl;

    // print stack after pop
    stack.display();

    pl("------------------------Checking peek operation------------------------")
    // peek at the top element and print it
    int top_element = stack.peek();
    cout << "Top element is: " << top_element << endl;

    // print stack after peek
    stack.display();

    pl("------------------------Checking isEmpty------------------------")
    // check if the stack is empty and full
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
}

void test_StackQueue() {
    pl("Testing functionalities of Queue using Stack")

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

int main() {
    // test_LinkedList();
    // test_Circular_LinkedList();
    // test_Doubly_LinkedList();
    // test_Circular_Doubly_LinkedList();
    // test_ArrayStack();
    // test_LinkedListStack();
    // test_ArrayQueue();
    // test_LinkedListQueue();
    // test_QueueStack();
    test_StackQueue();
    return 0;
}
