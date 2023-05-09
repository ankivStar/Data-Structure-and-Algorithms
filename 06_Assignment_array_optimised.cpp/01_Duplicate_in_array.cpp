#include <iostream>
using namespace std;

// Time complexity is O(n).
int main()
{
    int n;
    cin>> n;
    int *a = new int[n];
    for(int i =0; i < n; i++)
    {
        cin>> a[i];
    }

    //This method works only when duplicate element is present at 'last index.'
    int sum = 0;
    for (int i = 0; i < n; i++ )
    {
        sum += a[i];
    }

    for (int i = 0; i < n-1; i++)
    {
        sum -= a[i];
    }

    cout << sum << endl;

    delete [] a;
return 0;
}