#include <iostream>
using namespace std;
#include <vector>

// brute force
int lootHouses(int size, int* money, int i){
    if(i >= size) return 0;

    int x = money[i] + lootHouses(size, money, i+2);
    int y = lootHouses(size, money, i+1);

    return max(x, y);
}

// memoization
int lootHouses_memo_helper(int size, int* money, vector<int> output, int i){
    if(i >= size) return 0;

    if (output[i] != -1){
        return output[i];
    }
    int x = money[i] + lootHouses_memo_helper(size, money,output, i+2);
    int y = lootHouses_memo_helper(size, money,output, i+1);

    output[i] = max(x, y);
    return output[i];
}

int lootHouses_memoization(int size, int* money){
    vector<int> output(size, -1);

    return lootHouses_memo_helper(size, money, output, 0);
}

// DP
int lootHouses_DP(int size, int* money){
    vector<int> output(size);
    output[0] = money[0];
    output[1] = max(money[0], money[1]);

    for (int i = 2; i < size; i++){
        output[i] = max(output[i-1], output[i-2]+money[i]);
    }
    return output[size-1];
} 


int main(){
    int size;
    cin >> size;
    int money[size];

    for (int i = 0; i < size; i++){
        cin >> money[i];
    }

    cout << lootHouses(size, money, 0) << endl;
    cout << lootHouses_memoization(size, money) << endl;
    cout << lootHouses_DP(size, money) << endl;
    return 0;
}

/*
input
6
5 5 10 100 10 5

output
110

input
6
10 2 30 20 3 50

output
90
*/