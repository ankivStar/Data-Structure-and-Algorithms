#include <iostream>
using namespace std;

void printAllCode(string input, string h)
{
    if(input.length() == 0)
    {
        cout << h << endl;
        return;
    }
    
    int ch1 = input[0]-'0';
    printAllCode(input.substr(1),h + char(ch1 + 'a' - 1));

    int ch2 = (input[0] - '0') * 10 + (input[1] - '0');
    if(input.length() > 1 and ch2 > 9 and ch2 <= 26)
    {
        printAllCode(input.substr(2), h + char(ch2 + 'a' - 1));
    }
}

int main()
{
    string input;
    cin>> input;

    printAllCode(input,"");

return 0;
}