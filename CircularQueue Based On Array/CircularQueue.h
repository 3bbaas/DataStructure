#ifndef cq_
#define cq_
#define MaxSize 100


class CQ {
public:
    int front, rear;
    int entry[MaxSize];
};

void CreateCQ(CQ *cq);

bool isFull(CQ *cq);

bool isEmpty(CQ *cq);

void enqueue(int _item, CQ *cq);

void dequeue(CQ *cq);

void display(CQ *cq);

void clear(CQ *cq);
#endif //cq_
