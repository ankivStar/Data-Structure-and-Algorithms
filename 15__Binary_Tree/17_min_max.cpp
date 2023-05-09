#include <iostream>
using namespace std;
#include "00__Binary_Tree.h"
#include <queue>
#include "03_input.h"

pair<int, int> min_max(BinaryTreeNode<int> *root){
    if (root == NULL){
        pair<int, int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }

    pair<int, int> leftMinMax = min_max(root->left);
    pair<int, int> rightMinMax = min_max(root->right);
    int lMin = leftMinMax.first;
    int lMax = leftMinMax.second;
    int rMin = rightMinMax.first;
    int rMax = rightMinMax.second; 

    pair<int, int> p;
    p.first = min(root->data, min(lMin, rMin));
    p.second = max(root->data, max(lMax, rMax));
    return p;
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    pair<int, int> result = min_max(root);
    cout << "Min = " << result.first << endl;
    cout << "Max = " << result.second << endl;
    delete root;
return 0;
}

/*
input 
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
output
min = 1
max = 14

input
10 20 60 -1 -1 3 50 -1 -1 -1 -1
min = 3
max = 60

input
10 0  60 -1 -1 -1 -1
output
min = 0
max = 60
*/
