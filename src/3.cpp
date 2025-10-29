#include "Binary_Search_Tree.h"
#include <iostream>

// This function assumes the Node struct is accessible.
// Since it's private in your class, this function would
// ideally be a member of the class, as implemented in the
// original Binary_Search_Tree.h file you have.
// This is a standalone equivalent for demonstration.
template<typename T>
typename Binary_Search_Tree<T>::Node* findMin(typename Binary_Search_Tree<T>::Node* node) {
    while (node && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template<typename T>
typename Binary_Search_Tree<T>::Node* inorderSuccessor(typename Binary_Search_Tree<T>::Node* root, typename Binary_Search_Tree<T>::Node* n) {
    if (n->right != nullptr) {
        return findMin(n->right);
    }

    typename Binary_Search_Tree<T>::Node* successor = nullptr;
    while (root != nullptr) {
        if (n->value < root->value) {
            successor = root;
            root = root->left;
        } else if (n->value > root->value) {
            root = root->right;
        } else {
            break;
        }
    }
    return successor;
}

int main() {
    Binary_Search_Tree<int> bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Note: To test this properly, you need a way to get a pointer
    // to a specific node, which is not currently in your public API.
    // The inorderSuccessor function in your class is the best way to use this.
    std::cout << "Using the class method:" << std::endl;
    std::cout << "Inorder successor of 40 is " << bst.inorderSuccessor(40) << std::endl;

    return 0;
}