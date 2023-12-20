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

    friend std::ofstream& operator<<(std::ofstream& os, Node<T>& obj) {
        os << obj.data;
        return os;
    }
};

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:

    class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator(Node<T>* node) : current(node) {}

        T& operator*() {
            return current->data;
        }

        Iterator& operator+(int value) {
            for (int i = 0; i < value; i++) {
                if (current->next == nullptr) {
                    break;
                }
                current = current->next;
            }
            return *this;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        Iterator& operator--() {
            current = current->prev;
            return *this;
        }
    };

    using iter = Iterator;

    iter begin() {
        return iter(head);
    }

    iter end() {
        return iter(nullptr);
    }


    bool search(List<T>::iter start, List<T>::iter end, const T& value) {
        for (auto it = start; start != end; ++it) {
            if (*it == value) {
                return true;
            }
        }
        return false;
    }

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
            std::cout << "List is empty!" << std::endl;
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

    Node<T>* getHead() {
        return this->head;
    }

    T peek(int index) {
        if (index < 0 || index >= size) {
            throw std::exception();
        }

        Node<T>* current = head;

        if (current != nullptr) {

            int i = 0;
            while (current != nullptr && i < index) {
                current = current->next;
                i++;
            }

            if (current == nullptr)
                std::cout << "Invalid index." << std::endl;
        }
        return current->data;
    }

    void writeFromListToTXTFile() {
        std::ofstream file("test.txt");
        if (file.is_open()) {
            Node<T>* current = this->head;
            while (current != nullptr) {
                file << *current;
                current = current->next;
            }
            file.close();
            
        }
        else {
            throw std::exception();
        }
    }

    void readFromTXTFileToList() {
        std::ifstream inputFile("test.txt");
        if (inputFile.is_open()) {
            T value;
            while (inputFile >> value) {
                Node<T>* newNode = new Node<T>(value);

                if (this->head == nullptr) {
                    this->head = newNode;
                    this->tail = newNode;
                }
                else {
                    newNode->prev = this->tail;
                    this->tail->next = newNode;
                    this->tail = newNode;
                }
                this->size++;
            }
            inputFile.close();
        }
        else {
            throw std::exception();
        }
    }

    void writeFromlistToBinatyFile() {
        std::ofstream file("testBin.bin", std::ios::binary);
        if (file.is_open()) {
            Node<T>* current = head;

            while (current) {
                file.write(reinterpret_cast<char*>(&current->data), sizeof(T));
                current = current->next;
            }
            file.close();
        }
        else {
            throw std::exception();
        }
    }

    void readFromBinaryFileToList() {
        std::ifstream file("testBin.bin", std::ios::binary);
        if (file.is_open()) {

            while (!file.eof()) {
                T data;
                file.read(reinterpret_cast<char*>(&data), sizeof(T));
                if (file.gcount() == sizeof(T)) {
                    pushBack(data);
                }
            }
            file.close();
        }
        else {
            throw std::exception();
        }
    }

    void writeListToFile() {
        try {
            this->writeFromListToTXTFile();
        }
        catch (std::exception& problem) {
            std::string msg;
            msg = problem.what();
            std::cout << msg;
        }
        try {
            this->writeFromlistToBinatyFile();
        }
        catch (std::exception& problem) {
            std::string msg;
            msg = problem.what();
            std::cout << msg;
        }
    }
};