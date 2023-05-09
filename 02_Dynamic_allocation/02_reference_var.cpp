#include <iostream>
using namespace std;

void increment(int &n)
{
    n++;
}

int main()
{
    int i = 10;
    int &j = i;

    i++;
    cout << j << endl;

    j++;
    cout << i << endl;

    increment(i);
    cout << j << ", " << i << endl;

    return 0;
}