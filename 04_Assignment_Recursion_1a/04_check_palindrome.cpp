#include <iostream>
using namespace std;

bool helper(string s, int start, int end)
{
    if(end == 0 || start > end)
    {
        return true;
    }
    if (s[start] != s[end])
    {
        return false;
    }

    else
    {
        bool a = helper(s, start + 1, end - 1);
        return a;
    }
}

bool palindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;
    return helper(s, start, end);
}

int main()
{
    string s;
    cin >> s;
    if (palindrome(s))
        cout << "true";
    else
        cout << "false";
    return 0;
}