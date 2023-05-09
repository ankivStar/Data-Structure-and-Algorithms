#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"
#include "..\15_Assignment_binary_tree\02_levelOrderTraversal.h"

void replace(BinaryTreeNode<int>* root, int &sum){
    if(!root) return;

    replace(root->right, sum);
    sum = sum + root->data;
    root->data = sum;
    replace(root->left, sum);
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    int sum = 0;
    replace(root, sum);
    levelOrderTraversal(root);
    delete root;
    return 0;
}

/*
input 
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
output
18
36 10
38 31
25

input
8 7 9 -1 -1 -1 -1
output
17
24 9
*/