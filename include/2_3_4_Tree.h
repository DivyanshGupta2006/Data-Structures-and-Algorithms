#pragma once
#include <iostream>
#include "Queue_LinkedList.h"

class Tree_2_3_4 {
private:
    struct Node {
        int keys[3];
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
    };

    Node* root;

    void printInorder(Node* node) {
        if (!node) return;
        int i;
        for (i = 0; i < node->keyCount; ++i) {
            printInorder(node->children[i]);
            std::cout << node->keys[i] << " ";
        }
        printInorder(node->children[i]);
    }

    Node* find(Node* node, int key) {
        if (!node) return nullptr;
        int i = 0;
        while (i < node->keyCount && key > node->keys[i]) {
            i++;
        }
        if (i < node->keyCount && key == node->keys[i]) {
            return node;
        }
        if (node->isLeaf) {
            return nullptr;
        }
        return find(node->children[i], key);
    }

    void splitChild(Node* parent, int i, Node* child) {
        Node* newNode = new Node(child->isLeaf);
        newNode->keyCount = 1;
        newNode->keys[0] = child->keys[2];

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
        }
        parent->keys[i] = child->keys[1];
        parent->keyCount++;
    }

    void insertNonFull(Node* node, int key) {
        int i = node->keyCount - 1;

        if (node->isLeaf) {
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
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
            insertNonFull(node->children[i], key);
        }
    }

    int findKey(Node* node, int key) {
        int idx = 0;
        while (idx < node->keyCount && node->keys[idx] < key) {
            ++idx;
        }
        return idx;
    }

    void removeFromLeaf(Node* node, int idx) {
        for (int i = idx + 1; i < node->keyCount; ++i) {
            node->keys[i - 1] = node->keys[i];
        }
        node->keyCount--;
    }

    void removeFromNonLeaf(Node* node, int idx) {
        int key = node->keys[idx];
        if (node->children[idx]->keyCount >= 2) {
            int pred = getPredecessor(node, idx);
            node->keys[idx] = pred;
            deleteInternal(node->children[idx], pred);
        } else if (node->children[idx + 1]->keyCount >= 2) {
            int succ = getSuccessor(node, idx);
            node->keys[idx] = succ;
            deleteInternal(node->children[idx + 1], succ);
        } else {
            merge(node, idx);
            deleteInternal(node->children[idx], key);
        }
    }

    int getPredecessor(Node* node, int idx) {
        Node* curr = node->children[idx];
        while (!curr->isLeaf) {
            curr = curr->children[curr->keyCount];
        }
        return curr->keys[curr->keyCount - 1];
    }

    int getSuccessor(Node* node, int idx) {
        Node* curr = node->children[idx + 1];
        while (!curr->isLeaf) {
            curr = curr->children[0];
        }
        return curr->keys[0];
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

    void borrowFromPrev(Node* node, int idx) {
        Node* child = node->children[idx];
        Node* sibling = node->children[idx - 1];

        for (int i = child->keyCount - 1; i >= 0; --i) {
            child->keys[i + 1] = child->keys[i];
        }
        child->keys[0] = node->keys[idx - 1];

        if (!child->isLeaf) {
            for (int i = child->keyCount; i >= 0; --i) {
                child->children[i + 1] = child->children[i];
            }
            child->children[0] = sibling->children[sibling->keyCount];
        }

        node->keys[idx - 1] = sibling->keys[sibling->keyCount - 1];
        child->keyCount++;
        sibling->keyCount--;
    }

    void borrowFromNext(Node* node, int idx) {
        Node* child = node->children[idx];
        Node* sibling = node->children[idx + 1];

        child->keys[child->keyCount] = node->keys[idx];

        if (!child->isLeaf) {
            child->children[child->keyCount + 1] = sibling->children[0];
        }

        node->keys[idx] = sibling->keys[0];

        for (int i = 1; i < sibling->keyCount; ++i) {
            sibling->keys[i - 1] = sibling->keys[i];
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

        for (int i = 0; i < sibling->keyCount; ++i) {
            child->keys[i + 2] = sibling->keys[i];
        }

        if (!child->isLeaf) {
            for (int i = 0; i <= sibling->keyCount; ++i) {
                child->children[i + 2] = sibling->children[i];
            }
        }

        for (int i = idx + 1; i < node->keyCount; ++i) {
            node->keys[i - 1] = node->keys[i];
        }
        for (int i = idx + 2; i <= node->keyCount; ++i) {
            node->children[i - 1] = node->children[i];
        }

        child->keyCount += sibling->keyCount + 1;
        node->keyCount--;
        delete sibling;
    }

    void deleteInternal(Node* node, int key) {
        int idx = findKey(node, key);

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

    Node* buildFromSorted(int* arr, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid1 = start + (end - start) / 3;
        int mid2 = start + 2 * (end - start) / 3 + 1;
        
        Node* node = new Node(false);
        
        if (mid1 <= end) {
            node->keys[0] = arr[mid1];
            node->keyCount = 1;
        }
        if (mid2 <= end) {
            node->keys[1] = arr[mid2];
            node->keyCount = 2;
        }
        
        if (start <= end) {
             node->children[0] = buildFromSorted(arr, start, mid1 - 1);
        }
        if (mid1 + 1 <= end) {
             node->children[1] = buildFromSorted(arr, mid1 + 1, mid2 - 1);
        }
        if (mid2 + 1 <= end) {
             node->children[2] = buildFromSorted(arr, mid2 + 1, end);
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
        if (find(root, key)) return;

        if (!root) {
            root = new Node(true);
            root->keys[0] = key;
            root->keyCount = 1;
        } else {
            if (root->keyCount == 3) {
                Node* newRoot = new Node(false);
                newRoot->children[0] = root;
                splitChild(newRoot, 0, root);
                root = newRoot;
            }
            insertNonFull(root, key);
        }
    }

    void DELETE(int key) {
        if (!root || !find(root, key)) {
            return;
        }
        deleteInternal(root, key);
        if (root->keyCount == 0 && !root->isLeaf) {
            Node* oldRoot = root;
            root = root->children[0];
            oldRoot->children[0] = nullptr;
            delete oldRoot;
        }
    }

    void FIND(int key) {
        if (find(root, key)) {
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
        if (n <= 0) return;
        delete root;
        root = buildFromSorted(arr, 0, n - 1);
    }
};