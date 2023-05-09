#include <iostream>
using namespace std;

int knapsack(int* weight, int* values, int capacity, int size){
    int **output = new int*[size+1];
    for (int i = 0; i < size+1; i++){
        output[i] = new int[capacity+1];
    }

    // fill the first row when item/size = 0;
    for (int i = 0; i < capacity+1; i++){
        output[0][i] = 0;
    }

    // fill the first column when capacity = 0;
    for (int i = 0; i < size+1; i++){
        output[i][0] = 0;
    }

    // fill the remaining cells
    for (int i = 1; i < size+1; i++){
        for (int j = 1; j < capacity+1; j++){
            int ans;
            if (weight[i-1] > j){
                output[i][j] = output[i-1][j];
            }else{
                int x = output[i-1][j];
                int y = output[i-1][j-weight[i-1]] + values[i-1];
                output[i][j] = max(x, y);
            }
        }
    }
    return output[size][capacity];
}

int main(){
    int size;
    cin >> size;

    int weight[size];
    int values[size];

    for (int i = 0; i < size; i++){
        cin >> weight[i];
    }

    for (int i = 0; i < size; i++){
        cin >> values[i];
    }

    int capacity;
    cin >> capacity;

    cout << knapsack(weight, values, capacity, size) << endl;
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