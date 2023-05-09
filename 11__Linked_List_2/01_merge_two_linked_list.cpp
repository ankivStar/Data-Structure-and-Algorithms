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
    cin>> data;
    Node *head = NULL;
    Node *tail = NULL;

    while(data != -1)
    {
        Node *n = new Node(data);
        if(head == NULL)
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
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *mergeTwoLL(Node *head1, Node *head2)
{
    Node *finalHead = NULL;
    Node *finalTail = NULL;

    if(head1 == NULL)
    {
        return head2;
    }
    if(head2 == NULL)
    {
        return head1;
    }

    while (head1 != NULL and head2 != NULL)
    {
        if((head1->data < head2->data) and finalHead == NULL)
        {
            finalHead = head1;
            finalTail = head1;
            head1 = head1->next;
        }
        else if ((head1->data > head2->data) and finalHead == NULL)
        {
            finalHead = head2;
            finalTail = head2; 
            head2 = head2->next;
        }
        else if(head1->data < head2->data)
        {
            finalTail->next = head1;
            finalTail = head1;
            head1 = head1->next;
        }
        else{
            finalTail->next = head2;
            finalTail = head2;
            head2 = head2->next;
        }
    }
    while(head1 != NULL)
    {
        finalTail->next = head1;
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        finalTail->next = head2;
        head2 = head2->next;
    }

    return finalHead;
}

 int main()
{
    Node *head1 = takeInput();
    Node *head2 = takeInput();

    // traverse(head1);
    // traverse(head2);

    Node *finalHead = mergeTwoLL(head1, head2);
    traverse(finalHead);

    return 0;
}