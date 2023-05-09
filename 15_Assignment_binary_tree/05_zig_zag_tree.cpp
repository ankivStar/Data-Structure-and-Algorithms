#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"
#include <stack>

void zigZagTree(BinaryTreeNode<int> *root){
    if (root == NULL) return;

    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;

    s1.push(root);
    while (!s1.empty() or !s2.empty()){

        while (!s1.empty()){
            BinaryTreeNode<int> *top1 = s1.top();
            s1.pop();

            if (top1->left != NULL) s2.push(top1->left);          
            if (top1->right != NULL) s2.push(top1->right);
            cout << top1->data << " ";
        }
        cout << endl;

        while (!s2.empty()){
            BinaryTreeNode<int> *top2 = s2.top();
            s2.pop();

            if (top2->right != NULL) s1.push(top2->right);
            if (top2->left != NULL) s1.push(top2->left); 
            cout << top2->data << " ";
        }
        cout << endl;
    }
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    zigZagTree(root);
    delete root;
return 0;
}

/*
input
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
output
5
10 6
2 3 
9

input
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
output
8
10 3
1 6 14
13 7 4
*/