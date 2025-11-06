#include<iostream>
#include "Binary_Search_Tree.h"
#include "AVL_Tree.h"
#include "2_3_4_tree.h"

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

void test_AVLTree() {
    pl("Testing functionalities of Binary Search Tree")

    AVL_Tree tree;
    std::string command;

    // Read commands from standard input until EOF
    while (std::cin >> command) {
        if (command == "INSERT") {
            int x;
            std::cin >> x;
            tree.INSERT(x);
        } else if (command == "DELETE") {
            int x;
            std::cin >> x;
            tree.DELETE(x);
        } else if (command == "FIND") {
            int x;
            std::cin >> x;
            tree.FIND(x);
        } else if (command == "PREV") {
            int x;
            std::cin >> x;
            tree.PREV(x);
        } else if (command == "NEXT") {
            int x;
            std::cin >> x;
            tree.NEXT(x);
        } else if (command == "PRINT") {
            std::string type;
            std::cin >> type;
            tree.PRINT(type);
        } else if (command == "RANGE_COUNT") {
            int L, R;
            std::cin >> L >> R;
            tree.RANGE_COUNT(L, R);
        } else if (command == "RANK") {
            int x;
            std::cin >> x;
            tree.RANK(x);
        } else if (command == "SELECT") {
            int k;
            std::cin >> k;
            tree.SELECT(k);
        } else if (command == "RANGE_SUM") {
            int L, R;
            std::cin >> L >> R;
            tree.RANGE_SUM(L, R);
        } else {
            // To clear the rest of the line for an unknown command
            std::string s;
            std::getline(std::cin, s);
        }
    }
}

void test_234Tree() {
        Tree_2_3_4 tree;
        std::string command;

        // Read commands from standard input until EOF
        while (std::cin >> command) {
            if (command == "INSERT") {
                int x;
                std::cin >> x;
                tree.INSERT(x);
            } else if (command == "DELETE") {
                int x;
                std::cin >> x;
                tree.DELETE(x);
            } else if (command == "FIND") {
                int x;
                std::cin >> x;
                tree.FIND(x);
            } else if (command == "PRINT") {
                std::string type;
                std::cin >> type;
                tree.PRINT(type);
            } else if (command == "BULK") {
                int n;
                std::cin >> n;
                if (n > 0) {
                    int* arr = new int[n];
                    for(int i = 0; i < n; ++i) {
                        std::cin >> arr[i];
                    }
                    tree.BULK(arr, n);
                    delete[] arr;
                } else {
                    // Handle n=0 case, e.g., clear the tree
                    int* arr = nullptr;
                    tree.BULK(arr, 0);
                }
            } else {
                // To clear the rest of the line for an unknown command
                std::string s;
                std::getline(std::cin, s);
            }
        }

        return 0;
    }
}