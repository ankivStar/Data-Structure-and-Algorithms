#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

class largestBST{
    public :
    int min;
    int max;
    bool isBST;
    int height;
};

largestBST helper(BinaryTreeNode<int>* root){
    if (!root){
        largestBST l;
        l.min = INT_MAX;
        l.max = INT_MIN;
        l.isBST = true;
        l.height = 0;
        return l;
    }

    largestBST lAns = helper(root->left);
    largestBST rAns = helper(root->right);

    largestBST finalAns;
    if (root->data > lAns.max and root->data < rAns.min and lAns.isBST and rAns.isBST){
        finalAns.min = min(root->data, lAns.min);
        finalAns.max = max(root->data, rAns.max);
        finalAns.isBST = true;
        finalAns.height = max(lAns.height, rAns.height) + 1;
    }
    else{
        finalAns.min = min(root->data, min(lAns.min, rAns.min));
        finalAns.max = max(root->data, max(lAns.max, rAns.max));
        finalAns.isBST = false;
        finalAns.height = max(lAns.height, rAns.height); 
    }
    return finalAns;
}

int heightOfLargestBST(BinaryTreeNode<int>* root){
    return helper(root).height;
}
int main(){
    BinaryTreeNode<int>* root = takeInput();
    cout << heightOfLargestBST(root) << endl;
    delete root;
    return 0;
}

/*
input
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
output
2
*/