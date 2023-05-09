#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

pair<int, bool> helper(BinaryTreeNode<int> *root){
    if (root == NULL){
        pair<int, bool> p;
        p.first = 0;
        p.second = true;
        return p;
    }
    pair<int, bool> lAns = helper(root->left);
    pair<int, bool> rAns = helper(root->right);

    int lHeight = lAns.first;
    int rHeight = rAns.first;
    int hDiff = abs(lHeight - rHeight);
    
    pair<int, bool> p;
    p.first = 1 + max(lAns.first, rAns.first);

    if (hDiff <= 1 and lAns.second == true and rAns.second == true){
        p.second = true;
    }
    else{
        p.second = false;
    }

    return p;
}

bool isHeightBalanced(BinaryTreeNode<int> *root){
    pair<int, bool> p = helper(root);
    return p.second;
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    if(isHeightBalanced(root)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    delete root;
return 0;
}

/* Time complexity = O(n)

input 
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
output
false

input
1 2 3 -1 -1 -1 -1
output
true
*/