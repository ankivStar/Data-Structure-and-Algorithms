#include <iostream>
using namespace std;

string generateString(int n)
{
    string s[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return s[n];
}

void print_keypad(int n, string output)
{
    if(n < 2)
    {
        cout << output << endl;
        return;
    }
    int d = n % 10;
    string s = generateString(d);
    int smallerNum = n / 10;
    for(int i = 0; i < s.length(); i++)
    {
    print_keypad(smallerNum, s[i] + output);
    }
    
    if(s.length() == 0)
    {
        print_keypad(smallerNum,s[0] + output);
    }
    
}
int main()
{
    int n;
    cin>>n;
    print_keypad(n,"");
    
return 0;
}