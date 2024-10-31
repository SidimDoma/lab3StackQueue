#include <iostream>
#include "Stack.h"
#include "Queue.h"

//Захаров Тимофей 23.Б06-мм. Задача 3 "Стек и очередь"
int main() {
    Stack<int> stack;
    int stackSize;

    std::cout << "Enter number of stack elements: ";
    std::cin >> stackSize;
    std::cout << "Enter stack elements:\n";
    for (int i = 0; i < stackSize; ++i) {
        int element;
        std::cin >> element;
        stack.Push(element);
    }

    std::cout << "Stack: " << stack << std::endl;
    if (!stack.IsEmpty()) {
        std::cout << "Head element: " << stack.GetTop() << std::endl;
        stack.Pop();
        std::cout << "Stack after Pop: " << stack << std::endl;
    }

    Queue<int> queue;
    int queueSize;

    std::cout << "Enter number of queue elements: ";
    std::cin >> queueSize;
    std::cout << "Enter queue elements:\n";
    for (int i = 0; i < queueSize; ++i) {
        int element;
        std::cin >> element;
        queue.Push(element);
    }

    std::cout << "Queue: " << queue << std::endl;
    if (!queue.IsEmpty()) {
        std::cout << "Head element: " << queue.GetFront() << std::endl;
        queue.Pop();
        std::cout << "Queue after Pop: " << queue << std::endl;
    }

    return 0;
}

