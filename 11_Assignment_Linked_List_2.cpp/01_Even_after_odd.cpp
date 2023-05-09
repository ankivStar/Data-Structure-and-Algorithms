#include <iostream>
using namespace std;
#include "D:\Data structure CN\11__Linked_List_2\00__Node.cpp"

Node *evenAfterOdd(Node *head)
{
    Node *temp = head;
    Node *oddHead = NULL;
    Node *oddTail = NULL;
    Node *evenHead = NULL;
    Node *evenTail = NULL;
    while (temp != NULL)
    {
        if (temp->data % 2 != 0)
        {
            if (oddHead == NULL)
            {
                oddHead = temp;
                oddTail = temp;
            }
            else
            {
                oddTail->next = temp;
                oddTail = temp;
            }
        }

        else
        {
            if (evenHead == NULL)
            {
                evenHead = temp;
                evenTail = temp;
            }
            else
            {
                evenTail->next = temp;
                evenTail = temp;
            }
        }
        temp = temp->next;
    }

    if (oddHead == NULL)
    {
        oddHead = evenHead;
        oddHead->next = evenHead->next;
    }
    else if(evenHead == NULL)
    {
        oddTail->next = evenHead;
    }
    else
    {
        oddTail->next = evenHead;
        evenTail->next = NULL;
    }

    return oddHead;
}

int main()
{
    Node *head = takeInput();
    head = evenAfterOdd(head);
    traverse(head);

    return 0;
}