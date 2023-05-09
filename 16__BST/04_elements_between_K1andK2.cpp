#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

void elementsBetweenK1andK2(BinaryTreeNode<int> *root, int k1, int k2){
    if(root == NULL) return;

    if (root->data > k1) elementsBetweenK1andK2(root->left, k1, k2);
    if (root->data >= k1 and root->data <= k2) cout << root->data << " ";
    if (root->data < k2) elementsBetweenK1andK2(root->right, k1, k2);

}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    int k1, k2;
    cin >> k1 >> k2;
    elementsBetweenK1andK2(root, k1, k2);
    delete root;
return 0;
}

/*
input 
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
6 10
output
6 7 8 10

input
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 7
output
2 5 6 7
*/