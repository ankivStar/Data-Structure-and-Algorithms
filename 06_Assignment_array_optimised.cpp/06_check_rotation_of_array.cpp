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

    int count = 0;
    int d = a[n - 1];
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= d)
        {
            count = i;
            break;
        }
    }

    cout << count << endl;
    return 0;
}