#include <iostream>
using namespace std;
#include "00__Binary_Tree.h"
#include<queue>
#include "03_traverse.h"

void input(int size, int *root){
    for (int i = 0; i < size; i++){
        cin >> root[i];
    }
}

int helper(int *inOrder,int num, int start, int end ){
    for (int i = start; i <= end; i++){
        if(inOrder[i] == num){
            return i;
        }
    }
    return 0;
}
BinaryTreeNode<int> *constructTree(int *preOrder, int *inOrder, int inStart, int inEnd){
    static int preIndex = 0;
    if(inStart > inEnd) 
        return NULL;

    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(preOrder[preIndex]);
  
    int nodeIndex = helper(inOrder, preOrder[preIndex++],inStart, inEnd);

    BinaryTreeNode<int> *leftChild = constructTree(preOrder, inOrder, inStart, nodeIndex-1);
    BinaryTreeNode<int> *rightChild = constructTree(preOrder, inOrder, nodeIndex+1, inEnd);
    
    newNode->left = leftChild;
    newNode->right = rightChild;

    return newNode;
 }

//Approach 2
BinaryTreeNode<int>* Approach2helper(int* in, int* pre, int inS, int inE, int preS, int preE){
    if (inS > inE) return NULL;

    int rootData = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++){
        if (rootData == in[i]){
            rootIndex = i;
            break;
        }
    }
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = Approach2helper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = Approach2helper(in, pre, rInS, rInE, rPreS, rPreE);

    return root;
}

BinaryTreeNode<int>* constructTreeApproach2(int* pre, int* in, int size){
    return Approach2helper(in, pre, 0, size-1, 0, size-1);
}

int main(){

//    #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif

    int n;
    cin >> n;
    int preOrder[n];
    int inOrder[n];

    input(n, preOrder);
    input(n, inOrder);

    BinaryTreeNode<int> *root = constructTree(preOrder, inOrder, 0, n-1);
    // BinaryTreeNode<int> *root = constructTreeApproach2(preOrder, inOrder, n);
    traverse(root);
    delete root;
return 0;
}
/*
input
7
1 2 4 5 3 6 7
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
5 6 2 3 9 10
2 6 3 9 5 10
output :
5 : L6R10
6 : L2R3
10 : 
2 : 
3 : R9
9 :
*/