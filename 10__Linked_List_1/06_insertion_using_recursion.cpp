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

Node *insertAtIthPos(int i, int num, Node *head) // inserting element using recursion
{
    if (head == NULL)
    {
        return head;
    }
    if(i == 0)
    {
        Node *n = new Node(num);
        n->next = head;
        head = n;
        return head;
    }
    if (i == 1)
    {
        Node *n = new Node(num);
        n->next = head->next;
        head->next = n;
        return head;
    }

    Node *first = head;
    Node *result = insertAtIthPos(i - 1, num, head->next);

    first->next = result;
    head = first;
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
