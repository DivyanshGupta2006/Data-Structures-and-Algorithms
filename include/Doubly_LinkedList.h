// Header file containing declarations and definitions of Doubly_LinkedList class and all the associated functions and variables

// "include guard" to prevent multiple inclusions in different files that are also included in each other
#pragma once
#include <iostream>

// template class declaration - so the class will be generic with respect to datatypes
template<typename T>
class Doubly_LinkedList {
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

    Doubly_LinkedList() : head(nullptr), size(0) {
    }

    ~Doubly_LinkedList();

    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void display() const;

    Node *findMin() const;

    Node *findMax() const;

    void insert_begin(const T &data);

    void insert_end(const T &data);

    void insert_at(const T &data, const size_t index);

    void delete_begin();

    void delete_end();

    void delete_at(const size_t index);

    void delete_element(const T &data);

    Node *find(const T &data) const;

    void sort();

    void merge(const Doubly_LinkedList<T> &list);

    void reverse();
};

template<typename T>
Doubly_LinkedList<T>::~Doubly_LinkedList() {
    Node *current = head;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    size = 0;
}

template<typename T>
void Doubly_LinkedList<T>::display() const {
    Node *current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << "\n";
}

template<typename T>
typename Doubly_LinkedList<T>::Node *Doubly_LinkedList<T>::findMin() const {
    if (isEmpty()) {
        throw std::out_of_range("Doubly_LinkedList is empty.");
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
typename Doubly_LinkedList<T>::Node *Doubly_LinkedList<T>::findMax() const {
    if (isEmpty()) {
        throw std::out_of_range("Doubly_LinkedList is empty.");
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

template<typename T>
void Doubly_LinkedList<T>::insert_begin(const T &data) {
    Node *newNode = new Node(data);
    if (isEmpty()) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template<typename T>
void Doubly_LinkedList<T>::insert_end(const T &data) {
    Node *newNode = new Node(data);
    if (isEmpty()) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    size++;
}

template<typename T>
void Doubly_LinkedList<T>::insert_at(const T &data, const size_t index) {
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
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        size++;
    }
}

template<typename T>
void Doubly_LinkedList<T>::delete_begin() {
    if (isEmpty()) {
        throw std::out_of_range("Doubly_LinkedList is empty.");
    } else {
        Node *temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }
}

template<typename T>
void Doubly_LinkedList<T>::delete_end() {
    if (isEmpty()) {
        throw std::out_of_range("Doubly_LinkedList is empty.");
    } else {
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        if (current->prev != nullptr) {
            current->prev->next = nullptr;
        } else {
            head = nullptr;
        }
        delete current;
        size--;
    }
}

template<typename T>
void Doubly_LinkedList<T>::delete_at(const size_t index) {
    if (isEmpty()) {
        throw std::out_of_range("Doubly_LinkedList is empty.");
    }
    if (index == 0) {
        delete_begin();
        return;
    } else if (index >= size) {
        throw std::out_of_range("Invalid index: Deletion out of bounds.");
    } else {
        Node *current = head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        delete current;
        size--;
    }
}

template<typename T>
void Doubly_LinkedList<T>::delete_element(const T &data) {
    Node *current = head;
    while (current != nullptr) {
        if (current->value == data) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            delete current;
            size--;
            return;
        }
        current = current->next;
    }
}

template<typename T>
typename Doubly_LinkedList<T>::Node *Doubly_LinkedList<T>::find(const T &data) const {
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
typename Doubly_LinkedList<T>::Node *Doubly_LinkedList<T>::findMiddle(Node *h) {
    if (h == nullptr) {
        return nullptr;
    }
    Node *slow_ptr = h;
    Node *fast_ptr = h;
    while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    return slow_ptr;
}

template<typename T>
typename Doubly_LinkedList<T>::Node *Doubly_LinkedList<T>::merge_sort(Node *h) {
    if (h == nullptr || h->next == nullptr) {
        return h;
    }
    Node *middle = findMiddle(h);
    Node *mid_next = middle->next;
    middle->next = nullptr;
    if (mid_next != nullptr) {
        mid_next->prev = nullptr;
    }
    Node *left = merge_sort(h);
    Node *right = merge_sort(mid_next);
    return merge_sorted(left, right);
}

template<typename T>
typename Doubly_LinkedList<T>::Node *Doubly_LinkedList<T>::merge_sorted(Node *a, Node *b) {
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }
    Node *result = nullptr;
    if (a->value <= b->value) {
        result = a;
        Node* next_result = merge_sorted(a->next, b);
        result->next = next_result;
        if(next_result != nullptr) {
            next_result->prev = result;
        }
    } else {
        result = b;
        Node* next_result = merge_sorted(a, b->next);
        result->next = next_result;
        if(next_result != nullptr) {
            next_result->prev = result;
        }
    }
    return result;
}

template<typename T>
void Doubly_LinkedList<T>::sort() {
    head = merge_sort(head);
    if (head != nullptr) {
        head->prev = nullptr;
    }
}

template<typename T>
void Doubly_LinkedList<T>::merge(const Doubly_LinkedList<T> &list) {
    if (list.isEmpty()) {
        return;
    }
    if (isEmpty()) {
        head = list.head;
        return;
    }
    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    Node *list_head = list.head;
    current->next = list_head;
    if (list_head != nullptr) {
        list_head->prev = current;
    }
    size += list.size;
}

template<typename T>
void Doubly_LinkedList<T>::reverse() {
    Node *temp = nullptr;
    Node *current = head;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr) {
        head = temp->prev;
    }
}