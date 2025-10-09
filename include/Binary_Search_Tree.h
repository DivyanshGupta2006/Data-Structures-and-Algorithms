#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <queue>

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

public:
    Binary_Search_Tree() : root(nullptr) {}

    ~Binary_Search_Tree() {
        destroy(root);
    }

    void insert(const T &data) {
        root = insert(root, data);
    }

    void remove(const T &data) {
        root = remove(root, data);
    }

    bool search(const T &data) const {
        return search(root, data);
    }

    bool isEmpty() const {
        return root == nullptr;
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
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node *current = q.front();
            q.pop();
            std::cout << current->value << " ";
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        std::cout << "\n";
    }
};