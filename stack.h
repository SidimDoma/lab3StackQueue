#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <stdexcept>

//template <typename T>
//class Stack {
//private:
//    struct Node {
//        T data;
//        Node* next;
//        Node(T value) : data(value), next(nullptr) {}
//    };
//
//    Node* topNode;
//
//public:
//    Stack() : topNode(nullptr) {}
//
//    Stack(const Stack& other) : topNode(nullptr) {
//        if (!other.IsEmpty()) {
//            Node* current = other.topNode;
//            Node* prev = nullptr;
//            while (current) {
//                Node* newNode = new Node(current->data);
//                if (prev) {
//                    prev->next = newNode;
//                } else {
//                    topNode = newNode;
//                }
//                prev = newNode;
//                current = current->next;
//            }
//        }
//    }
//
//    Stack(Stack&& other) noexcept : topNode(other.topNode) {
//        other.topNode = nullptr;
//    }
//
//    ~Stack() {
//        while (!IsEmpty()) {
//            Pop();
//        }
//    }
//
//    Stack& operator=(const Stack& other) {
//        if (this != &other) {
//            while (!IsEmpty()) {
//                Pop();
//            }
//            Node* current = other.topNode;
//            Node* prev = nullptr;
//            while (current) {
//                Node* newNode = new Node(current->data);
//                if (prev) {
//                    prev->next = newNode;
//                } else {
//                    topNode = newNode;
//                }
//                prev = newNode;
//                current = current->next;
//            }
//        }
//        return *this;
//    }
//
//    Stack& operator=(Stack&& other) noexcept {
//        if (this != &other) {
//            while (!IsEmpty()) {
//                Pop();
//            }
//            topNode = other.topNode;
//            other.topNode = nullptr;
//        }
//        return *this;
//    }
//
//    void Push(const T& value) {
//        Node* newNode = new Node(value);
//        newNode->next = topNode;
//        topNode = newNode;
//    }
//
//    void Pop() {
//        if (IsEmpty()) {
//            throw std::runtime_error("Stack is empty!");
//        }
//        Node* temp = topNode;
//        topNode = topNode->next;
//        delete temp;
//    }
//
//    bool IsEmpty() const {
//        return topNode == nullptr;
//    }
//
//    T& GetTop() {
//        if (IsEmpty()) {
//            throw std::runtime_error("Stack is empty!");
//        }
//        return topNode->data;
//    }
//
//    friend std::ostream& operator<<(std::ostream& os, const Stack& stack) {
//        Node* current = stack.topNode;
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
//    friend std::istream& operator>>(std::istream& is, Stack& stack) {
//        T val;
//        while (is >> val) {
//            stack.Push(val);
//        }
//        return is;
//    }
//};

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* topNode;

public:
    Stack();                                                                        // Конструктор по умолчанию
    Stack(const Stack& other);                                                      // Конструктор копирования
    Stack(Stack&& other) noexcept;                                                  // Конструктор перемещения
    ~Stack();                                                                       // Деструктор
    Stack& operator=(const Stack& other);                                           // Оператор присваивания
    Stack& operator=(Stack&& other) noexcept;                                       // Оператор присваивания перемещением

    void Push(const T& value);                                                      // Добавление элемента
    void Pop();                                                                     // Извлечение элемента
    bool IsEmpty() const;                                                           // Проверка на пустоту
    T& GetTop();                                                                    // Получение ссылки на верхний элемент

    friend std::ostream& operator<<(std::ostream& os, const Stack& stack) {
        Node* current = stack.topNode;
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

    friend std::istream& operator>>(std::istream& is, Stack& stack) {
        T val;
        while (is >> val) {
            stack.Push(val);
        }
        return is;
    }
};

template <typename T>
Stack<T>::Stack() : topNode(nullptr) {}

template <typename T>
Stack<T>::Stack(const Stack& other) : topNode(nullptr) {
    if (!other.IsEmpty()) {
        Node* current = other.topNode;
        Node* prev = nullptr;
        while (current) {
            Node* newNode = new Node(current->data);
            if (prev) {
                prev->next = newNode;
            } else {
                topNode = newNode;
            }
            prev = newNode;
            current = current->next;
        }
    }
}

template <typename T>
Stack<T>::Stack(Stack&& other) noexcept : topNode(other.topNode) {
    other.topNode = nullptr;
}

template <typename T>
Stack<T>::~Stack() {
    while (!IsEmpty()) {
        Pop();
    }
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        while (!IsEmpty()) {
            Pop();
        }
        Node* current = other.topNode;
        Node* prev = nullptr;
        while (current) {
            Node* newNode = new Node(current->data);
            if (prev) {
                prev->next = newNode;
            } else {
                topNode = newNode;
            }
            prev = newNode;
            current = current->next;
        }
    }
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& other) noexcept {
    if (this != &other) {
        while (!IsEmpty()) {
            Pop();
        }
        topNode = other.topNode;
        other.topNode = nullptr;
    }
    return *this;
}

template <typename T>
void Stack<T>::Push(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = topNode;
    topNode = newNode;
}

template <typename T>
void Stack<T>::Pop() {
    if (IsEmpty()) {
        throw std::runtime_error("Stack is empty!");
    }
    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
}

template <typename T>
bool Stack<T>::IsEmpty() const {
    return topNode == nullptr;
}

template <typename T>
T& Stack<T>::GetTop() {
    if (IsEmpty()) {
        throw std::runtime_error("Stack is empty!");
    }
    return topNode->data;
}

#endif // STACK_H_INCLUDED
