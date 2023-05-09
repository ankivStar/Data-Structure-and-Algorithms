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

int countLeafNode(TreeNode<int> *root){
    if (root == NULL) return 0;
    
    if (root->children.size() == 0){
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++){
        ans += countLeafNode(root->children[i]);
    }
    return ans;
}

int main(){
    TreeNode<int> *root = takeInput();
    cout << countLeafNode(root) << endl;
    return 0;
}
 
// input : 10 3 20 30 40 2 40 50 0 0 0 0
// output : 3
// input : 10 3 20 30 40 2 40 50 0 1 70 2 90 100 0 1 60 0 0 0
// output : 4