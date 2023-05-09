#include <iostream>
using namespace std;
#include <queue>
#include <vector>
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

int NodeWithLargestdata(TreeNode<int> *root){
    if(root == NULL) return 0;

    int max = root->data;
    for (int i = 0; i < root->children.size(); i++){
        int ans= NodeWithLargestdata(root->children[i]);
        if (ans > max) max = ans;
    }
    return max;
}

int main(){
    TreeNode<int> *root = takeInput();
    cout << NodeWithLargestdata(root) << endl;
    return 0;
}

// input : 10 3 20 30 40 2 40 50 0 0 0 0
// output : 50