#include <iostream>
using namespace std;

class Parenthesis
{
    char *cArray;
    int nextIndex;

    public :

    Parenthesis()
    {
        cArray = new char[1000];
        nextIndex = 0;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    int getSize()
    {
        return nextIndex;
    }

    void push(char s)
    {
        if(s == '{' or s == '(' or s == '[')
        {
            cArray[nextIndex++] = s;
        }
    }

    char top()
    {
        // if(isEmpty())
        // {
        //     return 0;
        // }

        return cArray[nextIndex - 1];
    }

    char revTop()
    {
        if(top() == '{')
        {
            return '}';
        }

        else if (top() == '(')
        {
            return ')';
        }

        else{
            return ']';
        }
    }
    bool pop(char s)
    {
        // if(isEmpty())
        // {
        //     return 0;
        // }

       if (s == revTop())
        {
            nextIndex--;
            return true;
        }

        else{
            return false;
        }

    }
};

int main()
{
    Parenthesis p;

    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '{' or s[i] == '(' or s[i] == '[')
        {
            p.push(s[i]);
        }
        
      else if(s[i] == '}' or s[i] == ')' or s[i] == ']')
        {
            if(p.pop(s[i]) != 1)
            {
                break;
            }
        }
    }

    //cout << p.getSize()<< endl;
    if(p.getSize() != 0)
    {
        cout << "false" << endl;
    }

    else{
        cout << "true" << endl;
    }

return 0;
}