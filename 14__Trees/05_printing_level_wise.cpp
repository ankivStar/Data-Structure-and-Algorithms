#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include "02__Tree_Node.h"

TreeNode<int> *takeInputLevelWise(){
    int rootData;
    cout << "Enter data of Root Node" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter the no. of child of " << front->data << endl;
        int childNum;
        cin >> childNum;
        for (int i = 0; i < childNum; i++){
            cout << "Enter the data of " << i << "th child" << endl;
            int childData;
            cin >> childData; 
            TreeNode<int> * child = new TreeNode<int>(childData);
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

int main()
{
   TreeNode<int> *root = new TreeNode<int>(1); 

    root = takeInputLevelWise();

   printTreeLevelWise(root);
   // TODO delete Tree
return 0;
}