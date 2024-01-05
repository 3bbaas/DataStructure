#include<iostream>
#include"CircularQueue.h"
#include"Stack.h"

using namespace std;

int n;

bool ok(int k) {
    cin >> n;
    for (int i = 1; i <= k; ++i) {
        if (i == n)return true;
    }
    return false;
}


int main() {
//#define _cq
#ifdef _cq
    string introCQ = R"(
===============
1-> EnQ
2-> DeQ
3-> display
4-> isFull
5-> isEmpty
6-> clear
===============
)";
    CQ cq{};
    cout << introCQ;
    int q;
    while (ok(6)) {
        if (n == 1)
            cin >> q, enqueue(q, &cq);
        else if (n == 2)
            dequeue(&cq);
        else if (n == 3)
            display(&cq);
        else if (n == 4)
            cout << (isFull(&cq) ? "Q is full" : "Q not full");
        else if (n == 5)
            cout << (isEmpty(&cq) ? "Q is empty" : "Q not empty");
        else if (n == 6)
            clear(&cq);
        cout << introCQ;
    }
#endif //_cq


//#define _st
#ifdef _st
    string introSt = R"(
===============
1-> push
2-> pop
3-> display
4-> search
5-> count
6-> Top
===============
)";

    cout << introSt;
    int q;
    while (ok(4)) {
        if (n == 1)
            cin >> q, push(q);
        else if (n == 2)
            pop();
        else if (n == 3)
            display();
        else if (n == 4)
            cin >> q, search(q);
        else if (n == 5)
            count();
        else if (n == 6)
            Top();
        cout << introSt;
    }
#endif //_st


    return 0;
}