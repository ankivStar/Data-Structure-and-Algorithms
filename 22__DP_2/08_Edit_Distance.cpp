#include <iostream>
using namespace std;

int editDistance(string s1, string s2){
    if (s1.size() == 0 or s2.size() == 0){
        return max(s1.size(), s2.size());
    }

    if(s1[0] == s2[0]){
        return editDistance(s1.substr(1), s2.substr(1));
    }else{
        int insert = 1 + editDistance(s1.substr(1), s2);
        int del = 1 + editDistance(s1, s2.substr(1));
        int replace = 1 + editDistance(s1.substr(1), s2.substr(1));
        
        return min(insert, min(del, replace));
    }
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