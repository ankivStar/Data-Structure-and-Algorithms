#include <iostream>
using namespace std;

void printNum(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        printNum(n - 1);
        cout << n << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    printNum(n);
    return 0;
}