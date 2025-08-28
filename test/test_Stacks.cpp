#include<iostream>
#include "Stack_Array.h"
#include "Stack_LinkedList.h"
#include "Stack_Queue.h"

using namespace std;

#define pl(a) cout << a << "\n";

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