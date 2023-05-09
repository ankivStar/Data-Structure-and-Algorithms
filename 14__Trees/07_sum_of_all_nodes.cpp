#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include "02__Tree_Node.h"

TreeNode<int> *takeInput(){
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int childNum;
        cin >> childNum;
        for (int i = 0; i < childNum; i++){
            int childData;
            cin >> childData; 
            TreeNode<int> * child = new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

int sumOfNodes(TreeNode<int> *root){
    int ans = root->data;

    for (int i = 0; i < root->children.size(); i++){
        ans += sumOfNodes(root->children[i]);
    }
    return ans;
}

int main(){
    TreeNode<int> *root = takeInput();
    cout << sumOfNodes(root) << endl;
    delete root;
    return 0;
}