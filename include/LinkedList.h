// Header file containing declarations and definitions of LinkedList class and all the associated functions and variables

// "include guard" to prevent multiple inclusions in different files that are also included in each other
#pragma once
#include <iostream>

// template class declaration - so the class will be generic with respect to datatypes
template<typename T>
class LinkedList {
private:
    struct Node {
        // declaration of node variables
        T value;
        Node *next;

        // constructor of struct - takes reference to a data of type T and give that to value and nullptr to next
        Node(const T &data) : value(data), next(nullptr) {
        }
    };

    size_t size;

    // private functions used for merge sort
    Node *findMiddle(Node *h);

    Node *merge_sort(Node *h);

    Node *merge_sorted(Node *a, Node *b);

public:
    Node *head;

    // constructor
    LinkedList() : head(nullptr), size(0) {
    }

    // destructor
    ~LinkedList();

    // basic functions
    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    // utility functions
    void display() const;

    Node *findMin() const;

    Node *findMax() const;

    bool isCircular() const;

    // insertion functions
    void insert_begin(const T &data);

    void insert_end(const T &data);

    void insert_at(const T &data, const size_t index);

    // deletion functions
    void delete_begin();

    void delete_end();

    void delete_at(const size_t index);

    void delete_element(const T &data);

    // other functions
    Node *find(const T &data) const;

    int search(const T &data) const;

    void sort();

    void merge(const LinkedList<T> &list);

    void reverse();

    T getValue(int i) const;
};

// defining the destructor
template<typename T>
LinkedList<T>::~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    size = 0;
}

// defining utility functions
template<typename T>
void LinkedList<T>::display() const {
    Node *current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << "\n";
}

template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::findMin() const {
    if (isEmpty()) {
        throw std::out_of_range("LinkedList is empty.");
    }
    Node *current = head;
    Node *minn = head;
    while (current != nullptr) {
        if (current->value < minn->value) {
            minn = current;
        }
        current = current->next;
    }

    return minn;
}

template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::findMax() const {
    if (isEmpty()) {
        throw std::out_of_range("LinkedList is empty.");
    }
    Node *current = head;
    Node *maxx = head;
    while (current != nullptr) {
        if (current->value > maxx->value) {
            maxx = current;
        }
        current = current->next;
    }

    return maxx;
}

template <typename T>
bool LinkedList<T>::isCircular() const {
    if (head == nullptr) {
        return false;
    }

    Node* slow_ptr = head;
    Node* fast_ptr = head;

    while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr) {
            return true;
        }
    }

    return false;
}

// defining insertion functions
template<typename T>
void LinkedList<T>::insert_begin(const T &data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    size++;
}

template<typename T>
void LinkedList<T>::insert_end(const T &data) {
    Node *newNode = new Node(data);
    if (isEmpty()) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

template<typename T>
void LinkedList<T>::insert_at(const T &data, const size_t index) {
    if (index == 0) {
        insert_begin(data);
        return;
    } else if (index > size) {
        throw std::out_of_range("Invalid index: Insertion out of bounds.");
    } else {
        Node *newNode = new Node(data);
        Node *current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
}

// defining deletion functions
template<typename T>
void LinkedList<T>::delete_begin() {
    if (isEmpty()) {
        throw std::out_of_range("LinkedList is empty.");
    } else {
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

template<typename T>
void LinkedList<T>::delete_end() {
    if (isEmpty()) {
        throw std::out_of_range("LinkedList is empty.");
    } else {
        Node *current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
        size--;
    }
}

template<typename T>
void LinkedList<T>::delete_at(const size_t index) {
    if (isEmpty()) {
        throw std::out_of_range("LinkedList is empty.");
    } else {
        Node *current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
    }
}

template<typename T>
void LinkedList<T>::delete_element(const T &data) {
    Node *current = head;
    if (current->value == data) {
        head = head->next;
        delete current;
        size--;
        return;
    }
    while (current->next != nullptr) {
        if (current->next->value == data) {
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
            break;
        }
        current = current->next;
    }
}

// defining other functions
template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::find(const T &data) const {
    Node *current = head;
    while (current != nullptr) {
        if (current->value == data) {
            return current;
        }
        current = current->next;
    }

    return nullptr;
}

template<typename T>
int LinkedList<T>::search(const T &data) const {
    if (isEmpty()) {
        return -1;
    }
    int index = 0;
    Node *current = head;
    while (current != nullptr) {
        if (current->value == data) {
            return index;
        }
        index++;
        current = current->next;
    }
    if (index == size) {
        return -1;
    }
    return index;
}

template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::findMiddle(Node *h) {
    if (h == nullptr || h->next == nullptr) {
        return h;
    }

    // create two pointers to find mid of the list
    Node *slow_ptr = h;
    Node *fast_ptr = h->next;

    while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    return slow_ptr;
}

template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::merge_sort(Node *h) {
    if (h == nullptr || h->next == nullptr) {
        return h;
    }

    // find middle
    Node *middle = findMiddle(h);
    Node *mid_next = middle->next;

    // break the list
    middle->next = nullptr;

    Node *left = merge_sort(h);
    Node *right = merge_sort(mid_next);

    Node *sorted = merge_sorted(left, right);
    return sorted;
}

template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::merge_sorted(Node *a, Node *b) {
    Node *result = nullptr;
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }
    if (a->value <= b->value) {
        result = a;
        result->next = merge_sorted(a->next, b);
    } else {
        result = b;
        result->next = merge_sorted(a, b->next);
    }
    return result;
}

template<typename T>
T LinkedList<T>::getValue(int i) const {
    int index = 0;
    Node *current = head;
    while (current->next != nullptr && index < i) {
        current = current->next;
        index++;
    }
    return current->value;
}

template<typename T>
void LinkedList<T>::sort() {
    head = merge_sort(head);
}

template<typename T>
void LinkedList<T>::merge(const LinkedList<T> &list) {
    if (list.isEmpty()) {
        return;
    } else if (isEmpty()) {
        head = list.head;
    } else {
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = list.head;
        size += list.size;
    }
}

template<typename T>
void LinkedList<T>::reverse() {
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
