#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"
#include <stack>

class BSTIterator{
    private : 
    stack<BinaryTreeNode<int>*> s;
    bool reverse;

    public:
    BSTIterator(BinaryTreeNode<int>* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    public :
    int next(){
        BinaryTreeNode<int>* temp = s.top();
        s.pop();
        if (reverse){
            pushAll(temp->left);
        }else{
            pushAll(temp->right);
        }
        return temp->data;
    }

    private :
    void pushAll(BinaryTreeNode<int>* node){
        for (; node != NULL; ){
            s.push(node);
            if (reverse) node = node->right;
            else node = node->left;
        }
    }
};

void pairSum(BinaryTreeNode<int>* root, int sum){
    if (!root) return;

    BSTIterator inOrder(root, false);
    BSTIterator revInOrder(root, true);
    int i = inOrder.next();
    int j = revInOrder.next();
    while (i < j){
        if (i + j == sum){
            cout << i << " " << j << endl;
            i = inOrder.next();
            j = revInOrder.next();
        }else if ( i + j < sum){
            i = inOrder.next();
        }else{
            j = revInOrder.next();
        }
    }

}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
    return 0;
}

/*
input
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
output
2 10
5 7
*/