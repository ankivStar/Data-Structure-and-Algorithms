#include <iostream>
using namespace std;

bool checkAB(string s)
{

    if (s[0] == 'a') // checking for rule (a)
    {
        if (s[1] == 'b' and s[2] == 'b') // checking for rule (b).
        {
            if (s[3] == 'a') // checking for rule (c).
            {
                return checkAB(s.substr(3));// recursion will check rest of the string
            }
            if (s.length() == 3) // returning 'true' if string end with "abb".
            {
                return true;
            }
            else // returning 'false' if rule c violated.
            {
                return false;
            }
        }

        if (s[1] == 'a') // checking for rule (b).
        {
            return checkAB(s.substr(1)); // recursion will check rest of the string.
        }
        if (s.length() == 1) // returning true if string end with a or aa or aaa etc.
        {
            return true;
        }
        else // returning 'false' if rule (b) violated.
        {
            return false;
        }
    }
    else // retrurning 'false' if rule (a) violated.
    {
        return false;
    }
}

int main()
{
    string s;
    cin >> s;
    
    if (checkAB(s))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}