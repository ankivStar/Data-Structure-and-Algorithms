#include <iostream>
using namespace std;

int helper(int *a, int high, int low, int x)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + ((high - low) / 2);
    if (a[mid] == x)
    {
        return mid;
    }
   else if (a[mid] > x)
    {             
        return helper(a, mid - 1, low, x);
    }
    else
    {
        return helper(a, high, mid + 1, x);
    }
    
}

int binarySearch(int *a, int size, int x)
{
    int low = 0;
    int high = size - 1;
    return helper(a, high, low, x);
}

int main()
{
    int size;
    cin >> size;
    int *a = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> *(a + i);
    }

    int x;
    cin >> x;

    cout << binarySearch(a, size, x) << endl;
    delete[] a;
    return 0;
}