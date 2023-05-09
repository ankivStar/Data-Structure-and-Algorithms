#include <iostream>
using namespace std;

int AllIndexes(int *a, int N, int x, int *output, int *otsize)
{
    if (N == 0)
    {
        return 0;
    }

    else
    {
        int ans = AllIndexes(a, N - 1, x, output, otsize);

        if (a[N - 1] == x)
        {
            output[(*otsize)++] = N - 1;
            return *otsize;
        }

        return ans;
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

    int *outpt = new int[N];
    int outsize = 0;
    int output = AllIndexes(a, N, x, outpt, &outsize);

    // cout << outsize << endl;
    cout << output << endl;
  
    for (int i = 0; i < output; i++)
    {
        cout << outpt[i] << " ";
    }

    delete[] a;
    delete[] outpt;
    return 0;
}