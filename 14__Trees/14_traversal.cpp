#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include "02__Tree_Node.h"

TreeNode<int> *takeInput(){
    int rootData;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> nodesPending;
    nodesPending.push(root);

    while (nodesPending.size() != 0){
        TreeNode<int> *front = nodesPending.front();
        nodesPending.pop();

        int childNum;
        cin >> childNum;
        for (int i = 0; i < childNum; i++){
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            nodesPending.push(child);
        }
    }
    return root;
}

void preOrderTraversal(TreeNode<int> *root){
    if (root == NULL) return;
    
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++){
        preOrderTraversal(root->children[i]);
    }
}

void postOrderTraversal(TreeNode<int> *root){
    if (root == NULL) return;
    
    for (int i = 0; i < root->children.size(); i++){
        postOrderTraversal(root->children[i]);
    }
    cout << root->data << " ";
}

int main(){
    TreeNode<int> *root = takeInput();
    preOrderTraversal(root);
    cout << endl;
    postOrderTraversal(root);
    cout << endl;
    return 0;
}
 
// input : 10 3 20 30 40 2 40 50 0 0 0 0
// output pre : 10 20 40 50 30 40 
// output post: 40 50 20 30 40 10
// input : 10 3 20 30 40 2 40 50 0 1 70 2 90 100 0 1 60 0 0 0