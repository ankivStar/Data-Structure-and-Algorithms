#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arraySubset(int *input, int **output, int size)
{
    if (size == 0)
    {
        output[0][0] = 0;
        return 1;
    }

    int smallerOutput = arraySubset(input + 1, output, size - 1);

    int i,col;
    for (i = 0; i < smallerOutput; i++)
    {
        col = output[i][0] + 1;
        output[i + smallerOutput][0] = col;

        output[i + smallerOutput][1] = input[0];
        for (int j = 2; j < col + 1; j++)
        {
            output[i + smallerOutput][j] = output[i][j - 1];
        }
    }

    return 2 * smallerOutput;
}

int subsetSum(int *input,int size,int **Routput,int k)
{
    int outLen = pow(2, size);

    // Dynamically allocating 2D array
    int **output = new int *[outLen];
    for (int i = 0; i < outLen; i++)
    {
        output[i] = new int[size + 1];
    }

    int result = arraySubset(input, output, size);

    int sum, row = 0;
    for (int i = 0; i < result; i++)
    {
        sum = 0;
        int length = output[i][0];
        for(int j = 1; j < length + 1; j++)
        {
            sum = sum + output[i][j];
        }

        if(sum == k)
        {
            Routput[row][0] = length;
            for(int h = 1; h < length + 1; h++)
            {
                Routput[row][h] = output[i][h];
            }
            row++;
        }
    }

    for (int i = 0; i < outLen; i++)
    {
        delete[] output[i];
    }
    delete[] output;

    return row;


}

int main()
{
    int size;
    cin >> size;
    int *input = new int[size]; // creating dynamic 1D array input
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }
    int k;
    cin >> k;
    int outLen = pow(2, size);

    // Dynamically allocating 2D array
    int **Routput = new int *[outLen];
    for (int i = 0; i < outLen; i++)
    {
        Routput[i] = new int[size + 1];
    }

    int len = subsetSum(input, size, Routput, k); // calling fun arraysubset and storing the result in len variable

    // printing the resultant array of subset
    for (int i = 0; i < len; i++)
    {
        int index = Routput[i][0];
        for (int j = 1; j <= index; j++)
        {
            cout << Routput[i][j] << " ";
        }
        cout << endl;
    }

    delete[] input; // deallocating dynamic memory to 1D array input

    for (int i = 0; i < outLen; i++) // deallocating dynamic memory to 2D array Routput
    {
        delete[] Routput[i];
    }
    delete[] Routput;
    return 0;
}