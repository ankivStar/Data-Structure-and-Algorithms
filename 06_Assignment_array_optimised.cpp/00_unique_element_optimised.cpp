#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool uniqueElement(int * input, int size)
{
    sort(input, input + size);
    for (int i = 0; i < size; i++)
    {
        if ( input[i] != input[i + 1])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int size = (2 * n) + 1;

    int input[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    if (uniqueElement(input, size))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
return 0;
}