#include <iostream>
using namespace std;

void print_subseq(string input, string output)
{
    if( input.length() == 0)
    {
        cout << output << endl;
        return;
    }
    print_subseq(input.substr(1), output);
    print_subseq(input.substr(1), output + input[0]);
}

int main()
{
    string s;
    cin>> s;
    print_subseq(s,"");
    
return 0;
}