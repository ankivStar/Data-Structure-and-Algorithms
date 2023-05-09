#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"
#include "..\15__Binary_Tree\03_traverse.h"

BinaryTreeNode<int>* insertDuplicate(BinaryTreeNode<int>* root){
    if (root == nullptr){
        return nullptr;
    }

    BinaryTreeNode<int>* temp = root->left;
    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(root->data);

    root->left = newNode;
    newNode->left = insertDuplicate(temp);
    root->right = insertDuplicate(root->right);

    return root;
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    traverse(insertDuplicate(root));
    delete root; 
    return 0;
}

/*
input 
10 7 15 2 8 12 25 -1 -1 -1 -1 -1 -1 -1 -1
output
10 : L10R15
10 : L7
15 : L15R25
7 : L7R8
15 : L12
25 : L25
7 : L2
8 : L8
12 : L12
25 :
2 : L2
8 :
12 :
2 :
*/