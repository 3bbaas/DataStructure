#include <bits/stdc++.h>
using namespace std;
#define kill(X) return void(cout << (X) << '\n');
namespace DataStructure
{
    class Stack
    {
    public:
        int Mx_size, size = 0;
        vector<int> arr;
        Stack(int siz)
        {
            this->Mx_size = siz;
            arr = vector<int>(siz, -1);
        };

    private:
        bool is_full()
        {
            return size >= Mx_size;
        }

    public:
        bool is_empty() // size = 0
        {
            if (arr[0] == -1)
                return 1;
            return 0;
        }

        int Size() { return size; }

        int Top() //
        {
            if (!is_empty())
            {
                return cout << arr[size], 0;
            }
        }
        void Pop()
        {
            if (!is_empty())
            {
                arr[--size] = -1;
            }
        }

        void Push(int x)
        {
            if (!is_full())
            {
                arr[size++] = x;
            }
        }
        void display()
        {
            if (is_empty())
            {
                kill("Stack is empty");
            }
            cout << "Stack elements [ ";
            for (int i = 0; i < size - 1; i++)
            {
                cout << arr[i] << ", ";
            }
            cout << arr[size - 1] << " ]";
        }
    };
}
using namespace DataStructure;
int main()
{
    // st.empty();  // return boolean value.
    // st.top();    // return the top value.
    // st.pop();    // remove the top value
    // st.push(5);  // add value on the top.
    // st.size();   // returns size of stack.
    int x;
    cin >> x;
    Stack st(x);
    for (int i = 0; i < x; i++)
    {
        int a;
        cin >> a;
        st.Push(a);
    }
    st.Pop();
    st.display();
    return 0;
}
