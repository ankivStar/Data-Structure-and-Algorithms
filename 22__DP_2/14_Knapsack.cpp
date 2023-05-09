#include <iostream>
using namespace std;

int knapsack(int *w, int* v, int capacity, int size){
    // base case
    if (size == 0 or capacity == 0) return 0;

    if(w[0] > capacity){
        return knapsack(w+1, v+1, capacity, size-1);
    }
    
    // recursive calls
    int x = v[0] + knapsack(w+1, v+1, capacity-w[0], size-1);
    int y = knapsack(w+1, v+1, capacity, size-1);

    return max(x, y);
}

int main(){
    int size;
    cin >> size;

    int w[size];
    int v[size];

    for (int i = 0; i < size; i++){
        cin >> w[i];
    }

    for (int i = 0; i < size; i++){
        cin >> v[i];
    }

    int capacity;
    cin >> capacity;

    cout << knapsack(w, v, capacity, size) << endl;
    return 0;
}

/*
input
4
1 2 4 5
5 4 8 6
5

output
13

input
5
12 7 11 8 9
24 13 23 15 16
26

output
51
*/