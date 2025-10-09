#include<iostream>
#include "Binary_Search_Tree.h"

using namespace std;

#define pl(a) cout << a << "\n";

void test_BinarySearchTree() {
    pl("Testing functionalities of Binary Search Tree")

    // create a new binary search tree object containing data of int type
    Binary_Search_Tree<int> bst;

    pl("------------------------Checking insertion------------------------")
    // insert elements
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    pl("------------------------Checking traversals------------------------")
    // print traversals
    cout << "Inorder traversal: ";
    bst.inorder();
    cout << "Preorder traversal: ";
    bst.preorder();
    cout << "Postorder traversal: ";
    bst.postorder();
    cout << "Level order traversal: ";
    bst.levelOrder();

    pl("------------------------Checking searching------------------------")
    // search for elements
    cout << "Is 40 present? " << (bst.search(40) ? "Yes" : "No") << endl;
    cout << "Is 90 present? " << (bst.search(90) ? "Yes" : "No") << endl;

    pl("------------------------Checking min and max finding------------------------")
    // finding min and max
    cout << "The min value is " << bst.findMin() << endl;
    cout << "The max value is " << bst.findMax() << endl;

    pl("------------------------Checking height and depth------------------------")
    // finding height and depth
    cout << "Height of the tree is " << bst.height() << endl;
    cout << "Depth of 40 is " << bst.depth(40) << endl;
    cout << "Depth of 90 is " << bst.depth(90) << endl;

    pl("------------------------Checking inorder successor------------------------")
    // finding inorder successor
    cout << "Inorder successor of 20 is " << bst.inorderSuccessor(20) << endl;
    cout << "Inorder successor of 40 is " << bst.inorderSuccessor(40) << endl;
    cout << "Inorder successor of 60 is " << bst.inorderSuccessor(60) << endl;

    pl("------------------------Checking deletion------------------------")
    // delete elements
    pl("Deleting 20")
    bst.remove(20);
    cout << "Inorder traversal after deleting 20: ";
    bst.inorder();

    pl("Deleting 30")
    bst.remove(30);
    cout << "Inorder traversal after deleting 30: ";
    bst.inorder();

    pl("Deleting 50")
    bst.remove(50);
    cout << "Inorder traversal after deleting 50: ";
    bst.inorder();

    pl("------------------------Checking isEmpty------------------------")
    // check if the tree is empty
    cout << "Is tree empty? " << (bst.isEmpty() ? "Yes" : "No") << endl;
}