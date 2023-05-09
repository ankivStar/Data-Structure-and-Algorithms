#include <iostream>
#include <cstring>
using namespace std;

int allCode(string input, string *output)
{
    if (input.length() == 0)
    {
        output[0] = '\0';
        return 1;
    }

    int ch1 = (input[0] - '0');
    int r1 = allCode(input.substr(1), output);
    for (int i = 0; i < r1; i++)
    {
        output[i] = char(ch1 + 'a' - 1) + output[i];
    }

    int ch2 = (input[0] - '0') * 10 + (input[1] - '0');
    int r2 = 0;
    if (input.length() > 1 and ch2 > 9 and ch2 <= 26)
    {
        r2 = allCode(input.substr(2), output + r1);
        for (int j = r1; j < r1 + r2; j++)
        {
            output[j] = char(ch2 + 'a' - 1) + output[j];
        }
    }

    return r1 + r2;
}

int main()
{
    string input;
    cin >> input;

    string output[1000];

    int result = allCode(input, output);

    for (int i = 0; i < result; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}