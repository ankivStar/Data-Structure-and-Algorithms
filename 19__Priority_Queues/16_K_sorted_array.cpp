#include <iostream>
using namespace std;
#include<queue>

void kSortedArray(int input[], int n, int k){
    priority_queue<int> pq;
    for (int i = 0; i < k; i++){
        pq.push(input[i]);
    }

    int j = 0;
    for (int i = k; i < n; i++){
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }

    while (!pq.empty()){
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}

int main(){
    int size, k;
    cin >> size >> k;
    int input[size];

    for (int i = 0; i < size; i++){
        cin >> input[i];
    }

    kSortedArray(input, size, k);
    for (int i = 0; i < size; i++){
        cout << input[i] << " ";
    }
    return 0;
}

/*
input
7 3 
6 5 3 2 8 10 9
output
6 5 8 10 9 3 2
*/