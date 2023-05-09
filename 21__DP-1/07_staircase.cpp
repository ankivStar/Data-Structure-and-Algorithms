#include <iostream>
using namespace std;

// brute force 1
// int totalWays(int n){
//     // base casee
//     if (n <= 1) return 1;

//     // recrsive call
//     int x = totalWays(n-1);
//     int y = 0, z = 0;

//     if (n >= 2){
//         y = totalWays(n-2);
//     }
//     if (n >= 3){
//         z = totalWays(n-3);
//     }

//     // final calcualtion
//     return x + y + z;
// }

// brute force 2
int totalWays(int n){
    if (n == 0) return 1;
    else if (n < 0) return 0;
    else return totalWays(n-1) + totalWays(n-2) + totalWays(n-3);   
}

// using memoization
int totalWays_memoization_helper(int n, int* ans){
    if (n == 0) return 1;
    if (n < 0) return 0;

    if (ans[n] != -1) return ans[n];

    int x = totalWays_memoization_helper(n-1, ans);
    int y = totalWays_memoization_helper(n-2, ans);
    int z = totalWays_memoization_helper(n-3, ans);

    ans[n] = x + y + z;
    return ans[n];
}
int totalWays_memoization(int n){
    int* ans = new int[n+1];
    for (int i = 0; i <= n; i++){
        ans[i] = -1;
    }

    return totalWays_memoization_helper(n, ans);
}

// DP
int totalWays_DP(int n){
    int* ans = new int[n+1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    for (int i = 3; i <= n; i++){
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    }
    return ans[n];
}


int main(){
    int n;
    cin >> n;
    cout << totalWays(n) << endl;
    cout << totalWays_memoization(n) << endl;
    cout << totalWays_DP(n) << endl;
    return 0;
}