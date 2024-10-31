#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
#include <stdexcept>

//template <typename T>
//class Queue {
//private:
//    struct Node {
//        T data;
//        Node* next;
//        Node(T value) : data(value), next(nullptr) {}
//    };
//
//    Node* frontNode;
//    Node* backNode;
//
//public:
//    Queue() : frontNode(nullptr), backNode(nullptr) {}
//
//    Queue(const Queue& other) : frontNode(nullptr), backNode(nullptr) {
//        if (!other.IsEmpty()) {
//            Node* current = other.frontNode;
//            while (current) {
//                Push(current->data);
//                current = current->next;
//            }
//        }
//    }
//
//    Queue(Queue&& other) noexcept : frontNode(other.frontNode), backNode(other.backNode) {
//        other.frontNode = nullptr;
//        other.backNode = nullptr;
//    }
//
//    ~Queue() {
//        while (!IsEmpty()) {
//            Pop();
//        }
//    }
//
//    Queue& operator=(const Queue& other) {
//        if (this != &other) {
//            while (!IsEmpty()) {
//                Pop();
//            }
//            Node* current = other.frontNode;
//            while (current) {
//                Push(current->data);
//                current = current->next;
//            }
//        }
//        return *this;
//    }
//
//    Queue& operator=(Queue&& other) noexcept {
//        if (this != &other) {
//            while (!IsEmpty()) {
//                Pop();
//            }
//            frontNode = other.frontNode;
//            backNode = other.backNode;
//            other.frontNode = nullptr;
//            other.backNode = nullptr;
//        }
//        return *this;
//    }
//
//    void Push(const T& value) {
//        Node* newNode = new Node(value);
//        if (IsEmpty()) {
//            frontNode = newNode;
//        } else {
//            backNode->next = newNode;
//        }
//        backNode = newNode;
//    }
//
//    void Pop() {
//        if (IsEmpty()) {
//            throw std::runtime_error("Queue is empty!");
//        }
//        Node* temp = frontNode;
//        frontNode = frontNode->next;
//        delete temp;
//        if (frontNode == nullptr) {
//            backNode = nullptr;
//        }
//    }
//
//    bool IsEmpty() const {
//        return frontNode == nullptr;
//    }
//
//    T& GetFront() {
//        if (IsEmpty()) {
//            throw std::runtime_error("Queue is empty!");
//        }
//        return frontNode->data;
//    }
//
//    friend std::ostream& operator<<(std::ostream& os, const Queue& queue) {
//        Node* current = queue.frontNode;
//        os << "[";
//        while (current) {
//            os << current->data;
//            if (current->next) {
//                os << ", ";
//            }
//            current = current->next;
//        }
//        os << "]";
//        return os;
//    }
//
//    friend std::istream& operator>>(std::istream& is, Queue& queue) {
//        T val;
//        while (is >> val) {
//            queue.Push(val);
//        }
//        return is;
//    }
//};

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* backNode;

public:
    Queue();                                                                            // ����������� �� ���������
    Queue(const Queue& other);                                                          // ����������� �����������
    Queue(Queue&& other) noexcept;                                                      // ����������� �����������
    ~Queue();                                                                           // ����������
    Queue& operator=(const Queue& other);                                               // �������� ������������
    Queue& operator=(Queue&& other) noexcept;                                           // �������� ������������ ������������

    void Push(const T& value);                                                          // ���������� ��������
    void Pop();                                                                         // ���������� ��������
    bool IsEmpty() const;                                                               // �������� �� �������
    T& GetFront();                                                                      // ��������� ������ �� �������� �������

    friend std::ostream& operator<<(std::ostream& os, const Queue& queue) {
        Node* current = queue.frontNode;
        os << "[";
        while (current) {
            os << current->data;
            if (current->next) {
                os << ", ";
            }
            current = current->next;
        }
        os << "]";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Queue& queue) {
        T val;
        while (is >> val) {
            queue.Push(val);
        }
        return is;
    }
};

// �������� �������
template <typename T>
Queue<T>::Queue() : frontNode(nullptr), backNode(nullptr) {}

template <typename T>
Queue<T>::Queue(const Queue& other) : frontNode(nullptr), backNode(nullptr) {
    if (!other.IsEmpty()) {
        Node* current = other.frontNode;
        while (current) {
            Push(current->data);
            current = current->next;
        }
    }
}

template <typename T>
Queue<T>::Queue(Queue&& other) noexcept : frontNode(other.frontNode), backNode(other.backNode) {
    other.frontNode = nullptr;
    other.backNode = nullptr;
}

template <typename T>
Queue<T>::~Queue() {
    while (!IsEmpty()) {
        Pop();
    }
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this != &other) {
        while (!IsEmpty()) {
            Pop();
        }
        Node* current = other.frontNode;
        while (current) {
            Push(current->data);
            current = current->next;
        }
    }
    return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& other) noexcept {
    if (this != &other) {
        while (!IsEmpty()) {
            Pop();
        }
        frontNode = other.frontNode;
        backNode = other.backNode;
        other.frontNode = nullptr;
        other.backNode = nullptr;
    }
    return *this;
}

template <typename T>
void Queue<T>::Push(const T& value) {
    Node* newNode = new Node(value);
    if (IsEmpty()) {
        frontNode = newNode;
    } else {
        backNode->next = newNode;
    }
    backNode = newNode;
}

template <typename T>
void Queue<T>::Pop() {
    if (IsEmpty()) {
        throw std::runtime_error("Queue is empty!");
    }
    Node* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
    if (frontNode == nullptr) {
        backNode = nullptr;
    }
}

template <typename T>
bool Queue<T>::IsEmpty() const {
    return frontNode == nullptr;
}

template <typename T>
T& Queue<T>::GetFront() {
    if (IsEmpty()) {
        throw std::runtime_error("Queue is empty!");
    }
    return frontNode->data;
}

#endif // QUEUE_H_INCLUDED
