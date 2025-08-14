// Header file containing declarations and definitions of Circular_Doubly_LinkedList class and all the associated functions and variables

// "include guard" to prevent multiple inclusions in different files that are also included in each other
#pragma once
#include <iostream>

// template class declaration - so the class will be generic with respect to datatypes
template<typename T>
class Circular_Doubly_LinkedList {
private:
    struct Node {
        T value;
        Node *prev;
        Node *next;

        Node(const T &data) : value(data), prev(nullptr), next(nullptr) {
        }
    };

    size_t size;

    Node *findMiddle(Node *h);

    Node *merge_sort(Node *h);

    Node *merge_sorted(Node *a, Node *b);

public:
    Node *head;

    Circular_Doubly_LinkedList() : head(nullptr), size(0) {
    }

    ~Circular_Doubly_LinkedList();

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

    void merge(const Circular_Doubly_LinkedList<T> &list);

    void reverse();
};

template<typename T>
Circular_Doubly_LinkedList<T>::~Circular_Doubly_LinkedList() {
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
void Circular_Doubly_LinkedList<T>::display() const {
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
typename Circular_Doubly_LinkedList<T>::Node *Circular_Doubly_LinkedList<T>::findMin() const {
    if (isEmpty()) {
        throw std::out_of_range("Circular_Doubly_LinkedList is empty.");
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
typename Circular_Doubly_LinkedList<T>::Node *Circular_Doubly_LinkedList<T>::findMax() const {
    if (isEmpty()) {
        throw std::out_of_range("Circular_Doubly_LinkedList is empty.");
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
bool Circular_Doubly_LinkedList<T>::isCircular() const {
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
void Circular_Doubly_LinkedList<T>::insert_begin(const T &data) {
    Node *newNode = new Node(data);
    if (isEmpty()) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node *tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
    size++;
}

template<typename T>
void Circular_Doubly_LinkedList<T>::insert_end(const T &data) {
    Node *newNode = new Node(data);
    if (isEmpty()) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node *tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
    size++;
}

template<typename T>
void Circular_Doubly_LinkedList<T>::insert_at(const T &data, const size_t index) {
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
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        size++;
    }
}

template<typename T>
void Circular_Doubly_LinkedList<T>::delete_begin() {
    if (isEmpty()) {
        throw std::out_of_range("Circular_Doubly_LinkedList is empty.");
    }
    if (size == 1) {
        delete head;
        head = nullptr;
    } else {
        Node *tail = head->prev;
        Node *temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }
    size--;
}

template<typename T>
void Circular_Doubly_LinkedList<T>::delete_end() {
    if (isEmpty()) {
        throw std::out_of_range("Circular_Doubly_LinkedList is empty.");
    }
    if (size == 1) {
        delete head;
        head = nullptr;
    } else {
        Node *tail = head->prev;
        Node *new_tail = tail->prev;
        new_tail->next = head;
        head->prev = new_tail;
        delete tail;
    }
    size--;
}

template<typename T>
void Circular_Doubly_LinkedList<T>::delete_at(const size_t index) {
    if (isEmpty()) {
        throw std::out_of_range("Circular_Doubly_LinkedList is empty.");
    }
    if (index == 0) {
        delete_begin();
        return;
    }
    if (index >= size) {
        throw std::out_of_range("Invalid index: Deletion out of bounds.");
    }
    Node *current = head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    size--;
}

template<typename T>
void Circular_Doubly_LinkedList<T>::delete_element(const T &data) {
    if (isEmpty()) {
        return;
    }
    Node *current = head;
    do {
        if (current->value == data) {
            if (size == 1) {
                delete head;
                head = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (current == head) {
                    head = current->next;
                }
                delete current;
            }
            size--;
            return;
        }
        current = current->next;
    } while (current != head);
}

template<typename T>
typename Circular_Doubly_LinkedList<T>::Node *Circular_Doubly_LinkedList<T>::find(const T &data) const {
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
int Circular_Doubly_LinkedList<T>::search(const T &data) const {
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
typename Circular_Doubly_LinkedList<T>::Node *Circular_Doubly_LinkedList<T>::findMiddle(Node *h) {
    if (h == nullptr || h->next == nullptr) {
        return h;
    }
    Node *slow_ptr = h;
    Node *fast_ptr = h;
    while (fast_ptr->next != nullptr && fast_ptr->next->next != nullptr) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    return slow_ptr;
}

template<typename T>
typename Circular_Doubly_LinkedList<T>::Node *Circular_Doubly_LinkedList<T>::merge_sort(Node *h) {
    if (h == nullptr || h->next == nullptr) {
        return h;
    }
    Node *middle = findMiddle(h);
    Node *mid_next = middle->next;
    middle->next = nullptr;
    mid_next->prev = nullptr;
    Node *left = merge_sort(h);
    Node *right = merge_sort(mid_next);
    return merge_sorted(left, right);
}

template<typename T>
typename Circular_Doubly_LinkedList<T>::Node *Circular_Doubly_LinkedList<T>::merge_sorted(Node *a, Node *b) {
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }
    Node *result = nullptr;
    if (a->value <= b->value) {
        result = a;
        result->next = merge_sorted(a->next, b);
        if (result->next != nullptr) {
            result->next->prev = result;
        }
    } else {
        result = b;
        result->next = merge_sorted(a, b->next);
        if (result->next != nullptr) {
            result->next->prev = result;
        }
    }
    return result;
}

template<typename T>
void Circular_Doubly_LinkedList<T>::sort() {
    if (head == nullptr || head->next == head) {
        return;
    }
    Node* last = head->prev;
    last->next = nullptr;
    head->prev = nullptr;
    head = merge_sort(head);
    Node* new_tail = head;
    while (new_tail->next != nullptr) {
        new_tail = new_tail->next;
    }
    new_tail->next = head;
    head->prev = new_tail;
}

template<typename T>
void Circular_Doubly_LinkedList<T>::merge(const Circular_Doubly_LinkedList<T> &list) {
    if (list.isEmpty()) {
        return;
    }
    Node *list_head = list.head;
    Node *list_tail = list_head->prev;
    if (isEmpty()) {
        head = list_head;
    } else {
        Node *tail = head->prev;
        tail->next = list_head;
        list_head->prev = tail;
        list_tail->next = head;
        head->prev = list_tail;
    }
    size += list.size;
}

template<typename T>
void Circular_Doubly_LinkedList<T>::reverse() {
    if (isEmpty() || size == 1) {
        return;
    }
    Node* current = head;
    Node* temp = nullptr;
    Node* new_head = head->prev;
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != head);
    head = new_head;
}