#include <iostream>
using namespace std;

// Using DP
int minCostPath(int m, int n, int **cost){
    int **output = new int*[m];
    for (int i = 0; i < m; i++){
       output[i] = new int[n];
    }

    // Find the last cell i.e. destination
    output[m-1][n-1] = cost[m-1][n-1];
    
    // fill the last row (right to left)
    for (int j = n-2; j >= 0; j--){
        output[m-1][j] = output[m-1][j+1] + cost[m-1][j];
    }

    // fill the last column (bottom to top)
    for (int j = m-2; j >= 0; j--){
        output[j][n-1] = output[j+1][n-1] + cost[j][n-1];
    }

    // fill remaining cells
    for (int i = m-2; i >= 0; i--){
        for (int j = n-2; j >= 0; j--){
            output[i][j] = min(output[i][j+1], min(output[i+1][j], output[i+1][j+1])) + cost[i][j];
        }
    }
    return output[0][0];
}

int main(){
    int m, n;
    cin >> m >> n;

    int **cost = new int*[m];
    for (int i = 0; i < m; i++){
       cost[i] = new int[n];
       for (int j = 0; j < n; j++){
            cin >> cost[i][j];
        }
    }

    cout << minCostPath(m, n, cost);

    for (int i = 0; i < m; i++){
        delete[] cost[i];
    }
    delete[] cost;

    return 0;
}

/*
input
3 4
3 4 1 2
2 1 8 9
4 7 8 1

output
13

input
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200

output
76

input
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4
9 6 2 -10 7 4 
10 -2 0 5 5 7

output
18
*/