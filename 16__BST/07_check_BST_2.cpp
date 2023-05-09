#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

class isBSTReturn{
    public :
    bool isBST;
    int min;
    int max;
};

isBSTReturn checkBST(BinaryTreeNode<int> *root){
    if (root == NULL){
        isBSTReturn output;
        output.isBST = true;
        output.min = INT_MAX;
        output.max = INT_MIN;
        return output;
    }

    isBSTReturn lResult = checkBST(root->left);
    isBSTReturn rResult = checkBST(root->right);
    bool finalIsBST = root->data > lResult.max and root->data < rResult.min and lResult.isBST and rResult.isBST;

    isBSTReturn output;
    output.isBST = finalIsBST;
    output.min = min(root->data, min(lResult.min, rResult.min));
    output.max = max(root->data, max(lResult.max, rResult.max));

    return output;
}
int main(){
    BinaryTreeNode<int> *root = takeInput();
    if (checkBST(root).isBST) cout << "true" << endl;
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