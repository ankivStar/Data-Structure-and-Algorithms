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

void printAtLevelK(TreeNode<int> *root, int k){
    if (root == NULL) return;

    if (k == 0){
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++){    
        printAtLevelK(root->children[i], k - 1);
    }
}

int main(){
    TreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    printAtLevelK(root, k);
    return 0;
}
 
// input : 10 3 20 30 40 2 40 50 0 0 0 0 and k = 2
// output : 40 50
