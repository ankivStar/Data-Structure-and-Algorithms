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

Node *insertAtIthPos(int i, int data, Node *head)
{
    Node *temp = head;
    int j = 0;

    if (i == 0)
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
        return head;
    }

    while (temp != NULL and j < i - 1)
    {
        temp = temp->next;
        j++;
    }
    if(temp != NULL)
    {
        Node *n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

    return head;
}

int main()
{
    Node *head = takeInputWithTail();
    int index, num;
    cin >> index >> num;
    head = insertAtIthPos(index, num, head);
    traverse(head);

    return 0;
}
