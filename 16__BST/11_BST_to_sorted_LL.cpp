#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"

class node{
    public :
    int data;
    node *next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

void traverse(node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

node *BST_to_LL(BinaryTreeNode<int>*root){
    if (root == NULL) return NULL;

    node *leftAns = BST_to_LL(root->left);
    node *head = NULL;
    node *temp = NULL;
    if (leftAns == NULL){
        node *newNode = new node(root->data);
        temp = newNode;
        head = newNode;
    }
    else{
        temp = leftAns;
        head = leftAns;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new node(root->data);
        temp = temp->next;
    }
    temp->next = BST_to_LL(root->right);
    return head;
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    traverse(BST_to_LL(root));
    delete root;
return 0;
}

/*
input
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
output
2 5 6 7 8 10
*/