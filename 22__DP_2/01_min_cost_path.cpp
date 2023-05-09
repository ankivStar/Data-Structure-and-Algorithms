#include <iostream>
using namespace std;

int minCostPath(int m, int n, int **cost, int i, int j){
    // base case
    if (i == m-1 and j == n-1) return cost[i][j];

    if(i >= m or j >= n) return INT_MAX;

    // recursive calls
    int x = minCostPath(m, n, cost, i, j+1);
    int y = minCostPath(m, n, cost,i+1, j+1);
    int z = minCostPath(m, n, cost,i+1,j);

    // small calculation and return statement
    return cost[i][j] + min(x, min(y,z));
}

int minCostPath(int m, int n, int **cost){
    return minCostPath(m, n ,cost, 0 , 0);
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