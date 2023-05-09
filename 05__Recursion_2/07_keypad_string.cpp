#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string generateString(int n)
{
    string s[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return s[n];
}

int combination(int n, string *output)
{
    if (n < 2)
    {
        output[0] = "";
        return 1;
    }

    int smallerOutputSize = combination(n / 10, output);
    string s1 = generateString(n % 10);

    //cout << smallerOutputSize << " " << s1 << " ";
    string temp[1000];
    int k = 0;
    for(int i = 0; i < smallerOutputSize; i++)
    {
        for(int j = 0; j < s1.length(); j++)
        {
           temp[k++] = output[i] + s1[j];
        }
    }

    for(int i = 0; i < k; i++)
    {
        output[i] = temp[i];
    }

    return s1.length() * smallerOutputSize;
}

int main()
{
    int n;
    cin >> n;

    string *output = new string[1000];
    
    int count = combination(n, output);
    
    //cout << count << endl;
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
    delete[] output;
    return 0;
}