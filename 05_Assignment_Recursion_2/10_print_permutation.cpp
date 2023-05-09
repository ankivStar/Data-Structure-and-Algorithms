#include <iostream>
using namespace std;

void helper(string input, string temp)
{
    if (input.length() == 0)
    {
        cout << temp << endl;
        return;
    }

    for (int i = 0; i < input.length(); i++)
    {
        string s = input.substr(i, 1);
        string s1 = input.substr(0,i) + input.substr(i + 1);
        helper(s1, temp + s);
    }
}

void printPermutation(string input)
{
    string temp = "";
    helper(input, temp);
}

int main()
{
    string input;
    cin >> input;

    printPermutation(input);
    return 0;
}