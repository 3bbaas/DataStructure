#include "DoublyLinkedlist.h"
#include <iostream>

Node *head = nullptr;

bool isEmpty() {
    if (head == nullptr)return true;
    return false;
}

void insertFront(int _item) {
    Node *newNode = new Node();
    newNode->data = _item;
    if (isEmpty()) {
        newNode->next = newNode->prev = nullptr;
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertEnd(int _item) {
    Node *newNode = new Node();
    Node *temp = head;
    newNode->data = _item;
    while (temp->next != nullptr)
        temp = temp->next;
    newNode->next = nullptr;
    temp->next = newNode;
}

void insertOrder(int _item) {
    Node *newNode = new Node();
    Node *temp = head;
    newNode->data = _item;
    while (((temp->data < _item && temp->next->data < _item) ||
            (temp->data > _item && temp->next->data > _item)) &&
           temp != nullptr)
        temp = temp->next;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    newNode->next->prev = newNode;
}

void deleteEnd() {
    if (isEmpty())
        return;
    Node *temp = head;
    Node *temp1 = nullptr;
    while (temp != nullptr) {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = nullptr;
    delete temp;
}

void deleteFront() {
    if (isEmpty())
        return;
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
}

void display() {
    Node *temp = head;
    while (temp != nullptr)
        std::cout << temp->data, temp = temp->next;
}

bool search(int _item) {
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->data == _item)
            return true;
        temp = temp->next;
    }
    return false;
}