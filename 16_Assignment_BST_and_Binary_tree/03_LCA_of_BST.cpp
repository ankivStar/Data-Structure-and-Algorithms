#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

BinaryTreeNode<int>* helper(BinaryTreeNode<int>* root, int a, int b){
    if (!root) return NULL;

    if (root->data > a and root->data > b) return helper(root->left, a, b);
    if (root->data < a and root->data < b) return helper(root->right, a, b);
    return root;
}

int LCAOfBST(BinaryTreeNode<int>* root, int a, int b){
    if (!helper(root, a, b)) return -1;
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
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 10
output
8

input
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 6
output
5

input
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12 78
output
-1
*/