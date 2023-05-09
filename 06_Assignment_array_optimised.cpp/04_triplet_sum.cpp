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

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int l = j + 1; l < n; l++)
            {
                if(a[i] + a[j] + a[l] == k)
                {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
    delete [] a;
return 0;
}