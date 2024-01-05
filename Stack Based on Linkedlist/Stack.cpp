#include "Stack.h"
#include <iostream>

// for optimization made it without create new node
Node *top = nullptr;

void push(int _item) {
    Node *newNode = new Node();
    newNode->data = _item;
    newNode->next = top;
    top = newNode;
}

void pop() {
    int _item;
    Node *newNode = top;
    if (top == nullptr)return void(std::cout << "=> Stack Underflow!!");
    std::cout << "Item " << top->data << " is already popped";
    top = top->next;
    delete newNode;
}

void display() {
    if (top == nullptr)return void(std::cout << "Stack is empty!");
    Node *ptr = top;
    std::cout << "Stack: [";
    while (ptr->next != nullptr) {
        if (ptr->next == nullptr)
            std::cout << ptr->data << "]\n";
        std::cout << ptr->data << ", ";
        ptr = ptr->next;
    }
    std::cout << ptr->data << "]\n";
}
