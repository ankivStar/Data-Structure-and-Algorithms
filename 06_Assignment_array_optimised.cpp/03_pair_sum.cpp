#include <iostream>
#include <algorithm>
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

    int count = 0;
    sort(a, a + n);
    for (int i = 0, j = n-1; i < j;)
    {
        if(a[i] + a[j] == k)
        {
            count++;
            i++;
            j--;
        }

        else if(a[i] + a[j] > k)
        {
            j--;
        }
        else{
            i++;
        }
    }

    cout << count << endl;

    delete [] a;
return 0;
}