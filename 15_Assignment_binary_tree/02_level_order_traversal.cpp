#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

void levelOrderTraversal(BinaryTreeNode<int> *root){
    if (root == NULL) return;

    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    q.push(NULL);

    while (q.size() != 0){
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        if (front != NULL){
            cout << front->data << " ";
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
        }
        if(front == NULL){
            if (q.empty()) break;
            cout << endl;
            q.push(NULL);
        } 
    }    
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    levelOrderTraversal(root);
    delete root;
    return 0;
}

/*
input
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
output
10
20 30
40 50 60 

input
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
output
8
3 10
1 6 14
4 7 13
*/