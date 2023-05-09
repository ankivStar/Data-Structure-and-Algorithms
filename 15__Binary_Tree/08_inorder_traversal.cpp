#include <iostream>
using namespace std;
#include "00__Binary_Tree.h"
#include<queue>
#include "03_input.h"

void inOrder(BinaryTreeNode<int> *root){
    if(!root) return;

    inOrder(root->left);
    cout << root->data << ",";
    inOrder(root->right);
 }

int main(){
    BinaryTreeNode<int> *root = takeInput();
    inOrder(root);
    delete root;
return 0;
}
/*
input
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
output
4,2,5,1,6,3,7,
*/