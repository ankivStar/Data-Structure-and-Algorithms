#include <iostream>
using namespace std;

int minStepsTo1(int n){
    // base casee
    if (n <= 1) return 0;

    // recrsive call
    int x = minStepsTo1(n-1);
    int y = INT_MAX, z = INT_MAX;

    if (n % 2 == 0){
        y = minStepsTo1(n/2);
    }
    if (n % 3 == 0){
        z = minStepsTo1(n/3);
    }

    // final calcualtion
    return 1 + min(x, min(y, z));
}
int main(){
    int n;
    cin >> n;
    cout << minStepsTo1(n) << endl;
    return 0;
}