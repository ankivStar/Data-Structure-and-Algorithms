#include <iostream>
#include "00__Binary_Tree.h"
#include<queue>
using namespace std;

BinaryTreeNode<int> *takeInputLevelWise(){
    int rootData;
    cout << "Enter root Data" << endl;
    cin >> rootData;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0){
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        cout << "Enter left child data of " << front->data << endl;
        cin >> leftChildData;

        if(leftChildData != -1){
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            pendingNodes.push(leftChild);
            front->left = leftChild;
        }

        int rightChildData;
        cout << "Enter right child data of " << front->data << endl;
        cin >> rightChildData;

        if(rightChildData != -1){
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            pendingNodes.push(rightChild);
            front->right = rightChild;
        }
    }
    return root;
}

void print(BinaryTreeNode<int> *root){
    if (!root) return;

    cout << root->data << " : ";
    if(root->left){
        cout << "L" << root->left->data;
    } 

    if(root->right){
        cout << "R" << root->right->data;
    }
    cout << endl;
    print(root->left);
    print(root->right); 
}

int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    print(root);
    delete root;
return 0;
}