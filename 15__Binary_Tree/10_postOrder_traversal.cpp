#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#include "00__Binary_Tree.h"
#include<queue>
#include "03_input.h"

void postOrder(BinaryTreeNode<int> *root){
    if(!root) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ",";
 }

int main(){
    BinaryTreeNode<int> *root = takeInput();
    postOrder(root);
    delete root;
return 0;
}
/*
input
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
output
4,5,2,6,7,3,1,
*/