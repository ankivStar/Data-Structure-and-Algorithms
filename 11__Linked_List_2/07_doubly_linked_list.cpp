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
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseTraverse(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

Node *insertNumAtIthPos(int i, int num, Node *head)
{
    Node *temp = head;
    int j = 0;

    if (i == 0)
    {
        Node *newNode = new Node(num);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;

        return head;
    }

    while (temp != NULL and j < i - 1)
    {
        temp = temp->next;
        j++;
    }

    if (temp != NULL)
    {
        Node *newNode = new Node(num);
        newNode->next = temp->next;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    return head;
}

Node *deleteNode(int i, Node *head)
{
    Node *temp = head;

    if (i == 0) // to delete 0th node
    {
        head = temp->next;
        temp->next->prev = NULL;
    }

    int j = 0;
    while (temp != NULL and j < i - 1)
    {
        temp = temp->next;
        j++;
    }

    if (temp->next->next == NULL) // to delete last node
    {
        temp->next = NULL;
        return head;
    }

    if (temp != NULL and temp->next != NULL) // to delete node except 0th and last
    {
        temp->next = temp->next->next;
        temp->next->next->prev = temp;
    }

    return head;
}

main()
{
    Node *head = takeInput();

    // insertion
    int pos, num;
    cin >> pos >> num;
    Node *insert = insertNumAtIthPos(pos, num, head);
    traverse(insert);

    //deletion
    // int i;
    // cin >> i;
    // Node *del = deleteNode(i, head);
    // traverse(del);

    // reverseTraverse(head);

    return 0;
}