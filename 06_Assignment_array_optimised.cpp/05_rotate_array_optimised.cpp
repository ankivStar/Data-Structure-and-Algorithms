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

    int b[k];

    int i = k;
    int j = 0;
    while (i > 0)
    {
        b[j] = a[j];
        j++; 
        i--;
    }

    for (i = 0; i < n - k; i++)
    {
        a[i] = a[i + k];
    }

    for (i = n - k,j = 0; i < n; i++)
    {
        a[i] = b[j++];
    }

    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    delete [] a;
return 0;
}