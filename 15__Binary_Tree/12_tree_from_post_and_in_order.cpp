#include <iostream>
using namespace std;
#include "00__Binary_Tree.h"
#include <queue>
#include "03_traverse.h"

void input(int root[], int size){
    for (int i = 0; i < size; i++){
        cin >> root[i];
    }
}

int helper(int inOrder[], int postNum, int start, int end){
    for (int i = start; i <= end; i++){
        if (inOrder[i] == postNum)
            return i;
    }
    return 0;
}

BinaryTreeNode<int> *constructTree(int postOrder[], int inOrder[], int inStart, int inEnd){
    static int postIndex = inEnd;
    if(inStart > inEnd) return NULL;

    cout << postIndex << " ";
    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(postOrder[postIndex]);

    int nodeindex = helper(inOrder, postOrder[postIndex--], inStart, inEnd);

    newNode->right = constructTree(postOrder, inOrder, nodeindex+1, inEnd);
    newNode->left = constructTree(postOrder, inOrder, inStart, nodeindex-1);

    return newNode;
}

// Approach 2
BinaryTreeNode<int>* Approach2helper(int* in, int* post, int inS, int inE, int postS, int postE){
    if (inS > inE) return NULL;

    int rootData = post[postE];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++){
        if (rootData == in[i]){
            rootIndex = i;
            break;
        }
    }
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPostE = postE - 1;
    int rPostS = rPostE - rInE + rInS;
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPostS = postS;
    int lPostE = rPostS - 1;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->right = Approach2helper(in, post, rInS, rInE, rPostS, rPostE);
    root->left = Approach2helper(in, post, lInS, lInE, lPostS, lPostE);

    return root;
}

BinaryTreeNode<int>* constructTreeApproach2(int* post, int* in, int size){
    return Approach2helper(in, post, 0, size-1, 0, size-1);
}

int main(){
    int n;
    cin >> n;
    int postOrder[n];
    int inOrder[n];

    input(postOrder, n);
    input(inOrder, n);

    BinaryTreeNode<int> *root = constructTree(postOrder, inOrder, 0, n-1);
    // BinaryTreeNode<int> *root = constructTreeApproach2(postOrder, inOrder, n);
    //traverse(root);
    delete root;
return 0;
}

/*
input
7
4 5 2 6 7 3 1
4 2 5 1 6 3 7
output
1 : L2R3
2 : L4R5
3 : L6R7
4 :
5 :
6 :
7 : 

*/
/*
input:
6
2 9 3 6 10 5
2 6 3 9 5 10
output :
5 : L6R10
6 : L2R3
10 : 
2 : 
3 : R9
9 :
*/