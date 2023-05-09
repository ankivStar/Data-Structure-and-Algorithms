#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

bool findNode(BinaryTreeNode<int>* currNode, BinaryTreeNode<int>* &root, int n){
    if (!root) return false;

    if (root->data == n and root != currNode){
        root->data = INT_MIN;
        return true;
    }
    return findNode(currNode, root->left, n) or findNode(currNode,root->right, n);
}

void printPair(BinaryTreeNode<int>* currNode, int sum, BinaryTreeNode<int>* root){
    if (!currNode) return;

    if (currNode->data != INT_MIN){
        if (findNode(currNode, root, sum-(currNode->data))){
            cout << currNode->data << " " << sum - currNode->data << endl;
        }
    }
    printPair(currNode->left, sum, root);
    printPair(currNode->right, sum, root);
}

void pairSum(BinaryTreeNode<int>* root, int sum){
    printPair(root, sum, root);
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
    return 0;
}

/*
input
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1 
15 
output
5 10
6 9
*/