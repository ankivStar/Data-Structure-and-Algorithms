#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"

void inputArray(int a[], int size){
    for (int i = 0; i < size; i++){
        cin >> a[i];
    }
}

void preOrderTraversal(BinaryTreeNode<int> *root){
    if (root == NULL) return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

BinaryTreeNode<int> *constructBST(int a[], int size){
    if (size == 0) return NULL;

    int mid = size / 2;
    BinaryTreeNode<int> *root;
    
    if (size % 2 != 0){
    root = new BinaryTreeNode<int>(a[mid]);
    root->left = constructBST(a, mid);
    root->right = constructBST(a+mid+1, mid);
    }
    else{
        root = new BinaryTreeNode<int>(a[mid-1]);
        root->left = constructBST(a, mid-1);
        root->right = constructBST(a+mid, mid);
    }
    return root;
}

int main(){
    int size;
    cin >> size;
    int a[size];
    inputArray(a, size);
    preOrderTraversal(constructBST(a, size));
    return 0;
}

/*
input 
7
1 2 3 4 5 6 7

output
4 2 1 3 6 5 7

input 
8
1 2 3 4 5 6 7 8

output
4 2 1 3 6 5 7 8
*/