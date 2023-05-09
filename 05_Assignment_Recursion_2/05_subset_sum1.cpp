#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int subsetSum(int *input, int size, int **output, int k)
{
    if (size == 0)
    {
        if (k == 0)
        {
            output[0][0] = {0};
            return 1;
        }
        else{
        return 0;
        }
    }

    int r1 = subsetSum(input + 1, size - 1, output, k);

    int r2 = subsetSum(input + 1, size - 1, output + r1, k - input[0]);

    for (int i = 0; i < r2; i++)
    {
        output[r1 + i][0] += 1;
        for (int j = output[r1 + i][0]; j > 1; j--)
        {
            output[r1 + i][j] = output[r1 + i][j - 1];
        }
        output[r1 + i][1] = input[0];
    }
    return r1 + r2;
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

    int outLen = pow(2, size);
    int **output = new int *[outLen];

    for (int i = 0; i < outLen; i++)
    {
        output[i] = new int[size + 1];
    }

    int result = subsetSum(input, size, output, k);
    
    for (int i = 0; i < result; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < outLen; i++)
    {
        delete[] output[i];
    }
    delete[] output;
    delete[] input;

    return 0;
}