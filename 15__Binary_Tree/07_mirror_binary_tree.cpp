#include <iostream>
using namespace std;
#include "00__Binary_Tree.h"
#include<queue>
#include "03_input.h"
#include "03_traverse.h"

BinaryTreeNode<int> *mirrorBinaryTree(BinaryTreeNode<int> *root){
    if(!root) return root;

    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;

    BinaryTreeNode<int> *leftChild = mirrorBinaryTree(root->left);
    BinaryTreeNode<int> *rightChild = mirrorBinaryTree(root->right);

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    traverse(mirrorBinaryTree(root));
return 0;
}

/*
input
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
output
1 : L3R2
3 : L7R6
2 : L5R4
7 :     
6 :     
5 :     
4 :
*/