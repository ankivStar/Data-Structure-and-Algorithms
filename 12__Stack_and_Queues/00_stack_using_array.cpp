#include <climits>
#include <iostream>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray(int totalSize)
    {
        this->data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
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
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack is full" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // delete
    int pop()
    {
        if (nextIndex == 0)
        {
            cout << "Stack is empty " << endl;
            return INT_MIN;
        }

        nextIndex--;
        return data[nextIndex];
    }

    int top()
    { 
        if(isEmpty())
        {
            cout << "Stack is empty " << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};

