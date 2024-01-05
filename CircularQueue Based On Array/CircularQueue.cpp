#include "CircularQueue.h"
#include <iostream>

void CreateCQ(CQ *cq) { cq->front = cq->rear = -1; }

bool isFull(CQ *cq) {
    return cq->rear == (cq->front - 1) % (MaxSize - 1)
           || ((cq->front == 0) && (cq->rear == MaxSize - 1));
}

bool isEmpty(CQ *cq) { return cq->rear == cq->front && cq->front == -1; }

void enqueue(int _item, CQ *cq) {
    if (!isFull(cq)) {
        if (cq->front == -1) cq->front = 0;
        cq->rear = (cq->rear + 1) % MaxSize;
        cq->entry[cq->rear] = _item;
        std::cout << "Item " << _item << " already added\n";
        return;
    }
    std::cout << "=> Stack Overflow\n";
}

void dequeue(CQ *cq) {
    if (!isEmpty(cq)) {
        int _item = cq->entry[cq->front];
        if (cq->rear == cq->front)cq->rear = cq->front = -1;
        else cq->front = (cq->front + 1) % MaxSize;
        std::cout << "Item " << _item << " already deleted\n";
        return;
    }
    std::cout << "=> Stack Underflow\n";
}

void display(CQ *cq) {
    if (!isEmpty(cq)) {
        std::cout << "Queue [";
        for (int i = cq->front; i != cq->rear; ++i %= MaxSize) {
            std::cout << cq->entry[i] << ", ";
        }
        std::cout << cq->entry[cq->rear] << "]\n";
    }
}

void clear(CQ *cq) {
    cq->front = cq->rear = -1;
    std::cout << "Q is cleared successfully";
}
