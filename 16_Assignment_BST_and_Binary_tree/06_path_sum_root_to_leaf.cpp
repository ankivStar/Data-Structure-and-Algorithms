#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

void printPath(BinaryTreeNode<int>* root, int k, string s){
    if (!root) return;

    s = s + to_string(root->data) + " ";

    if (!root->left and !root->right and root->data - k == 0){
        cout << s << endl;
    }

    printPath(root->left, k - root->data, s);
    printPath(root->right, k - root->data, s);
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    printPath(root, k, "");
    delete root;
    return 0;
}

/*
input
2 3 9 4 8 -1 2 4 -1 -1 -1 6 -1 -1 -1 -1 -1
13
output
2 3 4 4
2 3 8
input
5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
13
output
5 6 2
5 7 1
*/