#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int data)
    {
        prev = NULL;
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
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cin >> data;
    }

    return head;
}

void traverse(Node *head)
{
    Node *temp = head->next;

    while (temp != head)
    {
        cout << temp->prev->data << " ";
        temp = temp->next;
    }
    cout << temp->prev->data << " " << endl;
}

Node *circularDoublyLL(Node *head)
{
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head;
    head->prev = temp;

    return head;
}

int main()
{
    Node *head = takeInput();
    head = circularDoublyLL(head);
    traverse(head);
}