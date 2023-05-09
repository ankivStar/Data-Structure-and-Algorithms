#include <iostream>
using namespace std;

int numOfDigit(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return 1 + numOfDigit(n / 10);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << numOfDigit(n);
    return 0;
}