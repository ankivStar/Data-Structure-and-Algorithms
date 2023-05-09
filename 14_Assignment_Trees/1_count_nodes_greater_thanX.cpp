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

int countNumOfGreaterX(TreeNode<int> *root, int x){
    if(root == NULL) return 0;

    int ans = 0;
    for (int i = 0; i < root->children.size(); i++){
        ans += countNumOfGreaterX(root->children[i], x);
    }
    if(root->data > x) return 1 + ans;
    else return ans;
}

int main(){
    TreeNode<int> *root = takeInput();
    int x;
    cin >> x;
    cout << countNumOfGreaterX(root, x) << endl;
}

// input : 10 3 20 30 40 2 40 50 0 0 0 0 and 20
// output : 4
// input : 10 3 20 30 40 2 40 50 0 1 70 2 90 100 0 1 60 0 0 0 and 10
// output : 9