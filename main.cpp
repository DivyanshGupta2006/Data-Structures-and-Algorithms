#include<iostream>
#include "LinkedList.h"
#include "Doubly_LinkedList.h"
#include "Circular_LinkedList.h"
#include "Circular_Doubly_LinkedList.h"

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

int main() {

    test_LinkedList();
    // test_Circular_LinkedList();
    // test_Doubly_LinkedList();
    // test_Circular_Doubly_LinkedList();
    return 0;

}