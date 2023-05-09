#include <iostream>
using namespace std;

bool isSorted(int *a, int s)
{
    if (s == 0 || s == 1)
        return true;
    if (a[0] > a[1])
        return false;
    else
    {
        return isSorted(a + 1, s - 1);
    }
}
int main()
{
    int a[6] = {1, 2, 3, 4, 5, 6};

    if (isSorted(a, 6))
        cout << "sorted";
    else
        cout << "unsorted";
    return 0;
}