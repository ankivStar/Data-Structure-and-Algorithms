#include <iostream>
using namespace std;

// using DP
int LCS(string s1, string s2){
    int m = s1.size();
    int n = s2.size();

    int **output = new int*[m+1];
    for (int i = 0; i < m+1; i++){
       output[i] = new int[n+1];
    }

    // filling up the first row (left to right)
    for (int i = 0; i < n+1; i++){
        output[0][i] = 0;
    }

    // filling up the first column (top to bottom)
    for (int i = 0; i < m+1; i++){
        output[i][0] = 0;
    }

    // fill the remaining cells
    for (int i = 1; i < m+1; i++){
        for (int j = 1; j < n+1; j++){
            // check if first character matches
            if(s1[m-i] == s2[n-j]){ 
                output[i][j] = 1 + output[i-1][j-1];
            }else{ 
                int x = output[i-1][j];
                int y = output[i][j-1];
                int z = output[i-1][j-1];
                output[i][j] = max(x, max(y, z));
            } 
        }
    }
    return output[m][n];
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    cout << LCS(s1, s2) << endl;
    return 0;
}

/*
input
xyz 
zxay

output
2

input
abcd 
badeab

output
2

input
abcde
cadbe

output
3
*/