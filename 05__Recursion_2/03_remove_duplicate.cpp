#include <iostream>
using namespace std;

void removeDuplicate(char s[])
{
    if(s[0] == '\0')
    {
        return;
    }
    if(s[0] != s[1])
    {
        removeDuplicate(s + 1);
    }
    else{
        int i = 1;
        for (; s[i] != '\0'; i++)
        {
            s[i - 1] = s[i];
        }
        s[i - 1] = s[i];
        removeDuplicate(s);
    }
}

int main()
{
    char str[100];
    cin>> str;

    removeDuplicate(str);
    cout<< str;
return 0;
}