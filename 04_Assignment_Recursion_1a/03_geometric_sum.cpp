#include <iostream>
#include<math.h>

using namespace std;

double geometricSum(int k)
{
    if(k == 0)
    {
        return 1;
    }
    else{
        double a = geometricSum(k-1);
        double b = 1/(pow(2,k));

        return a + b;
    }
}

int main()
{
   int k;
   cin>> k;
   cout<< geometricSum(k); 
return 0;
}