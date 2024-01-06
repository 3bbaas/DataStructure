#ifndef dbl_
#define dbl_


class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node() {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
};

void insertFront(int _item);

void insertEnd(int _item);

void insertOrder(int _item);

void deleteEnd();

void deleteFront();

void display();

bool search(int _item);

#endif //dbl_
