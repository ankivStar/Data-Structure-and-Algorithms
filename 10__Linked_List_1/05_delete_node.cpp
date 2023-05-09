#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

Node *takeInputWithTail() // time complexity = O(n)
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void traverse(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

}

Node *deleteAtIthPos(int i, Node *head)
{
    Node *temp = head;
    int count = 0;

    if(i == 0)
    {
        head = head->next;
        return head;
    }

    while(temp != NULL and count < i-1)
    {
        temp = temp->next;
        count++;
    }
    
    if(temp != NULL)
    {
        Node *a = temp->next;
        Node *b = a->next;
        temp->next = b;
    }

    return head;
}

int main()
{
    Node *head = takeInputWithTail();
    int index;
    cin >> index;
    head = deleteAtIthPos(index, head);
    traverse(head);

    return 0;
}
