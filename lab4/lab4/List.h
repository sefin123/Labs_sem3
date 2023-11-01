#pragma once
#include "Header.h"

template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(const T& data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    List() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~List() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void clearList() {
        if (isEmpty()) {
            std::cout << "List is empty!";
            return;
        }
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        this->size = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void pushBack(const T& data) {
        
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void pushFront(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void popBack() {
        if (isEmpty()) {
            std::cout << "List is empty!";
            return;
        }
            Node<T>* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }
            delete temp;
            size--;
    }

    void popFront() {
        if (isEmpty()) {
            std::cout << "List is empty!";
            return;
        }
            Node<T>* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete temp;
            size--;
    }

    int getSize() const {
        return size;
    }

    T peek(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Invalid position");
        }

        Node<T>* current = head;

        if (current != nullptr) {

            int i = 0;
            while (current != nullptr && i < index) {
                current = current->next;
                i++;
            }

            if (current == nullptr)
                std::cout << "Invalid index." << endl;
        }
        return current->data;
    }

    void printList() const {
        std::cout << endl << "List:";
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << endl;
    }
};