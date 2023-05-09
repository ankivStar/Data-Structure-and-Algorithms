#include <iostream>
#include "00__Binary_Tree.h"
#include<queue>
using namespace std;
#include "03_input.h"

int numOfNodes(BinaryTreeNode<int> *root){
    if(!root) return 0;
    return 1 + numOfNodes(root->left) + numOfNodes(root->right);
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    cout << numOfNodes(root) << endl;
    delete root;
return 0;
}

// input : 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
// output : 9