#pragma once
#include <iostream>
#include <string>
#include "Queue_LinkedList.h"

class Tree_2_3_4 {
private:
    struct Node {
        int keys[3];
        int values[3];
        Node* children[4];
        int keyCount;
        bool isLeaf;

        Node(bool leaf) : keyCount(0), isLeaf(leaf) {
            for (int i = 0; i < 4; ++i) children[i] = nullptr;
        }

        ~Node() {
            for (int i = 0; i < keyCount + 1; ++i) {
                delete children[i];
            }
        }

        int findKey(int key) {
            int idx = 0;
            while (idx < keyCount && keys[idx] < key) {
                ++idx;
            }
            return idx;
        }
    };

    Node* root;

    Node* find(Node* node, int key, int& index) {
        if (!node) return nullptr;
        int i = node->findKey(key);
        if (i < node->keyCount && node->keys[i] == key) {
            index = i;
            return node;
        }
        if (node->isLeaf) {
            return nullptr;
        }
        return find(node->children[i], key, index);
    }

    void splitChild(Node* parent, int i, Node* child) {
        Node* newNode = new Node(child->isLeaf);
        newNode->keyCount = 1;
        newNode->keys[0] = child->keys[2];
        newNode->values[0] = child->values[2];

        if (!child->isLeaf) {
            for (int j = 0; j < 2; ++j) {
                newNode->children[j] = child->children[j + 2];
            }
        }
        child->keyCount = 1;

        for (int j = parent->keyCount; j >= i + 1; --j) {
            parent->children[j + 1] = parent->children[j];
        }
        parent->children[i + 1] = newNode;

        for (int j = parent->keyCount - 1; j >= i; --j) {
            parent->keys[j + 1] = parent->keys[j];
            parent->values[j + 1] = parent->values[j];
        }
        parent->keys[i] = child->keys[1];
        parent->values[i] = child->values[1];
        parent->keyCount++;
    }

    void insertInternal(int key, int val) {
        if (!root) {
            root = new Node(true);
            root->keys[0] = key;
            root->values[0] = val;
            root->keyCount = 1;
            return;
        }

        if (root->keyCount == 3) {
            Node* newRoot = new Node(false);
            newRoot->children[0] = root;
            splitChild(newRoot, 0, root);
            root = newRoot;
            insertNonFull(root, key, val);
        } else {
            insertNonFull(root, key, val);
        }
    }

