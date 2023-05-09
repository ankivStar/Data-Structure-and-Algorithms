#include <iostream>
using namespace std;

// brute force approach
int fibo(int n){
    if(n <= 1){
        return n;
    }
    int a = fibo(n-1);
    int b = fibo(n-2);
    return a + b;
}

// memoization
int fibo_helper(int n, int* ans){
    if (n <= 1){
        return n;
    }

    //check if output already exits
    if (ans[n] != -1){
        return ans[n];
    }

    int a = fibo_helper(n-1, ans);
    int b = fibo_helper(n-2, ans);

    //save the output for future use
    ans[n] = a + b;

    // return the final ans
    return ans[n];
}

int fibo_2(int n){
    int* ans = new int[n+1];
    for (int i = 0; i <= n; i++){
        ans[i] = -1;
    }
    return fibo_helper(n, ans);
}


int main(){
    int n;
    cin >> n;
    cout << fibo_2(n) << endl;
    return 0;
}