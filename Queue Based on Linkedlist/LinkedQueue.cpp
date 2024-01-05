#include "LinkedQueue.h"
#include<iostream>

NodeQ *rear;
NodeQ *head;

void enQ(int _item) {
    NodeQ *newNode = new NodeQ();
    newNode->data = _item;
    newNode->next = nullptr;
    if (head == nullptr) {
        rear = head = newNode;
        rear->next = nullptr;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void deQ() {
    if (head == nullptr) { return void(std::cout << "Queue is empty!"); }
    NodeQ *temp = head;
    std::cout << "Item " << temp->data << " is enQueued!\n";
    head = head->next;
    delete temp;
}

void countQ() {
    int counter = 0;
    NodeQ *temp = head;
    while (temp->next != nullptr) {
        counter++;
        temp = temp->next;
    }
    std::cout << "Count of Queue is " << counter << '\n';
}

void displayQ() {
    if (head == nullptr) { return void(std::cout << "Queue is empty!"); }
    NodeQ *ptr = head;
    std::cout << "Queue [";
    while (ptr->next != nullptr) {
        if (ptr->next == rear)return void(std::cout << ptr->data << ", " << ptr->next->data << "]\n");
        std::cout << ptr->data << ", ";
        ptr = ptr->next;
    }
}