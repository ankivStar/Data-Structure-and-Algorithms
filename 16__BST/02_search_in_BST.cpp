#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

bool searchInBST(BinaryTreeNode<int> *root, int n){
    if (root == NULL) return false;

    if (root->data == n){
        return true;
    }
    else if (root->data > n){
        return searchInBST(root->left, n);
    }
    else {
        return searchInBST(root->right, n);
    }
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    int n;
    cin >> n;
    if (searchInBST(root,n)) cout << "true" << endl;
    else cout << "false" << endl;
return 0;
}

/*
input 
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
output
true

input
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
output
false
*/