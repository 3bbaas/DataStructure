#ifndef st_
#define st_


class Node {
public:
    int data;
    Node *next;

    Node() { data = 0, next = nullptr; }
};


void push(int _item);

void pop();

int Top();

void display();

void count();

void search(int _item);

#endif //st_
