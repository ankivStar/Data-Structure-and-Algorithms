#include <iostream>
using namespace std;

void printSubset(int *input, int size, int *output,int pos)
{
    if(size == 0)
    {
        for (int i = 0; i < pos; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }

    printSubset(input + 1,size-1,output, pos);

    output[pos] = input[0];
    
    printSubset(input + 1, size-1, output,pos+1);
    
}

int main()
{
    int size;
    cin>> size;
    int *input = new int[size];
    for(int i =0; i < size; i++)
    {
        cin>> input[i];
    }

    int *output = new int[size];

    printSubset(input,size,output,0);

    delete [] input;
    delete [] output;
return 0;
}