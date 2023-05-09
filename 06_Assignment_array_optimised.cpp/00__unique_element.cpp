#include <iostream>
using namespace std;

bool uniqueElement(int *input, int size)
{
    int count;
    for (int i = 0; i < size; i++)
    {
        count = 0;
        for (int j = 0; j < size; j++)
        {
            if (input[j] == input[i])
            {
                count++;
            }
        }
        if (count == 1)
        {
            return true;
        }
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