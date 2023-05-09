#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"


BinaryTreeNode<int>* helper(BinaryTreeNode<int>* root, int a, int b){
    if (!root) return NULL;

    if (root->data == a or root->data == b) return root;

    BinaryTreeNode<int>* lAns = helper(root->left, a, b);
    BinaryTreeNode<int>* rAns = helper(root->right, a, b);

    if (lAns and rAns) return root;
    else if (!lAns and !rAns) return NULL;
    else if (!lAns) return rAns;
    else return lAns;
}

int LCAOfBST(BinaryTreeNode<int>* root, int a, int b){
    if (!helper) return -1;
    else return helper(root, a, b)->data;
}
int main(){
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << LCAOfBST(root, a, b);
    delete root;
return 0;
}

/*
input
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 10
output
10

input
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 6
output
5
*/