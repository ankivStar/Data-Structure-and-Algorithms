#include <iostream>
using namespace std;

string pairStar(string s)
{
    if ((s.length() == 0) || (s.length() == 1))
    {
        return s;
    }
    if (s[0] == s[1])
    {
        string s1 = s.substr(0, 1);
        string s2 = s.substr(1);
        s = s1 + "*" + s2;
        return s.substr(0,2) + pairStar(s.substr(2));
    }
    else
    {
        string a1 = s.substr(0, 1);
        string a2 = pairStar(s.substr(1));
        return a1 + a2;
    }
}

int main()
{
    string s;
    cin >> s;
    cout << pairStar(s);
    return 0;
}