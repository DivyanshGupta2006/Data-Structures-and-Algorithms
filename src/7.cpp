#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void printInorder(Node* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    std::cout << node->data << " ";
    printInorder(node->right);
}

int main() {
    std::cout << "Given inorder sequence: 1, 2, 3" << std::endl;
    std::cout << "Structurally distinct binary trees:" << std::endl;

    // Tree 1
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);
    std::cout << "Tree 1 inorder: ";
    printInorder(root1);
    std::cout << std::endl;
    // 
    // Tree 2
    Node* root2 = new Node(3);
    root2->left = new Node(2);
    root2->left->left = new Node(1);
    std::cout << "Tree 2 inorder: ";
    printInorder(root2);
    std::cout << std::endl;
    //     
    // Tree 3
    Node* root3 = new Node(1);
    root3->right = new Node(2);
    root3->right->right = new Node(3);
    std::cout << "Tree 3 inorder: ";
    printInorder(root3);
    std::cout << std::endl;
    //     
    // Tree 4
    Node* root4 = new Node(3);
    root4->left = new Node(1);
    root4->left->right = new Node(2);
    std::cout << "Tree 4 inorder: ";
    printInorder(root4);
    std::cout << std::endl;
    
    // Tree 5
    Node* root5 = new Node(1);
    root5->right = new Node(3);
    root5->right->left = new Node(2);
    std::cout << "Tree 5 inorder: ";
    printInorder(root5);
    std::cout << std::endl;

    return 0;
}