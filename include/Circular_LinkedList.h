// Header file containing declarations and definitions of Circular_LinkedList class and all the associated functions and variables

// "include guard" to prevent multiple inclusions in different files that are also included in each other
#pragma once
#include <iostream>

// template class declaration - so the class will be generic with respect to datatypes
template<typename T>
class Circular_LinkedList {
private:
    struct Node {
        T value;
        Node *next;

        Node(const T &data) : value(data), next(nullptr) {
        }
    };

    size_t size;

    Node *findMiddle(Node *h);

    Node *merge_sort(Node *h);

    Node *merge_sorted(Node *a, Node *b);

public:
    Node *head;

    Circular_LinkedList() : head(nullptr), size(0) {
    }

    ~Circular_LinkedList();

    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void display() const;

    Node *findMin() const;

    Node *findMax() const;

    bool isCircular() const;

    void insert_begin(const T &data);

    void insert_end(const T &data);

    void insert_at(const T &data, const size_t index);

    void delete_begin();

    void delete_end();

    void delete_at(const size_t index);

    void delete_element(const T &data);

    Node *find(const T &data) const;

    int search(const T &data) const;

    void sort();

    void merge(const Circular_LinkedList<T> &list);

    void reverse();
};

template<typename T>
Circular_LinkedList<T>::~Circular_LinkedList() {
    if (head == nullptr) {
        return;
    }
    Node *current = head->next;
    while (current != head) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
    head = nullptr;
    size = 0;
}

template<typename T>
void Circular_LinkedList<T>::display() const {
    if (isEmpty()) {
        std::cout << "\n";
        return;
    }
    Node *current = head;
    do {
        std::cout << current->value << " ";
        current = current->next;
    } while (current != head);
    std::cout << "\n";
}

template<typename T>
typename Circular_LinkedList<T>::Node *Circular_LinkedList<T>::findMin() const {
    if (isEmpty()) {
        throw std::out_of_range("Circular_LinkedList is empty.");
    }
    Node *current = head->next;
    Node *minn = head;
    do {
        if (current->value < minn->value) {
            minn = current;
        }
        current = current->next;
    } while (current != head);
    return minn;
}

template<typename T>
typename Circular_LinkedList<T>::Node *Circular_LinkedList<T>::findMax() const {
    if (isEmpty()) {
        throw std::out_of_range("Circular_LinkedList is empty.");
    }
    Node *current = head->next;
    Node *maxx = head;
    do {
        if (current->value > maxx->value) {
            maxx = current;
        }
        current = current->next;
    } while (current != head);
    return maxx;
}

template <typename T>
bool Circular_LinkedList<T>::isCircular() const {
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


template<typename T>
void Circular_LinkedList<T>::insert_begin(const T &data) {
    Node *newNode = new Node(data);
    if (isEmpty()) {
        head = newNode;
        newNode->next = head;
    } else {
        Node *tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    size++;
}

template<typename T>
void Circular_LinkedList<T>::insert_end(const T &data) {
    Node *newNode = new Node(data);
    if (isEmpty()) {
        head = newNode;
        newNode->next = head;
    } else {
        Node *tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = head;
    }
    size++;
}

template<typename T>
void Circular_LinkedList<T>::insert_at(const T &data, const size_t index) {
    if (index == 0) {
        insert_begin(data);
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

template<typename T>
void Circular_LinkedList<T>::delete_begin() {
    if (isEmpty()) {
        throw std::out_of_range("Circular_LinkedList is empty.");
    }
    if (size == 1) {
        delete head;
        head = nullptr;
    } else {
        Node *tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        Node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }
    size--;
}

template<typename T>
void Circular_LinkedList<T>::delete_end() {
    if (isEmpty()) {
        throw std::out_of_range("Circular_LinkedList is empty.");
    }
    if (size == 1) {
        delete head;
        head = nullptr;
    } else {
        Node *current = head;
        while (current->next->next != head) {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = head;
        delete temp;
    }
    size--;
}

template<typename T>
void Circular_LinkedList<T>::delete_at(const size_t index) {
    if (isEmpty()) {
        throw std::out_of_range("Circular_LinkedList is empty.");
    }
    if (index == 0) {
        delete_begin();
        return;
    }
    if (index >= size) {
        throw std::out_of_range("Invalid index: Deletion out of bounds.");
    }
    Node *current = head;
    for (size_t i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    size--;
}

template<typename T>
void Circular_LinkedList<T>::delete_element(const T &data) {
    if (isEmpty()) {
        return;
    }
    if (head->value == data) {
        delete_begin();
        return;
    }
    Node *current = head;
    while (current->next != head) {
        if (current->next->value == data) {
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
            return;
        }
        current = current->next;
    }
}

template<typename T>
typename Circular_LinkedList<T>::Node *Circular_LinkedList<T>::find(const T &data) const {
    if (isEmpty()) {
        return nullptr;
    }
    Node *current = head;
    do {
        if (current->value == data) {
            return current;
        }
        current = current->next;
    } while (current != head);
    return nullptr;
}

template<typename T>
int Circular_LinkedList<T>::search(const T &data) const {
    if (isEmpty()) {
        return -1;
    }
    int index = 0;
    if (head->value == data) {
        return index;
    }
    Node *current = head->next;
    index = 1;
    while (current != head) {
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
typename Circular_LinkedList<T>::Node *Circular_LinkedList<T>::findMiddle(Node *h) {
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
typename Circular_LinkedList<T>::Node *Circular_LinkedList<T>::merge_sort(Node *h) {
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
typename Circular_LinkedList<T>::Node *Circular_LinkedList<T>::merge_sorted(Node *a, Node *b) {
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
void Circular_LinkedList<T>::sort() {
    if (head == nullptr || head->next == head) {
        return;
    }

    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    last->next = nullptr;

    head = merge_sort(head);

    Node* new_tail = head;
    while (new_tail->next != nullptr) {
        new_tail = new_tail->next;
    }
    new_tail->next = head;
}

template<typename T>
void Circular_LinkedList<T>::merge(const Circular_LinkedList<T> &list) {
    if (list.isEmpty()) {
        return;
    }
    Node *list_head = list.head;
    Node *list_tail = list_head;
    while (list_tail->next != list_head) {
        list_tail = list_tail->next;
    }
    if (isEmpty()) {
        head = list_head;
    } else {
        Node *tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = list_head;
        list_tail->next = head;
    }
    size += list.size;
}

template<typename T>
void Circular_LinkedList<T>::reverse() {
    if (isEmpty()) {
        return;
    }
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;
    Node *tail = nullptr;
    if (head->next != head) {
        tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
    }
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);
    head->next = tail;
    head = prev;
}
