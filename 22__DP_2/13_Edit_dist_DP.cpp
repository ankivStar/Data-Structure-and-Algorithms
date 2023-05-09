#include <iostream>
using namespace std;

int editDistance(string s1, string s2){
    int m = s1.size();
    int n = s2.size();

    int **output = new int*[m+1];
    for (int i = 0; i < m+1; i++){
       output[i] = new int[n+1];
    }
    
    // fill the first row (left to right)
    for (int i = 0; i < n+1; i++){
        output[0][i] = i;
    }

    // fill the first column (top to bottom)
    for (int i = 0; i < m+1; i++){
        output[i][0] = i;
    }

    // fill remaining cells
    for (int i = 1; i < m+1; i++){
        for (int j = 1; j < n+1; j++){
            int ans;
            if (s1[m-i] == s2[n-j]){
                output[i][j] = output[i-1][j-1];
            }else{
                int insert = 1 + output[i-1][j-1];
                int del = 1 + output[i][j-1];
                int replace = 1 + output[i-1][j];
                
                output[i][j] = min(insert, min(del, replace)); 
            }
        }
    }
    return output[m][n];
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    cout << editDistance(s1, s2) << endl;
    return 0;
}

/*
input
abc
dc

output
2

input
whgtdwhgtdg
aswcfg

output
9
*/