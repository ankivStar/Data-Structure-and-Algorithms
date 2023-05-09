#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//time complexity O(n * log n)
int main()
{
    int n;
    cin>> n;
    int *a = new int[n];
    for(int i =0; i < n; i++)
    {
        cin>> a[i];
    }

    sort(a, a + n);

    for (int i =0; i < n; i++)
    {
        if(a[i] == a[i+1])
        {
            cout << a[i] << endl;
        }
    }

    delete [] a;

return 0;
}