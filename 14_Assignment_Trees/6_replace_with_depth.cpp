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

void printTreeLevelWise(TreeNode<int> *root){
    if (root == NULL){
        return;
    }

    queue<TreeNode<int> *> print;
    print.push(root);

    while (print.size() != 0){
        TreeNode<int> *front = print.front();
        print.pop();

        cout << front->data << ": ";
        for(int i = 0; i < front->children.size(); i++){
            cout << front->children[i]->data << ",";
            print.push(front->children[i]);
        }
        cout << endl;
    }
}

TreeNode<int> *helper(TreeNode<int> *root, int depth){

    root->data = depth;
    for (int i = 0; i < root->children.size(); i++){
        TreeNode<int> *result = helper(root->children[i], depth + 1);
    }
    return root;
}

TreeNode<int> *replaceWithDepth(TreeNode<int> *root){
    if(root == NULL) return NULL;
    return helper(root, 0);
}

int main(){
    TreeNode<int> *root = takeInput();
    printTreeLevelWise(replaceWithDepth(root));
    
    return 0;
}

 /* input : 
    10 3 20 30 40 2 40 50 0 0 0 0
    output :
    0 : 1,1,1,
    1 : 2,2,
    1 : 
    1 : 
    2 :
    2 :
*/                
