#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"
#include <vector>

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void traverse(vector<Node *> v){
    for (int i = 0; i < v.size(); i++){
        Node *head = v[i];
        while (head != NULL){
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
}

vector<Node *> levelWiseLinkedList(BinaryTreeNode<int> *root){
    vector<Node *> v;
    if (root == NULL) return v;

    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    q.push(NULL);

    Node *head = NULL;
    Node *tail = NULL;

    while (!q.empty()){
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        if (front != NULL){
            Node *newNode = new Node(front->data);
            if (head == NULL){
                head = newNode;
                tail = newNode;
                v.push_back(head);
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }

            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
        }

        else{
            if (q.empty()) break;
            
            head = NULL;
            q.push(NULL);
        }
    }
    return v;
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    traverse(levelWiseLinkedList(root));
    return 0;
}

/*
input
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
output
5
6 10
2 3 
9

input
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
output
8
3 10
1 6 14
4 7 13
*/