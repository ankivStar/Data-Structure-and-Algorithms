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
    cout << endl;
}

Node *reverseLL(Node *head)
{
    if (head->next == NULL)
    {
        return head;
    }

    Node *result = reverseLL(head->next);
    Node *temp = result;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    head = result;

    return head;
}

Node *copyLL(Node *head)
{
    Node *temp = head;
    Node *newNode = new Node(temp->data);
    Node *head1 = newNode;
    Node *tail = newNode;
    temp = temp->next;
    
    while(temp != NULL)
    {
        Node *newNode = new Node(temp->data);
        tail->next = newNode;
        tail = newNode;
        temp = temp->next;
    }

    return head1; 
}

bool checkPalindrome(Node *head)
{
    Node *rev = copyLL(head);
    rev = reverseLL(rev);

    while (head != NULL)
    {
        if (rev->data != head->data)
        {
           return false;
        }

        rev = rev->next;
        head = head->next;
    }

    return true;
}

int main()
{
    Node *head = takeInput();
  
    if (checkPalindrome(head))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
    return 0;
}