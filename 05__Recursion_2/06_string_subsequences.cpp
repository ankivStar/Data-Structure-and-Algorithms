#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int subsequences(string s, string *op)
{
    if (s.size() == 0)
    {
        op[0] = "";
        return 1;
    }

    int smallerOutputSize = subsequences(s.substr(1), op);
    cout<< smallerOutputSize << endl;
    for(int i = 0; i < smallerOutputSize; i++)
    {
        op[i + smallerOutputSize] = s[0] + op[i];
    }

    return 2 * smallerOutputSize;
}

int main()
{
    string input;
    cin >> input;
    int l = input.length();
    int outSize = pow(2, l);
    string *output = new string[outSize];
    int count  = subsequences(input, output);

    for(int i = 0; i < count ; i++)
    {
        cout << output[i] << endl;
    }

    delete [] output;
    return 0;
}