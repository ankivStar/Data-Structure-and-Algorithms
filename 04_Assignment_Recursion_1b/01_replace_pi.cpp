#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

//Method 1
// string helper(string s, int start, int end)
// {
//     if (end == 0 || start >= end)
//     {
//         return s;
//     }

//     if (s[start] == 'p' && s[start + 1] == 'i')
//     {
//         s.replace(start, 2, "3.14");
//         return helper(s, start + 4, end + 2);
//     }

//     else
//     {
//         string a1 = helper(s, start + 1, end);
//         return a1;
//     }
// }

// string replacePi(string s)
// {
//     int start = 0;
//     int end = s.length() - 1;
//     return helper(s, start, end);
// }

//Method 2
string replacePi(string s)
{
    if(s.length() == 0 || s.length() == 1)
    {
        return s;
    }

    if(s[0] == 'p' && s[1] == 'i')
    {
        s.replace(0,2,"3.14");
        return s.substr(0,4) + replacePi(s.substr(4));
    }
    else{
        string s1 = s.substr(0,1);
        string s2 = replacePi(s.substr(1));
        return s1 + s2;
    }
}

int main()
{
    string s;
    cin >> s;
    cout << replacePi(s);
    return 0;
}