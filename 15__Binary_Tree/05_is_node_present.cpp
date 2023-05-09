#include <iostream>
#include "00__Binary_Tree.h"
#include<queue>
using namespace std;
#include "03_input.h"

bool isNodePresent(BinaryTreeNode<int> *root, int x){
    if(!root) return false;
    
    if(root->data == x) return true;

    return (isNodePresent(root->left, x) or isNodePresent(root->right, x));
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    int x;
    cin >> x;
    cout << isNodePresent(root, x) << endl;
    delete root;
return 0;
}

// input : 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
// input : 7
// output : yes