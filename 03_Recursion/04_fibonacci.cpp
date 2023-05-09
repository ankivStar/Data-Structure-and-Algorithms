#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    else{
        int output1 = fibonacci(n-1);
        int output2 = fibonacci(n-2);

        return output1 + output2;
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<fibonacci(n); 
return 0;
}