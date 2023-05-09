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

pair<node*, node*> BST_to_LL(BinaryTreeNode<int>*root){
    if (root == NULL){
        pair<node*, node*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }

    pair<node*, node*> leftAns = BST_to_LL(root->left);
    pair<node*, node*> rightAns = BST_to_LL(root->right);
    node *head = NULL;
    node *tail = NULL;

    if (leftAns.first == NULL){
        node* newNode = new node(root->data);
        head = newNode;
        tail = newNode;
    }
    else{
        head = leftAns.first;
        tail = leftAns.second;
        tail->next = new node(root->data);
        tail = tail->next;
    }

    if (rightAns.first != NULL){
        tail->next = rightAns.first;
    }
    if (rightAns.second != NULL){
        tail = rightAns.second;
    }

    pair<node*, node*> finalAns;
    finalAns.first = head;
    finalAns.second = tail;
    return finalAns;
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    traverse(BST_to_LL(root).first);
    delete root;
return 0;
}

/*
input
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
output
2 5 6 7 8 10
*/