#include <iostream>
using namespace std;
#include "D:\Data structure CN\11__Linked_List_2\00__Node.cpp"

int length(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }

    return count;
}

Node *bubbleSort(Node *head)
{
    int len = length(head);

    Node *temp = NULL;
    Node *curr = NULL;
    Node *prev = NULL;

    for (int i = 0; i < len; i++)
    {
        curr = head;
        prev = NULL;

        int count = 0;
        while (count < len - i - 1 and curr != NULL and curr->next != NULL)
        {
            if (curr->data > curr->next->data and curr == head)
            {
                temp = curr->next->next;

                head = curr->next;
                curr->next->next = curr;
                curr->next = temp;
                prev = head;
            }

            else if (curr->data > curr->next->data)
            {
                temp = curr->next->next;

                prev->next = curr->next;
                curr->next->next = curr;
                curr->next = temp;
                prev = prev->next;
            }

            else
            {
                prev = curr;
                curr = curr->next;
            }
            count++;
        }
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    head = bubbleSort(head);
    traverse(head);
    return 0;
}