    void insertNonFull(Node* node, int key, int val) {
        int i = node->keyCount - 1;
        if (node->isLeaf) {
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                node->values[i + 1] = node->values[i];
                i--;
            }
            node->keys[i + 1] = key;
            node->values[i + 1] = val;
            node->keyCount++;
        } else {
            while (i >= 0 && key < node->keys[i]) {
                i--;
            }
            i++;
            if (node->children[i]->keyCount == 3) {
                splitChild(node, i, node->children[i]);
                if (key > node->keys[i]) {
                    i++;
                }
            }
            insertNonFull(node->children[i], key, val);
        }
    }

    void removeFromLeaf(Node* node, int idx) {
        for (int i = idx + 1; i < node->keyCount; ++i) {
            node->keys[i - 1] = node->keys[i];
            node->values[i - 1] = node->values[i];
        }
        node->keyCount--;
    }

    int getPredecessor(Node* node, int idx, int& val) {
        Node* curr = node->children[idx];
        while (!curr->isLeaf) {
            curr = curr->children[curr->keyCount];
        }
        val = curr->values[curr->keyCount - 1];
        return curr->keys[curr->keyCount - 1];
    }

    int getSuccessor(Node* node, int idx, int& val) {
        Node* curr = node->children[idx + 1];
        while (!curr->isLeaf) {
            curr = curr->children[0];
        }
        val = curr->values[0];
        return curr->keys[0];
    }

    void removeFromNonLeaf(Node* node, int idx) {
        int key = node->keys[idx];
        if (node->children[idx]->keyCount >= 2) {
            int predVal = 0;
            int predKey = getPredecessor(node, idx, predVal);
            node->keys[idx] = predKey;
            node->values[idx] = predVal;
            deleteInternal(node->children[idx], predKey);
        } else if (node->children[idx + 1]->keyCount >= 2) {
            int succVal = 0;
            int succKey = getSuccessor(node, idx, succVal);
            node->keys[idx] = succKey;
            node->values[idx] = succVal;
            deleteInternal(node->children[idx + 1], succKey);
        } else {
            merge(node, idx);
            deleteInternal(node->children[idx], key);
        }
    }

    void borrowFromPrev(Node* node, int idx) {
        Node* child = node->children[idx];
        Node* sibling = node->children[idx - 1];
        for (int i = child->keyCount - 1; i >= 0; --i) {
            child->keys[i + 1] = child->keys[i];
            child->values[i + 1] = child->values[i];
        }
        if (!child->isLeaf) {
            for (int i = child->keyCount; i >= 0; --i) {
                child->children[i + 1] = child->children[i];
            }
            child->children[0] = sibling->children[sibling->keyCount];
        }
        child->keys[0] = node->keys[idx - 1];
        child->values[0] = node->values[idx - 1];
        node->keys[idx - 1] = sibling->keys[sibling->keyCount - 1];
        node->values[idx - 1] = sibling->values[sibling->keyCount - 1];
        child->keyCount++;
        sibling->keyCount--;
    }

    void borrowFromNext(Node* node, int idx) {
        Node* child = node->children[idx];
        Node* sibling = node->children[idx + 1];
        child->keys[child->keyCount] = node->keys[idx];
        child->values[child->keyCount] = node->values[idx];
        if (!child->isLeaf) {
            child->children[child->keyCount + 1] = sibling->children[0];
        }
        node->keys[idx] = sibling->keys[0];
        node->values[idx] = sibling->values[0];
        for (int i = 1; i < sibling->keyCount; ++i) {
            sibling->keys[i - 1] = sibling->keys[i];
            sibling->values[i - 1] = sibling->values[i];
        }
        if (!sibling->isLeaf) {
            for (int i = 1; i <= sibling->keyCount; ++i) {
                sibling->children[i - 1] = sibling->children[i];
            }
        }
        child->keyCount++;
        sibling->keyCount--;
    }

    void merge(Node* node, int idx) {
        Node* child = node->children[idx];
        Node* sibling = node->children[idx + 1];
        child->keys[1] = node->keys[idx];
        child->values[1] = node->values[idx];
        for (int i = 0; i < sibling->keyCount; ++i) {
            child->keys[i + 2] = sibling->keys[i];
            child->values[i + 2] = sibling->values[i];
        }
        if (!child->isLeaf) {
            for (int i = 0; i <= sibling->keyCount; ++i) {
                child->children[i + 2] = sibling->children[i];
            }
        }
        for (int i = idx + 1; i < node->keyCount; ++i) {
            node->keys[i - 1] = node->keys[i];
            node->values[i - 1] = node->values[i];
        }
        for (int i = idx + 2; i <= node->keyCount; ++i) {
            node->children[i - 1] = node->children[i];
        }
        child->keyCount += sibling->keyCount + 1;
        node->keyCount--;
        delete sibling;
    }

    void fill(Node* node, int idx) {
        if (idx != 0 && node->children[idx - 1]->keyCount >= 2) {
            borrowFromPrev(node, idx);
        } else if (idx != node->keyCount && node->children[idx + 1]->keyCount >= 2) {
            borrowFromNext(node, idx);
        } else {
            if (idx != node->keyCount) {
                merge(node, idx);
            } else {
                merge(node, idx - 1);
            }
        }
    }

    void deleteInternal(Node* node, int key) {
        if (!node) return;
        int idx = node->findKey(key);
        if (idx < node->keyCount && node->keys[idx] == key) {
            if (node->isLeaf) {
                removeFromLeaf(node, idx);
            } else {
                removeFromNonLeaf(node, idx);
            }
        } else {
            if (node->isLeaf) {
                return;
            }
            bool flag = (idx == node->keyCount);
            if (node->children[idx]->keyCount < 2) {
                fill(node, idx);
            }
            if (flag && idx > node->keyCount) {
                deleteInternal(node->children[idx - 1], key);
            } else {
                deleteInternal(node->children[idx], key);
            }
        }
    }

    void rangeSearch(Node* node, int L, int R, bool& found) {
        if (!node) return;
        int i;
        for (i = 0; i < node->keyCount; ++i) {
            if (!node->isLeaf) {
                rangeSearch(node->children[i], L, R, found);
            }
            if (node->keys[i] >= L && node->keys[i] <= R) {
                std::cout << node->keys[i] << ":" << node->values[i] << std::endl;
                found = true;
            }
        }
        if (!node->isLeaf) {
            rangeSearch(node->children[i], L, R, found);
        }
    }

    void printInorder(Node* node) {
        if (!node) return;
        int i;
        for (i = 0; i < node->keyCount; ++i) {
            printInorder(node->children[i]);
            std::cout << node->keys[i] << " ";
        }
        printInorder(node->children[i]);
    }

    Node* buildFromSorted(int* arr, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int n = end - start + 1;
        if (n == 0) return nullptr;

        int mid1_idx = start + (n - 1) / 3;
        int mid2_idx = start + (2 * n) / 3;

        Node* node = new Node(false);
        node->keys[0] = arr[mid1_idx];
        node->values[0] = 0;
        node->keyCount = 1;

        if (mid2_idx > mid1_idx && mid2_idx <= end) {
            node->keys[1] = arr[mid2_idx];
            node->values[1] = 0;
            node->keyCount = 2;
        }

        node->children[0] = buildFromSorted(arr, start, mid1_idx - 1);
        node->children[1] = buildFromSorted(arr, mid1_idx + 1, mid2_idx - 1);

        if (node->keyCount == 2) {
            node->children[2] = buildFromSorted(arr, mid2_idx + 1, end);
        }

        if (node->children[0] == nullptr && node->children[1] == nullptr && node->children[2] == nullptr) {
            node->isLeaf = true;
        }
        return node;
    }


