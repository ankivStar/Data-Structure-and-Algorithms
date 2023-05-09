#include <iostream>
using namespace std;

int lastIndex(int *a, int N, int x,int idx)
{
    if (a[idx] == x)
    {
        return idx;
    }
    if (idx < 0)
    {
        return -1;
    }
    else
    {
        int smallerOutput = lastIndex(a, N, x, idx-1);
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

    cout << lastIndex(a, N, x, N-1);

    delete[] a;
    return 0;
}