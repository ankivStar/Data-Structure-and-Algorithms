#include <iostream>
using namespace std;
#include "00__Binary_Tree.h"
#include<queue>
#include "03_input.h"

pair<int, int> heightDiameter(BinaryTreeNode<int> *root){
    if (root == NULL){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rigthAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rigthAns.second;
    int rh = rigthAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    cout << "height = " << heightDiameter(root).first << endl;
    cout << "Diameter = " << heightDiameter(root).second << endl;
    delete root;
return 0;
}

/*
input 1:-
10 20 30 40 50 -1 -1 -1 -1 -1 -1
output 1:-
height = 3
diameter = 3

input 2:-
1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1
output 2:-
height = 5
diameter = 6
*/