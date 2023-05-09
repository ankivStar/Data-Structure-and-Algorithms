#include <iostream>
using namespace std;

int firstIndex(int *a, int N, int x)
{
    if (N == 0)
    {
        return -1;
    }
    if (a[0] == x)
    {
        return 0;
    }
    else
    {
        int smallerOutput = firstIndex(a + 1, N - 1, x);

        if (smallerOutput == -1)
        {
            return smallerOutput;
        }
        else
        {
            return 1 + smallerOutput;
        }
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

    cout << firstIndex(a, N, x);

    delete[] a;
    return 0;
}