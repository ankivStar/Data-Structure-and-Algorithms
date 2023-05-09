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

int findNode(Node *head, int num)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL and temp->data != num )
    {
        temp = temp->next;
        count++;
    }
    
    if (temp == NULL)
    {
        count = -1;
    }
    
    return count;
}

int main()
{
    Node *head = takeInput();
    int num;
    cin >> num;
    int result = findNode(head, num);
    cout << result << endl;

    return 0;
}