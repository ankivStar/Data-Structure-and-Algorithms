#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

bool checkBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX){
    if (root == NULL) return true;

    if (root->data < min or root->data > max) return false;

    bool isLeftOk = checkBST(root->left, min, root->data - 1);
    bool isRightOk = checkBST(root->right, root->data, max);

    return isLeftOk and isRightOk;
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