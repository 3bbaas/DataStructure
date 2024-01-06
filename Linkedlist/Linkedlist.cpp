#include<iostream>
#include "Linkedlist.h"

class Linkedlist {
public:
    Node_ *head;

    Linkedlist() {
        head = nullptr;
    }

    bool isEmpty() {
        if (head == nullptr)
            return true;
        return false;
    }

    bool isFull() {
        Node_ *newnode = new Node_();
        if (newnode == nullptr)return true;
        return false;
    }

    void insertFront(int item) {
        Node_ *newnode = new Node_();
        newnode->data = item;
        if (isEmpty()) {
            newnode->next = nullptr;
            head = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    void insertLast(int item) {
        auto *newnode = new Node_();
        newnode->data = item;
        newnode->next = nullptr;
        if (head == nullptr) {
            head = newnode;
        } else {
            Node_ *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    void insertAtPos(int item, int pos1, int pos = 0) {
        Node_ *newnode = new Node_();
        newnode->data = item;
        Node_ *temp = head;
        while (pos++ != pos1)temp = temp->next;
        if (temp == nullptr) {
            delete newnode;
            return;
        }
        newnode->next = temp;
        temp->next = newnode;
    }

    void insertSorted(int item) {
        Node_ *newnode = new Node_();
        newnode->data = item;
        if (isEmpty()) {
            newnode->next = nullptr;
            head = newnode;
        } else {
            Node_ *temp1 = head;
            while ((temp1->data > item && temp1->next->data > item) ||
                   (temp1->data < item && temp1->next->data < item)
                   && temp1 != nullptr) {
                temp1 = temp1->next;
            }
            newnode->next = temp1->next;
            temp1->next = newnode;
        }
    }

    bool search(int item) {
        Node_ *temp = head;
        while (temp != nullptr) {
            if (temp->data == item) return true;
            else temp = temp->next;
        }
        return false;
    }

    void display() {
        Node_ *temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << ' ';
            temp = temp->next;
        }
    }

    void deleteLast() {
        if (isEmpty()) {
            return;
        } else {
            Node_ *temp1 = head;
            Node_ *temp2 = nullptr;
            while (temp1->next != nullptr) {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            delete temp1;
            temp2->next = nullptr;
        }
    }

    void deleteFront() {
        Node_ *temp = head;
        if (isEmpty()) {
            return;
        } else {
            head = head->next;
            delete temp;
            return;
        }
    }

};