#include<iostream>
using namespace std;
#include <vector>
#include<queue>
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

TreeNode<int> *nextLarger(TreeNode<int> *root, int x){
    if (root == NULL) return 0;

    TreeNode<int> *ans = NULL;
    if (root->data > x){
    ans = root;
    }

    for (int i = 0; i < root->children.size(); i++){
        TreeNode<int> *result = nextLarger(root->children[i], x);
        if(ans == NULL)
        ans = result;
        else if(result == NULL);
        else if(ans->data > result->data)
        ans = result;
    }
    return ans;
}

int main(){
    TreeNode<int> *root = takeInput();
    int x;
    cin >> x;
    TreeNode<int> *ans = nextLarger(root, x);
    if (ans != NULL)
    cout << ans->data << endl;
    else
    cout << "NULL" << endl;
    return 0;
}

// input : 10 3 20 30 40 2 40 50 0 0 0 0
// input : 11
// output : 20