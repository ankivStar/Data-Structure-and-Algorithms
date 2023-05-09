#include <iostream>
using namespace std;

int firstIndex(int *a, int N, int x,int idx)
{
    if (a[idx] == x)
    {
        return idx;
    }
    if (N == idx)
    {
        return -1;
    }
    else
    {
        int smallerOutput = firstIndex(a, N, x, idx+1);
        return smallerOutput;
    }
}


int main()
{
    int N;
    cin >> N;
    int *a = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> *(a + i);
    }

    int x;
    cin >> x;

    cout << firstIndex(a, N, x, 0);

    delete[] a;
    return 0;
}