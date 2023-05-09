#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

void nodesWithoutSibling(BinaryTreeNode<int> *root){
    if (root == NULL) return;

    if (root->left == NULL and root ->right != NULL)
    cout << root->right->data << " ";

    if (root->left != NULL and root->right == NULL)
    cout << root->left->data << " ";

    nodesWithoutSibling(root->left);
    nodesWithoutSibling(root->right);
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    nodesWithoutSibling(root);
    delete root;
    return 0;
}

/*
input
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
output
9

input
2 4 5 6 -1 -1 7 20 30 80 90 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1 -1
output
6 8 9 7
*/