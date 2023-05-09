#include <iostream>
using namespace std;

int LCS(string s1, string s2, int** output){
    int m = s1.size();
    int n = s2.size();
    // base case
    if (s1.length() == 0 or s2.length() == 0) return 0;

    //checking is ans already exists
    if(output[m][n] != -1){
        return output[m][n];
    }
    
    // recursive calls
    int ans;
    if(s1[0] == s2[0]){ 
        ans = 1 + LCS(s1.substr(1), s2.substr(1), output);
    }else{ 
        int x = LCS(s1.substr(1), s2, output);
        int y = LCS(s1, s2.substr(1), output);
        int z = LCS(s1.substr(1), s2.substr(1), output);

        //small calculation
        ans = max(x, max(y, z));
    } 
    output[m][n] = ans;
    return ans;
}

int LCS(string s1, string s2){
    int m = s1.size();
    int n = s2.size();

    int **output = new int*[m+1];
    for (int i = 0; i < m+1; i++){
       output[i] = new int[n+1];
       for (int j = 0; j < n+1; j++){
            output[i][j] = -1;
        }
    }

    return LCS(s1, s2, output);
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