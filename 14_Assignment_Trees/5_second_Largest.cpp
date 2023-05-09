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

int maxNode(TreeNode<int> *root){
    if (root == NULL) return 0;

    int max = root->data;
    for (int i = 0; i < root->children.size(); i++){
        int ans = maxNode(root->children[i]);
        if (ans > max)
        max = ans;
    }
    return max;
}
TreeNode<int> *nextSmallest(TreeNode<int> *root, int x){
    if (root == NULL) return 0;

    TreeNode<int> *ans = NULL;
    if (root->data < x){
    ans = root;
    }

    for (int i = 0; i < root->children.size(); i++){
        TreeNode<int> *result = nextSmallest(root->children[i], x);
        if(ans == NULL)
        ans = result;
        else if(result == NULL);
        else if(ans->data < result->data)
        ans = result;
    }
    return ans;
}

TreeNode<int> *secondLargest(TreeNode<int> *root){
    int max = maxNode(root);
    return nextSmallest(root, max);
}

int main(){
    TreeNode<int> *root = takeInput();
    TreeNode<int> *ans = secondLargest(root);
    if (ans != NULL)
    cout << ans->data << endl;
    else
    cout << "NULL" << endl;
    return 0;
}

// input : 10 3 20 30 40 2 40 50 0 0 0 0
// output : 40
// input : 10 3 40 8 30 2 20 25 1 26 0 0 0 0
// output : 30