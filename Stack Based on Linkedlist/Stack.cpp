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

void search(int _item) {
    if (top == nullptr)return void(std::cout << "Stack is empty!");
    Node *ptr = top;
    while (ptr->next != nullptr) {
        if (_item == ptr->data)
            return void(std::cout << "Item is here" << ptr->data << '\n');
        ptr = ptr->next;
    }
    std::cout << "Not Found\n";
}

void count() {
    int counter = 0;
    if (top == nullptr)return void(std::cout << "Stack is empty!");
    Node *ptr = top;
    while (ptr->next != nullptr) {
        counter++;
        ptr = ptr->next;
    }
    std::cout << "Count of items is " << counter << '\n';
}

int Top() {
    if (top == nullptr)return std::cout << "Stack is empty!", 0;
    return std::cout << "Top stack is " << top->data << '\n', top->data;
}