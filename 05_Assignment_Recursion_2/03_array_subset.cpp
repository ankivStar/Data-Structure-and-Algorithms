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

    for (int i = 0; i < smallerOutput; i++)
    {
        int col = output[i][0] + 1;
        output[i + smallerOutput][0] = output[i][0] + 1;

        output[i + smallerOutput][1] = input[0];
        for (int j = 2; j < col + 1; j++)
        {
            output[i + smallerOutput][j] = output[i][j - 1];
        }
        
    }

    return 2 * smallerOutput;
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

    int outLen = pow(2, size);

    // Dynamically allocating 2D array
    int **output = new int *[outLen];
    for (int i = 0; i < outLen; i++)
    {
        output[i] = new int[size + 1];
    }

    int len = arraySubset(input, output, size); //calling fun arraysubset and storing the result in len variable

    //printing the resultant array of subset
    for (int i = 0; i < len; i++)           
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    delete[] input; // deallocating dynamic memory to 1D array input 

    // deallocating dynamic memory to 2D array output
    for (int i = 0; i < outLen + 1; i++)
    {
        delete[] output[i];
    }
    delete[] output;
    return 0;
}