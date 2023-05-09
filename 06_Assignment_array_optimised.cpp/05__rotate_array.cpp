#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int store = a[0];
        for (int j = 0; j < n-1; j++)
        {
            a[j] = a[j + 1];
        }
        a[n-1] =  store;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    delete [] a;
    return 0;
}