#include <iostream>
using namespace std;
#include "D:\Data structure CN\11__Linked_List_2\00__Node.cpp"

Node *swapTwoNodes(int i, int j, Node *head)
{
    Node *prev1 = head;
    Node *curr1 = head;
    Node *prev2 = head;
    Node *curr2 = head;
    Node *temp = head;
    Node *temp1 = NULL;

    int count = 0;

    if (i == j) // if i and j  are equal then no swapping possible, return same LL
    {
        return head;
    }

    if (i > j)
    {
        int t = i;
        i = j;
        j = t;
    }

    while (count < i and temp->next != NULL) // reaching to ith index 
    {
        prev1 = curr1;
        curr1 = curr1->next;
        temp = temp->next;
        count++;
    }

    prev2 = curr1;
    curr2 = curr1;

    while (count < j and temp->next != NULL) //reaching to jth index
    {
        prev2 = curr2;
        curr2 = curr2->next;
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL) // if any of the i or j is greater than highest index of LL
    {                        // then no swapping possible, return the same LL
        return head;
    }

    else if (i == 0 and j - i == 1) // if i equal to 0 and j equal to 1 or vice-versa
    {
        prev2->next = head;
        head->next = curr2->next;
        head = curr2;
        curr2->next = curr1;

        return head;
    }

    else if (i == 0) // if either i equal to 0 or j equal to 0
    {
        Node *temp2 = curr2->next;
        temp1 = head;
        head = curr2;
        curr2->next = temp1->next;
        prev2->next = temp1;
        temp1->next = temp2;

        return head;
    }

    else if (j - i == 1) // if i and j are adjacent/consecutive
    {
        prev1->next = curr2;
        prev2->next = curr1;
        curr1->next = curr2->next;
        curr2->next = curr1;

        return head;
    }

    else // rest of the cases
    {
        temp1 = curr1->next;
        prev1->next = curr2;
        prev2->next = curr1;
        curr1->next = curr2->next;
        curr2->next = temp1;

        return head;
    }

}

int main()
{
    Node *head = takeInput();
    int i, j;
    cin >> i >> j;
    head = swapTwoNodes(i, j, head);
    traverse(head);

    return 0;
}