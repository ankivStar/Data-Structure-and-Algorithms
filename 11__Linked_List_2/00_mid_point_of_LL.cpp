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

int length(Node *head)
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

int midElement(Node *head) // finding mid element by using length
{
    Node *temp = head;
    int len = length(head);

    if (len % 2 == 0)
    {
        len = (len / 2) - 1;
    }
    else
    {
        len = len / 2;
    }

    int i = 0;
    while (i < len)
    {
        temp = temp->next;
        i++;
    }

    return temp->data;
}

int midElementWithoutLen(Node *head) // finding mid element without using length
{
    Node *slow = head;
    Node *fast = slow->next;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}
int main()
{
    Node *head = takeInput();
    // int mid = midElement(head);
    int mid1 = midElementWithoutLen(head);

    cout << "Mid element = " << mid1 << endl;

    return 0;
}