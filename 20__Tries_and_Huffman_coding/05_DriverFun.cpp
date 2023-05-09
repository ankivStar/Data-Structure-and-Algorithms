#include <iostream>
using namespace std;
#include "02_Tries_all_fun.h"

int main(){
    Trie t;
    t.inserWord("and");
    t.inserWord("are");
    t.inserWord("dot");
    t.inserWord("dash");

    cout << t.searchWord("and") << endl;
    cout << t.searchWord("de") << endl;

    t.removeWord("and");
    cout << t.searchWord("and") << endl;

    return 0;
}