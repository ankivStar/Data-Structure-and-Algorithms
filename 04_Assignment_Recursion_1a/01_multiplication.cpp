#include <iostream>
using namespace std;

int multiplication(int m, int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        int smalleroutput = multiplication(m, n - 1);
        return m + smalleroutput;
    }
}

int main()
{
    int m, n;
    cin >> m;
    cin >> n;
    cout << multiplication(m, n);
    return 0;
}