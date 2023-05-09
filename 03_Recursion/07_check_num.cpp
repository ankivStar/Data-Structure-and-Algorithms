#include <iostream>
using namespace std;

bool checkNum(int *a, int N, int x)
{
    // 1st method
    // if(*(a) == x){
    //     return true;
    // }
    // if(N==1){
    //     return false;
    // }
    // else{
    //     return checkNum(a+1, N-1, x);
    // }

    //2nd method
    if (N == 0)
    {
        return false;
    }
    if (a[0] == x)
    {
        return true;
    }

    else
    {
        bool output = checkNum(a + 1, N - 1, x);
        return output;
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
    if (checkNum(a, N, x))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    delete[] a;
    return 0;
}