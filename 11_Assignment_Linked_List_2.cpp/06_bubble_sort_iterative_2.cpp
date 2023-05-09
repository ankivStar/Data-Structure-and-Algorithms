#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include "D:\Data structure CN\11__Linked_List_2\00__Node.cpp"


int len(Node *head)
{
    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }

    return i;
}

Node *swap(Node *ptr1, Node *ptr2)
{
    Node *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void bubbleSort(Node **head)
{
    int length = len(*head);
    Node **temp;
    int i, j, swapped;
    Node *p1, *p2;

    for (i = 0; i < length; i++)
    {

        temp = head;
        swapped = 0;

        for (j = 0; j < length - i - 1; j++)
        {

            p1 = *temp;
            p2 = p1->next;

            if (p1->data > p2->data)
            {

                /* update the link after swapping */
                *temp = swap(p1, p2);
                swapped = 1;
            }

            temp = &(*temp)->next;
        }

        if (swapped == 0)
            break;
    }
    return;
}

int main()
{
    Node *head = takeInput();
    bubbleSort(&head);
    traverse(head);

    return 0;
}