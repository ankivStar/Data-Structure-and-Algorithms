#include <iostream>
using namespace std;

int sumOfDigit(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        int smallerOutput1 = sumOfDigit(n / 10);
        int smallerOutput2 = sumOfDigit(n % 10);

        return smallerOutput1 + smallerOutput2;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << sumOfDigit(n);
    return 0;
}