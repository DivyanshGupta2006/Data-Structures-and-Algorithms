#pragma once
#include <iostream>
#include <stdexcept>
#include "Queue_LinkedList.h"

template<typename T>
class Binary_Search_Tree {
private:
    struct Node {
        T value;
        Node *left;
        Node *right;

        Node(const T &data) : value(data), left(nullptr), right(nullptr) {}
    };

    Node *root;

    Node* insert(Node *node, const T &data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->value) {
             node->left = insert(node->left, data);
         } else if (data > node->value) {
             node->right = insert(node->right, data);
         }
         return node;
     }

     Node* remove(Node *node, const T &data) {
         if (node == nullptr) {
             return node;
         }
         if (data < node->value) {
             node->left = remove(node->left, data);
         } else if (data > node->value) {
             node->right = remove(node->right, data);
         } else {
             if (node->left == nullptr) {
                Node *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = findMin(node->right);
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }
        return node;
    }

    bool search(Node *node, const T &data) const {
        if (node == nullptr) {
            return false;
        }
        if (data == node->value) {
            return true;
        }
        return data < node->value ? search(node->left, data) : search(node->right, data);
    }

    void inorder(Node *node) const {
        if (node != nullptr) {
            inorder(node->left);
            std::cout << node->value << " ";
            inorder(node->right);
        }
    }

    void preorder(Node *node) const {
        if (node != nullptr) {
            std::cout << node->value << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node *node) const {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            std::cout << node->value << " ";
        }
    }

    Node* findMin(Node *node) const {
        Node *current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* findMax(Node *node) const {
        Node *current = node;
        while (current && current->right != nullptr) {
            current = current->right;
        }
        return current;
    }

    int height(Node *node) const {
        if (node == nullptr) {
            return -1;
        }
        return 1 + std::max(height(node->left), height(node->right));
    }

    int depth(Node *node, const T &data, int d) const {
        if (node == nullptr) {
            return -1;
        }
        if (node->value == data) {
            return d;
        }
        int downlevel = depth(node->left, data, d + 1);
        if (downlevel != -1) {
            return downlevel;
        }
        downlevel = depth(node->right, data, d + 1);
        return downlevel;
    }

    Node* find(Node *node, const T &data) const {
        if (node == nullptr || node->value == data) {
            return node;
        }
        if (data < node->value) {
            return find(node->left, data);
        }
        return find(node->right, data);
    }

    void destroy(Node* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    bool is_bst_helper(Node* current, Node* &prev){
        if(current == nullptr) return true;
        if(is_bst_helper(current->left, prev) == false) {
            return false;
        }
        if(prev != nullptr && current->key <= prev->key) return false;
        prev = current;
        return is_bst_helper(current->right,prev);
    }

    bool isBalancedUtil(Node* node, int& height) const {
            if (node == nullptr) {
                height = -1;
                return true;
            }

            int leftHeight, rightHeight;
            if (isBalancedUtil(node->left, leftHeight) &&
                isBalancedUtil(node->right, rightHeight) &&
                std::abs(leftHeight - rightHeight) <= 1) {
                height = std::max(leftHeight, rightHeight) + 1;
                return true;
                }
            return false;
        }

    int countLeavesUtil(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }
        return countLeavesUtil(node->left) + countLeavesUtil(node->right);
    }

    // int diameterUtil(Node* node, int& height) const {
    //     if (node == nullptr) {
    //         height = -1;
    //         return 0;
    //     }
    //     int leftHeight = 0, rightHeight = 0;
    //     int leftDiameter = diameterUtil(node->left, leftHeight);
    //     int rightDiameter = diameterUtil(node->right, rightHeight);
    //
    //     height = std::max(leftHeight, rightHeight) + 1;
    //
    //     return std::max({leftDiameter, rightDiameter, (leftHeight + rightHeight + 2)});
    // }
    //
    // void serializeUtil(Node* node, std::stringstream& ss) const {
    //     if (node == nullptr) {
    //         ss << "# ";
    //         return;
    //     }
    //     ss << node->value << " ";
    //     serializeUtil(node->left, ss);
    //     serializeUtil(node->right, ss);
    // }
    //
    // Node* deserializeUtil(std::stringstream& ss) {
    //     std::string val;
    //     ss >> val;
    //     if (val == "#") {
    //         return nullptr;
    //     }
    //     Node* root = new Node(std::stoi(val));
    //     root->left = deserializeUtil(ss);
    //     root->right = deserializeUtil(ss);
    //     return root;
    // }



public:
    Binary_Search_Tree() : root(nullptr) {}

    ~Binary_Search_Tree() {
        destroy(root);
    }

    void insert(const T &data) {
        root = insert(root, data);
    }

    // std::string serialize() const {
    //     std::stringstream ss;
    //     serializeUtil(getRoot(), ss);
    //     return ss.str();
    // }

    // void deserialize(const std::string& data) {
    //     std::stringstream ss(data);
    //     this->root = deserializeUtil(ss);
    // }

    int diameter() const {
        int height = 0;
        return diameterUtil(getRoot(), height);
    }

    void remove(const T &data) {
        root = remove(root, data);
    }

    bool search(const T &data) const {
        return search(root, data);
    }

    int countLeaves() const {
        return countLeavesUtil(getRoot());
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    bool is_BST() {
        Node* prev = nullptr;
        return is_bst_helper(root, prev);
    }

    Node* getRoot() const {
        return root;
    }

    void inorder() const {
        inorder(root);
        std::cout << "\n";
    }

    void preorder() const {
        preorder(root);
        std::cout << "\n";
    }

    void postorder() const {
        postorder(root);
        std::cout << "\n";
    }

    T findMin() const {
        if (isEmpty()) {
            throw std::out_of_range("Tree is empty.");
        }
        return findMin(root)->value;
    }

    bool isBalanced() const {
        int height = 0;
        return isBalancedUtil(getRoot(), height);
    }

    T lowestCommonAncestor(const T& val1, const T& val2) const {
        Node* current = getRoot();
        while (current != nullptr) {
            if (val1 < current->value && val2 < current->value) {
                current = current->left;
            } else if (val1 > current->value && val2 > current->value) {
                current = current->right;
            } else {
                return current->value;
            }
        }
        throw std::runtime_error("LCA not found or tree is empty.");
    }

    T findMax() const {
        if (isEmpty()) {
            throw std::out_of_range("Tree is empty.");
        }
        return findMax(root)->value;
    }

    int height() const {
        return height(root);
    }

    int depth(const T &data) const {
        return depth(root, data, 0);
    }

    T inorderSuccessor(const T &data) {
        Node *node = find(root, data);
        if (node == nullptr) {
            throw std::runtime_error("Node not found in the tree.");
        }
        if (node->right != nullptr) {
            return findMin(node->right)->value;
        }
        Node *successor = nullptr;
        Node *ancestor = root;
        while (ancestor != node) {
            if (node->value < ancestor->value) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        if (successor == nullptr) {
            throw std::runtime_error("No inorder successor found.");
        }
        return successor->value;
    }

    void levelOrder() const {
        if (root == nullptr) {
            return;
        }
        Queue_LinkedList<Node*> q;
        q.enqueue(root);
        while (!q.isEmpty()) {
            Node *current = q.peek();
            q.dequeue();
            std::cout << current->value << " ";
            if (current->left != nullptr) {
                q.enqueue(current->left);
            }
            if (current->right != nullptr) {
                q.enqueue(current->right);
            }
        }
        std::cout << "\n";
    }
};