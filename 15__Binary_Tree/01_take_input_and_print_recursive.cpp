#include <iostream>
#include "00__Binary_Tree.h"
using namespace std;

void print(BinaryTreeNode<int> *root){
    if (!root) return;

    cout << root->data << " : ";
    if (root->left){
        cout << "L" << root->left->data;
    }

    if(root->right){
        cout << "R" << root->right->data;
    }
    cout << endl;
    print(root->left);
    print(root->right);
}

BinaryTreeNode<int> *takeInput(){
    int rootData;
    cout << "Enter data " << endl;
    cin >> rootData;
    if (rootData == -1)
    return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;

    return root;
}

int main(){
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;
    // print(root);

    BinaryTreeNode<int> *root = takeInput();
    print(root);
    delete root;
return 0;
}