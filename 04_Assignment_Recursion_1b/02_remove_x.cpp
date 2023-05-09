#include <iostream>
using namespace std;

// 1st method
//  string helper(string s, int start, int end)
//  {
//      if (end == 0 || start == end)
//      {
//          return s;
//      }
//      if (s[start] == 'x')
//      {
//          for (int i = start; i < end; i++)
//          {
//              s[i] = s[i + 1];
//          }
//          return helper(s, start, end - 1);
//      }

//     else
//     {
//         string a = helper(s, start + 1, end);
//         return a;
//     }
// }

// string remove(string s)
// {
//     int start = 0;
//     int end = s.length();
//     return helper(s, start, end);
// }


// 2nd method
string remove(string s)
{
    if (s.length() == 0 || !(s.find("x") >= 0 && s.find("x") <= s.length() - 1))
    {
        return s;
    }
    if (s[0] == 'x')
    {
        for (int i = 0; i < s.length() - 1; i++)
        {
            s[i] = s[i + 1];
        }
        return remove(s.substr(0, s.length() - 1));
    }

    else
    {
        string s1 = s.substr(0, 1);
        string s2 = remove(s.substr(1, s.length()));
        return s1 + s2;
    }
}

int main()
{
    string s;
    cin >> s;
    cout << remove(s);
    return 0;
}