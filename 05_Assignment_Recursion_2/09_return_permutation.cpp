#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int permutation(string input, string *output)
{
    if (input.length() == 0)
    {
        output[0] = "\0";
        return 1;
    }

    int len = 0;
    for (int i = 0; i < input.length(); i++)
    {
        string s = input.substr(i,1);
        string s1 = input.substr(0, i) + input.substr(i + 1);
        int r = permutation(s1, output + len);
        
        for (int j = len; j < len + r; j++)
        {
            output[j] = s + output[j];
        }
        len = len + r;
    }

    return len;
}

int main()
{
    string input;
    cin >> input;

    int outlen = input.length() * (input.length() - 1);

    string *output = new string[outlen];

    int result = permutation(input, output);
    cout << result << " result" << endl;
    for (int i = 0; i < result; i++)
    {
       cout << output[i] << endl;
    }

    delete [] output;

    return 0;
}