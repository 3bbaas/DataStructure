#ifndef Q_
#define Q_


class NodeQ {
public:
    int data;
    NodeQ *next;

    NodeQ() { data = 0, next = nullptr; }
};

void enQ(int _item);

void deQ();

void displayQ();

void countQ();

void getRear();

void getFront();

#endif //Q_
