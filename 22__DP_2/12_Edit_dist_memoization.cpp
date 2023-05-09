#include <iostream>
using namespace std;

int editDistance(string s1, string s2, int** output){
    int m = s1.size();;
    int n = s2.size();
    if (s1.size() == 0 or s2.size() == 0){
        return max(s1.size(), s2.size());
    }

    // check if ans is already present
    if (output[m][n] != -1){
        return output[m][n];
    }

    // recursive calls
    int ans;
    if(s1[0] == s2[0]){
        ans = editDistance(s1.substr(1), s2.substr(1), output);
    }else{
        int insert = 1 + editDistance(s1.substr(1), s2, output);
        int del = 1 + editDistance(s1, s2.substr(1), output);
        int replace = 1 + editDistance(s1.substr(1), s2.substr(1), output);
        
        ans = min(insert, min(del, replace));
    }
    output[m][n] = ans;
    return ans;
}

int editDistance(string s1, string s2){
    int m = s1.size();
    int n = s2.size();

    int **output = new int*[m+1];
    for (int i = 0; i < m+1; i++){
       output[i] = new int[n+1];
       for (int j = 0; j < n+1; j++){
            output[i][j] = -1;
        }
    }
    return editDistance(s1, s2, output);
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