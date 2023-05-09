#include <iostream>
using namespace std;

int minStepsTo1(int n){
    int* ans = new int[n+1];

    ans[0] = 0;
    ans[1] = 0;

    
    for (int i = 2; i <= n; i++){
        int x, y = INT_MAX, z = INT_MAX;
        x = ans[i-1];

        if(i%2 == 0){
            y = ans[i/2];
        }
        if(i%3 == 0){
            z = ans[i/3];
        }

        ans[i] = min(x, min(y, z)) + 1; 
        // cout << ans[i] << " " << x << " " << y << " " << z << endl;
    }
    return ans[n];
}

int main(){
    int n;
    cin >> n;
    cout << minStepsTo1(n) << endl;
    return 0;
}