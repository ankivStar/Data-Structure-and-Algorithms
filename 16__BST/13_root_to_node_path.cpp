#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){
    if (root == NULL){
        return NULL;
    }

    if (root->data == data){
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>* leftOutput = getRootToNodePath(root->left, data);
    if (leftOutput != NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput = getRootToNodePath(root->right, data);
    if (rightOutput != NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }else{
        return NULL;
    }
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    int data; 
    cin >> data;
    vector<int>* output = getRootToNodePath(root, data);
    for (int i = 0; i < output->size(); i++){
        cout << output->at(i) << " ";
    }
    delete root;
    delete output;
    return 0;
}

/*
input
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
output
2 5 8
*/