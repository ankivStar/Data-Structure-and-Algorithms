#include <iostream>
using namespace std;
#include<queue>

int KthLargestElement(int* a, int n, int k){
    priority_queue<int> q;
    for (int i = 0; i < n; i++){
        q.push(a[i]);
    }

    while(k > 1){
        q.pop();
        k--;
    }
    return q.top();
}

int main(){
    
    int size;
    cin >> size;
    int a[size];
    for (int i = 0; i < size; i++){
        cin >> a[i];
    }

    int k;
    cin >> k;
    cout << KthLargestElement(a, size, k) << endl;

    return 0;
}

/*
input
6
9 4 8 7 11 3
2
output
9

input
8
2 6 10 11 13 4 1 20
4
output
10
*/