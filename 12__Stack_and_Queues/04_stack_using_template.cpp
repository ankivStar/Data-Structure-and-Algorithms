#include <iostream>
using namespace std;

template <typename T>
class StackUsingArray
{
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        this->data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    // return no. of elements in my stack
    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        // if (nextIndex == 0)
        // {
        //     return true;
        // }
        // else{
        //     return false;
        // }

        return (nextIndex == 0);
    }

    // insert element
    void push(T element)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < nextIndex; i++)
            {
                newData[i] = data[i];
            }
            capacity = 2 * capacity;
            delete[] data;
            data = newData;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    // delete
    T pop()
    {
        if (nextIndex == 0)
        {
            cout << "Stack is empty " << endl;
            return 0;
        }

        nextIndex--;
        return data[nextIndex];
    }

    T top()
    {
        if(isEmpty())
        {
            cout << "Stack is empty " << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};

int main()
{
    StackUsingArray<char> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;

    cout << s.isEmpty() << endl;
    return 0;
}