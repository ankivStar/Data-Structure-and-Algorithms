#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

int leftMaximum(BinaryTreeNode<int> *root){
    if (root == NULL) return INT_MIN;

    int lMax = leftMaximum(root->left);
    int rMax = leftMaximum(root->right);
    return max(root->data, max(lMax, rMax));
}

int rightMinimum(BinaryTreeNode<int> *root){
    if (root == NULL) return INT_MAX;

    int lMin = rightMinimum(root->left);
    int rMin = rightMinimum(root->right);
    return min(root->data, min(lMin, rMin));
}

bool checkBST(BinaryTreeNode<int> *root){
    if (root == NULL) return true;

    int lMax = leftMaximum(root->left);
    int rMin = rightMinimum(root->right);

    bool lResult = checkBST(root->left);
    bool rResult = checkBST(root->right);
    
    return root->data > lMax and root->data <= rMin and lResult and rResult;
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    if (checkBST(root)) cout << "true" << endl;
    else cout << "false" << endl;
    delete root;
    return 0;
}

/*
input 
3 1 5 -1 2 -1 -1 -1 -1
output
true

input
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
output
false
*/