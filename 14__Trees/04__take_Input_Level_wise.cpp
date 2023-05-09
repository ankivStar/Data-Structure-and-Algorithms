#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include "02__Tree_Node.h"

TreeNode<int> *takeInputLevelWise(){
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter the no. of child of " << front->data << endl;
        int childNum;
        cin >> childNum;
        for (int i = 0; i < childNum; i++){
            cout << "Enter the data of " << i << "th child" << endl;
            int childData;
            cin >> childData; 
            TreeNode<int> * child = new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }

    return root;
}

void printTree(TreeNode<int> *root){

    if (root == NULL){
        return;
    }

    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++){
        cout << root->children[i]->data << ",";
    }
    cout<< endl;

    for (int i = 0; i < root->children.size(); i++){
        printTree(root->children[i]);
    }
}

int main()
{
   TreeNode<int> *root = new TreeNode<int>; 
    root = takeInputLevelWise();
   printTree(root);
   // TODO delete Tree
return 0;
}