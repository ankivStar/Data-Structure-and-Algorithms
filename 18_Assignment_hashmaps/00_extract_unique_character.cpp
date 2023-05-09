#include <iostream>
using namespace std;
#include<unordered_map>
#include<map>

string extractUniqueCharacter(string s){
    // unordered_map<char, int> unique;
    map<char, int> unique;
    for (int i = 0; i < s.length(); i++)
        unique[s[i]]++;

    string newS="";
    // for (auto i = unique.begin(); i != unique.end(); i++){
    //     newS += i->first;
    // }

    for (auto i : unique){
        newS += i.first;
    }
    return newS;
}
int main(){
    string s;
    cin >> s;
    cout << extractUniqueCharacter(s) << endl;
    return 0;
}

/*
input 
ababacd
output
abcd

input
abcde
output
abcde
*/