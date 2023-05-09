#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

int sumOfNodes(BinaryTreeNode<int> *root){
    if (root == NULL){
        return 0;
    }

    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}


int main(){
    BinaryTreeNode<int> *root = takeInput();
    cout << sumOfNodes(root) << endl;
    delete root;
return 0;
}

/*
input 
2 3 4 6 -1 -1 -1 -1 -1
output
15

input
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
output
28
*/