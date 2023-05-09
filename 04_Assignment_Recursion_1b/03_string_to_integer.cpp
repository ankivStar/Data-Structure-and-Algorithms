#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//1st Method
// int helper(string s, int start, int end)
// {
//     if(end == 0)
//     {
//         return 0;
//     }
//     if(end == 1)
//     {
//         return (int)s[start] - 48;
//     }
//     else{
//     int digit = ((int)s[start] - 48) * pow(10,end-1);
//     int smallerOutput = helper(s,start+1,end-1);
//     return smallerOutput + digit;
//     }
// }

// int strToInt(string s)
// {
//     int start = 0;
//     int end = s.length();
//     return helper(s,start,end);
// }


//2nd Method
int strToInt(string s)
{
    if (s.length() == 0)
    {
        return 0;
    }
    if (s.length() == 1)
    {
        return (int)s[0] - 48;
    }
    else
    {

        int digit = ((int)s[0] - 48) * pow(10, (s.length() - 1));
        int smallerOutput = strToInt(s.substr(1));
        return smallerOutput + digit;
    }
}

int main()
{
    string s;
    cin >> s;
    //cout<< s[1,3];
    cout << strToInt(s);
    return 0;
}