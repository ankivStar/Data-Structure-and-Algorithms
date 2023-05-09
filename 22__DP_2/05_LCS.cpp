#include <iostream>
using namespace std;

int LCS(string s1, string s2){
    // base case
    if (s1.length() == 0 or s2.length() == 0) return 0;
    
    // recursive calls
    if(s1[0] == s2[0]){ 
        return 1 + LCS(s1.substr(1), s2.substr(1));
    }else{
        int x = LCS(s1.substr(1), s2);
        int y = LCS(s1, s2.substr(1));
        int z = LCS(s1.substr(1), s2.substr(1));

    //small calculation
    int ans = max(x, max(y, z));
    return ans;
    } 
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