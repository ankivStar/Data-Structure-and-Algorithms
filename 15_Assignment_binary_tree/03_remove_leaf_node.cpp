#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"
#include "02_levelOrderTraversal.h"

BinaryTreeNode<int> *removeLeafNode(BinaryTreeNode<int> *root){
    if (root == NULL)
        return root;

    if (root->left != NULL or root->right != NULL){
        root->left = removeLeafNode(root->left);
        root->right = removeLeafNode(root->right);
        return root;
    }
    else{
        delete root->left;
        delete root->right;
        root = NULL;
        return root;
    }
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    levelOrderTraversal(removeLeafNode(root));
    delete root;
    return 0;
}

/*
input
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
output
10
20 30

input
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
output
8
3 10
6 14

*/