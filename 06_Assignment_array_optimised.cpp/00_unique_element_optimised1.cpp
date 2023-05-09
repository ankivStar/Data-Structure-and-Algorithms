#include <iostream>
using namespace std;

bool uniqueElement(int *input, int size)
{
    int mxor = 0;
    for( int i = 0 ; i < size; i++)
    {
        mxor ^= input[i];
    }

    //return mxor;

    if(mxor != 0)
    {
        return true;
    }
    return false;
    
}

int main()
{
    int size;
    cin >> size;

    int input[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    //cout << uniqueElement(input, size);

    if (uniqueElement(input, size))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
return 0;
}
