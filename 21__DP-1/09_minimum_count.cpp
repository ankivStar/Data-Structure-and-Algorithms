#include <iostream>
using namespace std;
#include<cmath>


// brute force approach
int minCount(int n){

    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    if (n <= 3)
        return n;

    int res = n;   
    
    for (int x = 1; x <= n; x++)
    {
        int temp = x * x;
        if (temp > n)
            break;
        else
            res = min(res, 1 + minCount(n - temp));
    }
    return res; 
}

//memoization

int minCount_memoization_helper(int n, int* ans){
    if (sqrt(n) - floor(sqrt(n)) == 0){
        return 1;
    }
    if (n <= 3){
        return n;
    }

    if(ans[n] != -1){
        return ans[n];
    }

    int res = n;
    for (int x = 1; x <= n; x++)
    {
        int temp = x * x;
        if (temp > n)
            break;
        else
            res = min(res, 1 + minCount_memoization_helper(n - temp, ans));
    }
    ans[n] = res;
    return ans[n]; 
}
int minCount_memoization(int n){
    int* ans = new int[n+1];
    for (int i = 0; i <= n; i++){
        ans[i] = -1;
    }
    return minCount_memoization_helper(n, ans);
}

// using DP
int minCount_DP(int n){
    if (sqrt(n) - floor(sqrt(n)) == 0){
        return 1;
    }
    if (n <= 3){
        return n;
    }

    int* ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;

    for (int i = 4; i <= n; i++)
    {
        ans[i] = i;
 
        // Go through all smaller numbers to recursively find minimum
        for (int x = 1; x <= ceil(sqrt(i)); x++)
        {
            int temp = x * x;
            if (temp > i)
                break;
            else
                ans[i] = min(ans[i], 1 + ans[i - temp]);
        }
    }
 
    // Store result and free ans[]
    int res = ans[n];
    delete[] ans;
 
    return res;
} 

int main(){
    int n;
    cin >> n;
    cout << minCount(n) << endl;
    cout << minCount_memoization(n) << endl;
    cout << minCount_DP(n) << endl;

    cout << sqrt(n) << endl;
    return 0;
}