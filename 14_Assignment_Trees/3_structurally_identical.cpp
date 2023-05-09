#include<iostream>
using namespace std;
#include<queue>
#include <vector>
#include "..\14__Trees\02__Tree_Node.h"

TreeNode<int> *takeInput(){
    int rootData;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int childNum;
        cin >> childNum;
        for (int i = 0; i < childNum; i++){
            int childData;
            cin >> childData;

            TreeNode<int> *child = new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;   
}

bool structurallyIdentical(TreeNode<int> *root1, TreeNode<int> *root2){
    if(root1 == NULL or root2 == NULL) return false;

    bool result = true;
    int r1cs = root1->children.size(); //root1ChildSize(r1cs) calculation
    int r2cs = root2->children.size(); //root2ChildSize(r2cs) calculation
    if(root1->data != root2->data or r1cs != r2cs) return !result;
    for (int i = 0; i < root1->children.size() and i < root2->children.size(); i++){
       bool childResult = structurallyIdentical(root1->children[i], root2->children[i]);
        if(!childResult)
        result = childResult;
    }

    return result;
}
int main(){
    TreeNode<int> *root1 = takeInput();
    TreeNode<int> *root2 = takeInput();

    cout << structurallyIdentical(root1, root2) << endl;
}

// input : 10 3 20 30 40 2 40 50 0 0 0 0
// input : 10 3 20 30 40 2 40 50 0 0 0 0
// output : true

// input : 10 3 20 30 40 2 40 50 0 0 0 0
// input : 10 3 20 30 40 2 40 50 0 1 70 2 90 100 0 1 60 0 0 0
// output : false