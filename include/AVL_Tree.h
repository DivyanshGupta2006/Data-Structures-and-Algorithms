#pragma once

#include <iostream>
#include <string>
#include "Queue_LinkedList.h"

class AVL_Tree {
private:
    struct Node {
        int key;
        long long sum;
        int height;
        int size;
        Node *left;
        Node *right;
        Node(int k) : key(k), sum(k), height(0), size(1), left(nullptr), right(nullptr) {}
    };

    Node *root;

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int getHeight(Node* n) {
        return n ? n->height : -1;
    }

    int getSize(Node* n) {
        return n ? n->size : 0;
    }

    long long getSum(Node* n) {
        return n ? n->sum : 0;
    }

    void updateNode(Node* n) {
        if (n) {
            n->height = 1 + max(getHeight(n->left), getHeight(n->right));
            n->size = 1 + getSize(n->left) + getSize(n->right);
            n->sum = n->key + getSum(n->left) + getSum(n->right);
        }
    }

    int getBalanceFactor(Node* n) {
        return n ? getHeight(n->left) - getHeight(n->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateNode(y);
        updateNode(x);
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateNode(x);
        updateNode(y);
        return y;
    }

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        updateNode(node);

        int balance = getBalanceFactor(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }
                delete temp;
            } else {
                Node* temp = findMin(root->right);
                root->key = temp->key;
                root->sum = temp->sum;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (!root) return root;

        updateNode(root);

        int balance = getBalanceFactor(root);

        if (balance > 1 && getBalanceFactor(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalanceFactor(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    Node* find(Node* node, int key) {
        if (!node || node->key == key)
            return node;
        if (key < node->key)
            return find(node->left, key);
        else
            return find(node->right, key);
    }

    Node* prev(Node* node, int key, Node* p) {
        if (!node) return p;
        if (node->key < key) {
            p = node;
            return prev(node->right, key, p);
        } else {
            return prev(node->left, key, p);
        }
    }

    Node* next(Node* node, int key, Node* s) {
        if (!node) return s;
        if (node->key > key) {
            s = node;
            return next(node->left, key, s);
        } else {
            return next(node->right, key, s);
        }
    }

    void inorder(Node* n, std::string& s) {
        if (n) {
            inorder(n->left, s);
            s += std::to_string(n->key) + " ";
            inorder(n->right, s);
        }
    }

    void preorder(Node* n, std::string& s) {
        if (n) {
            s += std::to_string(n->key) + " ";
            preorder(n->left, s);
            preorder(n->right, s);
        }
    }

    void postorder(Node* n, std::string& s) {
        if (n) {
            postorder(n->left, s);
            postorder(n->right, s);
            s += std::to_string(n->key) + " ";
        }
    }

    void levelorder(Node* root, std::string& s) {
        if (!root) return;
        Queue_LinkedList<Node*> q;
        q.enqueue(root);
        while (!q.isEmpty()) {
            Node* curr = q.peek();
            q.dequeue();
            s += std::to_string(curr->key) + " ";
            if (curr->left) q.enqueue(curr->left);
            if (curr->right) q.enqueue(curr->right);
        }
    }

    int rank(Node* node, int key) {
        if (!node) return 0;
        if (key <= node->key)
            return rank(node->left, key);
        else
            return 1 + getSize(node->left) + rank(node->right, key);
    }

    Node* select(Node* node, int k) {
        if (!node) return nullptr;
        int leftSize = getSize(node->left);
        if (k == leftSize + 1)
            return node;
        if (k <= leftSize)
            return select(node->left, k);
        else
            return select(node->right, k - leftSize - 1);
    }

    int countLessThanOrEqual(Node* node, int key) {
        if (!node) return 0;
        if (key < node->key)
            return countLessThanOrEqual(node->left, key);
        else
            return 1 + getSize(node->left) + countLessThanOrEqual(node->right, key);
    }

    long long sumLessThan(Node* node, int key) {
        if (!node) return 0;
        if (key <= node->key)
            return sumLessThan(node->left, key);
        else
            return node->key + getSum(node->left) + sumLessThan(node->right, key);
    }

    long long sumLessThanOrEqual(Node* node, int key) {
        if (!node) return 0;
        if (key < node->key)
            return sumLessThanOrEqual(node->left, key);
        else
            return node->key + getSum(node->left) + sumLessThanOrEqual(node->right, key);
    }

    void destroyTree(Node* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    AVL_Tree() : root(nullptr) {}

    ~AVL_Tree() {
        destroyTree(root);
    }

    bool isEmpty() {
        return root == nullptr;
    }

    void INSERT(int key) {
        root = insert(root, key);
    }

    void DELETE(int key) {
        root = deleteNode(root, key);
    }

    void FIND(int key) {
        if (find(root, key))
            std::cout << "FOUND" << std::endl;
        else
            std::cout << "NOTFOUND" << std::endl;
    }

    void PREV(int key) {
        Node* p = prev(root, key, nullptr);
        if (p)
            std::cout << p->key << std::endl;
        else
            std::cout << "NONE" << std::endl;
    }

    void NEXT(int key) {
        Node* s = next(root, key, nullptr);
        if (s)
            std::cout << s->key << std::endl;
        else
            std::cout << "NONE" << std::endl;
    }

    void PRINT(const std::string& type) {
        if (isEmpty()) {
            std::cout << "EMPTY" << std::endl;
            return;
        }
        std::string s = "";
        if (type == "IN") inorder(root, s);
        else if (type == "PRE") preorder(root, s);
        else if (type == "POST") postorder(root, s);
        else if (type == "LEVEL") levelorder(root, s);

        s.pop_back();
        std::cout << s << std::endl;
    }

    void RANK(int key) {
        std::cout << rank(root, key) << std::endl;
    }

    void SELECT(int k) {
        if (k <= 0 || k > getSize(root)) {
            std::cout << "INVALID" << std::endl;
            return;
        }
        Node* n = select(root, k);
        if (n)
            std::cout << n->key << std::endl;
        else
            std::cout << "INVALID" << std::endl;
    }

    void RANGE_COUNT(int L, int R) {
        int count = countLessThanOrEqual(root, R) - rank(root, L);
        std::cout << count << std::endl;
    }

    void RANGE_SUM(int L, int R) {
        long long sum = sumLessThanOrEqual(root, R) - sumLessThan(root, L);
        std::cout << sum << std::endl;
    }
};