#include <iostream>
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

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }

        else
        {
            tail->next = n;
            tail = n;
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

Node *eliminateConsecutiveDuplicate(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        Node *n = temp->next;
        if (temp->data == n->data)
        {
            while (n->next != NULL and temp->data == n->data)
            {
                n = n->next;
            }

            if (n->data == temp->data)
            {
                temp->next = n->next;
            }
            else
            {
                temp->next = n;
            }
        }

        if (temp->next != NULL)
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    head = eliminateConsecutiveDuplicate(head);
    traverse(head);
    return 0;
}