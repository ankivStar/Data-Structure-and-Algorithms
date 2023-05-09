#include <iostream>
using namespace std;

int minStepsTo1_helper(int n, int* ans){
    if (n <= 1){
        return 0;
    }

    if (ans[n] != -1){
        return ans[n];
    }

    int x = minStepsTo1_helper(n-1, ans);
    int y = INT_MAX, z = INT_MAX;

    if (n % 2 == 0){
        y = minStepsTo1_helper(n/2, ans);
    }
    if (n % 3 == 0){
        z = minStepsTo1_helper(n/3, ans);
    }

    ans[n] = min(x, min(y, z)) + 1;

    return ans[n];
}

int minStepsTo1(int n){
    int* ans = new int[n+1];
    for (int i = 0; i <= n; i++){
        ans[i] = -1;
    }
    return minStepsTo1_helper(n, ans);
}

int main(){
    int n;
    cin >> n;
    cout << minStepsTo1(n) << endl;
    return 0;
}