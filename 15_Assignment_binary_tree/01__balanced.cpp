#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

int height(BinaryTreeNode<int> *root){
    if (root == NULL) return 0;

    return 1 + max(height(root->left), height(root->right));
}

bool isHeightBalanced(BinaryTreeNode<int> *root){
    if (root == NULL){
        return true;
    }

    int diff = abs(height(root->left) - height(root->right));
    if (diff <= 1){
        return isHeightBalanced(root->left) and isHeightBalanced(root->right);
    }
    else{
        return false;
    }
}


int main(){
    BinaryTreeNode<int> *root = takeInput();
    if(isHeightBalanced(root)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    delete root;
return 0;
}


/* Time complexity = O(n*h)

input 
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
output
false

input
1 2 3 -1 -1 -1 -1
output
true
*/