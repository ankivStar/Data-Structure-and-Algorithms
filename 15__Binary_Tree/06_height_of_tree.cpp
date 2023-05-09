#include <iostream>
#include "00__Binary_Tree.h"
#include<queue>
using namespace std;
#include "03_input.h"

int heightOfTree(BinaryTreeNode<int> *root){
    if(!root) return 0;

    int leftChildHeight = heightOfTree(root->left);
    int rightChildHeight = heightOfTree(root->right);

    if (leftChildHeight > rightChildHeight) return 1 + leftChildHeight;
    else return 1 + rightChildHeight;
    
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    cout << heightOfTree(root) << endl;
    delete root;
return 0;
}

// input : 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
// output : 4
// input : 10 20 30 40 50 -1 -1 -1 -1 -1 -1
// output : 3