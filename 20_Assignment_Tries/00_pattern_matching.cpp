#include <iostream>
using namespace std;
#include "_SuffixTrie.h"

int main(){
    int n;
    cin >> n;
    string str[n];
    for (int i = 0; i < n; i++){
        cin >> str[i];
    }

    string patt;
    cin >> patt;

    Trie t;
    for (int i = 0; i < n; i++){
        int l = str[i].length();
        int j = 0;
        while(j < l){
            t.inserWord(str[i].substr(j));
            j++;
        }
    }

    if (t.searchWord(patt)){ 
        cout << "true" << endl;
    }else{ 
        cout << "false" << endl;
    }
    return 0;
}

/*
input
4
abc def ghi cba
de
output
true

input
4
abc def ghi hg
hi
output
true

input
4
abc def ghi cba
hif
output
false
*/