#include <iostream>
using namespace std;

int knapsack(int *w, int* v, int capacity, int size, int** output){
    // base case
    if (size == 0 or capacity == 0) return 0;

    // checking if ans is already present
    if(output[size][capacity] != -1){
        return output[size][capacity];
    }

    // recursive calls
    int ans;
    if(w[0] > capacity){
        ans = knapsack(w+1, v+1, capacity, size-1, output);
    }else{
        int x = v[0] + knapsack(w+1, v+1, capacity-w[0], size-1, output);
        int y = knapsack(w+1, v+1, capacity, size-1, output);
        ans = max(x, y);
    }

    // saving ans for future use
    output[size][capacity] = ans;
    return ans;
}

int knapsack(int* w, int* v, int capacity, int size){
    int **output = new int*[size+1];
    for (int i = 0; i < size+1; i++){
        output[i] = new int[capacity+1];
    }

    for (int  i = 0; i < size+1; i++){
        for (int j = 0; j < capacity+1; j++){
            output[i][j] = -1;
        }
    }

    return knapsack(w, v, capacity, size, output);
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