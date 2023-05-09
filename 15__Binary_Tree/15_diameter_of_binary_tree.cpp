#include <iostream>
using namespace std;
#include "00__Binary_Tree.h"
#include<queue>
#include "03_input.h"

int height(BinaryTreeNode<int> *root){
    if (root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int> *root){
    if (root == NULL) {
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    cout << "Diameter = " << diameter(root) << endl;
    delete root;
return 0;
}

/*
input 
10 20 30 40 50 -1 -1 -1 -1 -1 -1
output
3
*/