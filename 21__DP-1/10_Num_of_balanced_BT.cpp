#include <iostream>
using namespace std;

int countBalancedBT(int h){
    if(h <= 1) return 1;

    int x = countBalancedBT(h-1);
    int y = countBalancedBT(h-2);

    return ((x*x) + (x*y) + (y*x));
}

// memoization
int countBalancedBT_helper(int h, int* ans){
    if(h <= 1) return 1;

    if(ans[h] != -1) return ans[h];

    int x = countBalancedBT_helper(h-1, ans);
    int y = countBalancedBT_helper(h-2, ans);

    ans[h] = ((x*x) + (x*y) + (y*x));
    return ans[h];
}

int countBalBT_memo(int h){
    int* ans = new int[h+1];
    for (int i = 0; i <= h; i++){
        ans[i] = -1;
    }
    return countBalancedBT_helper(h, ans);
}

// DP
int countBalBT_DP(int h){
    int* ans = new int[h+1];

    ans[0] = 1;
    ans[1] = 1;

    for (int i = 2; i <= h; i++){
        int x = ans[i-1];
        int y = ans[i-2];
        ans[i] = ((x*x) + (x*y) + (y*x));
    }
    return ans[h];
}

int main(){
    int height;
    cin >> height;

    cout  << countBalancedBT(height) << endl;
    cout  << countBalBT_memo(height) << endl;
    cout  << countBalBT_DP(height) << endl;
    return 0;
}

/*
input
3
output
15

input
4
output
315
*/