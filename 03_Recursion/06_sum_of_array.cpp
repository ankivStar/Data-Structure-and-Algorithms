#include <iostream>
using namespace std;
 int sumOfArray(int *a, int n)
 {
    if(n==1){
        return *a;
    }
    else{
        int smallerOutput1 = *a;
        int smallerOutput2 = sumOfArray(a+1,n-1);
        return  smallerOutput1 + smallerOutput2;
    }
 }
int main()
{
    int n;
    cin>> n;
    int *a = new int[n];
     for(int i = 0; i< n;i++)
     {
        cin>> *(a+i);
     }

     cout<<sumOfArray(a,n);

     delete [] a;
return 0;
}