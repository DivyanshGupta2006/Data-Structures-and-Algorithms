#include<iostream>
#include "LinkedList.h"
#include "Doubly_LinkedList.h"
#include "Circular_LinkedList.h"
#include "Circular_Doubly_LinkedList.h"

using namespace std;

#define pl(a) cout << a << "\n";

void run_test() {
    pl("Run this file to test functionalities")

    // create a new singly linked list object containing data of int type
    LinkedList<int> list;

    // insert two elements at beginning
    list.insert_begin(1);
    list.insert_begin(2);

    // print list and size
    list.display();
    cout << list.getSize() << endl;

    // insert two elements at end
    list.insert_end(3);
    list.insert_end(4);

    // print list and size
    list.display();
    cout << list.getSize() << endl;

    // insert two elements at index 2
    list.insert_at(5, 2);
    list.insert_at(6, 2);

    // print list and size
    list.display();
    cout << list.getSize() << endl;

    // delete an element from beginning
    list.delete_begin();

    // print list and size
    list.display();
    cout << list.getSize() << endl;

    // delete an element from end
    list.delete_end();

    // print list and size
    list.display();
    cout << list.getSize() << endl;

    // delete an element at index 1
    list.delete_at(1);

    // print list and size
    list.display();
    cout << list.getSize() << endl;

    // delete elements present and not present in list
    list.delete_element(5);
    list.delete_element(0);

    // print list and size
    list.display();
    cout << list.getSize() << endl;

    // find elements present and not present in list
    cout << "Position of '5' is " << list.find(5) << endl;
    cout << "Position of '6' is " << list.find(6) << endl;

}
