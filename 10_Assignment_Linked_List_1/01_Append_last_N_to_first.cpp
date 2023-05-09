#include <iostream>
using namespace std;

class Node
{
    public :

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

int length(Node *head)
{
    int count = 0;
    while(head != NULL)
    {
        head = head->next;
        count++;
    }
    
    return count;
}

Node *appendLastNToFirst(int n, Node *head)
{
    int l = length(head) - 1;
    int diff = l - n;
    
    Node *temp = head;
    Node *tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }

    int i = 0;
    while(i < diff)
    {
        temp = temp->next;
        i++;
    }
    Node *a = temp->next;
    tail->next = head;
    temp->next = NULL;
    head = a;
    return head;

}

int main()
{
    Node *head = takeInput();
    int n;
    cin >> n;
    head = appendLastNToFirst(n, head);
    traverse(head);
    
return 0;
}