public:
    Tree_2_3_4() : root(nullptr) {}

    ~Tree_2_3_4() {
        delete root;
    }

    void INSERT(int key) {
        int idx = -1;
        if (find(root, key, idx)) {
            return;
        }
        insertInternal(key, 0);
    }

    void DELETE(int key) {
        if (!root) return;
        int idx = -1;
        if (!find(root, key, idx)) return;

        deleteInternal(root, key);
        if (root->keyCount == 0 && !root->isLeaf && root->children[0]) {
            Node* oldRoot = root;
            root = root->children[0];
            oldRoot->children[0] = nullptr;
            delete oldRoot;
        }
    }

    void FIND(int key) {
        int idx = -1;
        if (find(root, key, idx)) {
            std::cout << "FOUND" << std::endl;
        } else {
            std::cout << "NOTFOUND" << std::endl;
        }
    }

    void PRINT(std::string type) {
        if (!root) {
            std::cout << "EMPTY" << std::endl;
            return;
        }
        if (type == "IN") {
            printInorder(root);
            std::cout << std::endl;
        } else if (type == "LEVEL") {
            Queue_LinkedList<Node*> q;
            q.enqueue(root);
            while (!q.isEmpty()) {
                int levelSize = q.getSize();
                for (int i = 0; i < levelSize; ++i) {
                    Node* curr = q.peek();
                    q.dequeue();

                    std::cout << "[";
                    for(int k=0; k < curr->keyCount; ++k) {
                        std::cout << curr->keys[k];
                        if (k < curr->keyCount - 1) std::cout << " ";
                    }
                    std::cout << "] ";

                    if (!curr->isLeaf) {
                        for (int j = 0; j <= curr->keyCount; ++j) {
                            if (curr->children[j]) {
                                q.enqueue(curr->children[j]);
                            }
                        }
                    }
                }
            }
            std::cout << std::endl;
        }
    }

    void BULK(int* arr, int n) {
        if (n <= 0) {
            delete root;
            root = nullptr;
            return;
        }
        delete root;
        root = buildFromSorted(arr, 0, n - 1);
    }

    void PUT(int key, int val) {
        int idx = -1;
        Node* n = find(root, key, idx);
        if (n) {
            n->values[idx] = val;
            return;
        }
        insertInternal(key, val);
    }

    void GET(int key) {
        int idx = -1;
        Node* n = find(root, key, idx);
        if (n) {
            std::cout << n->values[idx] << std::endl;
        } else {
            std::cout << "NOTFOUND" << std::endl;
        }
    }

    void RANGE(int L, int R) {
        bool found = false;
        rangeSearch(root, L, R, found);
        if (!found) {
            std::cout << "EMPTY" << std::endl;
        }
    }

    void BATCH_DELETE(int m, int* keys) {
        for (int i = 0; i < m; ++i) {
            DELETE(keys[i]);
        }
    }
};