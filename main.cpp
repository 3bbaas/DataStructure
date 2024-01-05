#include<iostream>
#include"CircularQueue.h"

using namespace std;

int n;

bool ok() {
    cin >> n;
    for (int i: {1, 2, 3, 4, 5, 6})
        if (i == n)return true;
    return false;
}

string intro = R"(
===============
1-> EnQ
2-> DeQ
3-> display
4-> isFull
5-> isEmpty
6-> clear
===============
)";

int main() {
    CQ cq{};
    CreateCQ(&cq);
    cout << intro;
    int q;
    while (ok()) {
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
        cout << intro;
    }

    return 0;
}