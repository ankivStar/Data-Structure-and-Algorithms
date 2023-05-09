#include <iostream>
using namespace std;
#include<queue>
#include <vector>
#include "..\14__Trees\02__Tree_Node.h"

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

bool containX(TreeNode<int> *root, int x){
    if(!root) return false;
 
    if(root->data == x) return true;

    bool result = false;
    for (int i = 0; i < root->children.size(); i++){
        result = containX(root->children[i], x);
    }
    return result;
}

int main(){
    TreeNode<int> *root = takeInput();
    int x; 
    cin >> x;
    cout << containX(root, x) << endl;
    
    //cout << root->children.size();
    return 0;
}
 
// input : 10 3 20 30 40 2 40 50 0 0 0 0 and 40
// output : YES
// input : 10 3 20 30 40 2 40 50 0 1 70 2 90 100 0 1 60 0 0 0 and 80
// output : No