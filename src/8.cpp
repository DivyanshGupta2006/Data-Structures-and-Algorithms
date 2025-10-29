#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void printPreorder(Node* node) {
    if (node == nullptr) return;
    std::cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(Node* node) {
    if (node == nullptr) return;
    printPostorder(node->left);
    printPostorder(node->right);
    std::cout << node->data << " ";
}

int main() {
    // Tree 1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    
    // Tree 2
    Node* root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);

    std::cout << "Tree 1:" << std::endl;
    std::cout << "Preorder: ";
    printPreorder(root1);
    std::cout << std::endl;
    std::cout << "Postorder: ";
    printPostorder(root1);
    std::cout << std::endl;

    std::cout << "\nTree 2:" << std::endl;
    std::cout << "Preorder: ";
    printPreorder(root2);
    std::cout << std::endl;
    std::cout << "Postorder: ";
    printPostorder(root2);
    std::cout << std::endl;

    return 0;
}