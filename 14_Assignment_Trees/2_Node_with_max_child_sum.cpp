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
// Approach 2
class Pair{
    public :

    TreeNode<int> *node;
    int sum;
};

Pair helper(TreeNode<int> *root){
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++){
        sum += root->children[i]->data;
    }

    Pair result;
    result.node = root;
    result.sum = sum;

    for (int i = 0; i < root->children.size(); i++){
        Pair ans = helper(root->children[i]);
        if (ans.sum > result.sum){
            result.sum = ans.sum;
            result.node = ans.node;
        }
    }

    return result;
}

int NodeWithMaxChildSum(TreeNode<int> *root){
    if(root == NULL) return 0;

    Pair result = helper(root);
    return result.node->data;
}

//Approach 1
int sumOfNode(TreeNode<int> *root){
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++){
        sum += root->children[i]->data;
    }
    return sum;
}

TreeNode<int> *helper1(TreeNode<int> *root){
    
    int rootNodeSum = sumOfNode(root);
    TreeNode<int> *cur = root;

    for (int i = 0; i < root->children.size(); i++){
        TreeNode<int> *result = helper1(root->children[i]);
        int childNodeSum = sumOfNode(root->children[i]);
        if (childNodeSum > rootNodeSum){
            rootNodeSum = childNodeSum;
            cur = result;
        }
    }
    return cur;
}
int NodeWithMaxChildSum1(TreeNode<int> *root){
    if(root == NULL) return 0;
    TreeNode<int> *ans = helper1(root);
    return ans->data;
}

int main(){
    TreeNode<int> *root = takeInput();
    //cout << NodeWithMaxChildSum1(root) << endl; // approach 1
    cout << NodeWithMaxChildSum(root) << endl; // approach 2
}

// input : 10 3 20 30 40 2 40 50 0 0 0 0
// output : 20
// input : 10 3 20 30 40 2 40 50 0 1 70 2 90 100 0 1 60 0 0 0
// output : 40