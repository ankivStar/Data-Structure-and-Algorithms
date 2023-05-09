#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void helper(int *input, int size, int *temp, int pos, int k)
{
    if (size == 0)
    {
        if (k == 0)
        {
            for (int i = 0; i < pos; i++)
            {
                cout << temp[i] << " ";
            }

            cout << endl;
            return;
        }
        return;
    }

    helper(input + 1, size - 1, temp, pos, k);

    temp[pos] = input[0];

    helper(input + 1, size - 1, temp, pos + 1, k - input[0]);
}

void subsetSum(int *input, int size, int k)
{
    int *temp = new int[size];
    int pos = 0;

    helper(input, size, temp, pos, k);

    delete[] temp;
    return;
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    subsetSum(input, size, k);

    delete[] input;

    return 0;
}