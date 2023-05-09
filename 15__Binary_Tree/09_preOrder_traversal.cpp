#include <iostream>
using namespace std;
#include "00__Binary_Tree.h"
#include<queue>
#include "03_input.h"

void preOrder(BinaryTreeNode<int> *root){
    if(!root) return;

    cout << root->data << ",";
    preOrder(root->left);
    preOrder(root->right);
 }

int main(){
    BinaryTreeNode<int> *root = takeInput();
    preOrder(root);
    delete root;
return 0;
}
/*
input
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
output
1,2,4,5,3,6,7,
*/