#include <iostream>
using namespace std;
#include<stack>

int *stockSpan(int *a,int *b, int n){
    stack<int> s;
    s.push(0);
    b[0] = 1;
    for (int i = 1; i < n; i++){
        int t = s.top();
        if(a[i] < a[t]){
            s.push(i);
            b[i] = i - t;
        }
        else{
            while(a[t] < a[i] and s.size() != 1){
            s.pop();
            t = s.top();
            }
            
            if(s.size() == 1 and a[t] < a[i]){
            s.pop();
            s.push(i);
            b[i] = i + 1;
            }

            else{
            s.push(i);
            b[i] = i - t;
            }
        }
    }

    return b;
}


int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int *b = new int[n];
    b = stockSpan(a, b, n);

    for (int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
    cout<< endl;
    delete [] b;
    
return 0;
}