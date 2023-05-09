#include <iostream>
#include "00__Binary_Tree.h"
#include<queue>
using namespace std;

BinaryTreeNode<int> *takeInputLevelWise(){
    int rootData;
    cin >> rootData;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0){
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        cin >> leftChildData;

        if(leftChildData != -1){
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            pendingNodes.push(leftChild);
            front->left = leftChild;
        }

        int rightChildData;
        cin >> rightChildData;

        if(rightChildData != -1){
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            pendingNodes.push(rightChild);
            front->right = rightChild;
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int> *root){
    if (!root) return;

    queue<BinaryTreeNode<int> *> printingNodes;
    printingNodes.push(root);

    while (printingNodes.size() != 0){
        BinaryTreeNode<int> *front = printingNodes.front();
        printingNodes.pop();

        cout << front->data << " : ";

        if(front->left){
            cout << "L" << front->left->data;
            printingNodes.push(front->left); 
        }

        if(front->right){
            cout << "R" << front->right->data;
            printingNodes.push(front->right); 
        }
        cout << endl;
    }
}

int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    delete root;
return 0;
}

// input : 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1