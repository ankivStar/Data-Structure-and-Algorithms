#include <iostream>
using namespace std;
#include "00__Node.cpp"

Node *reverseLL(Node *head) // time complexity O(n²)
{
    if (head == NULL || head->next == NULL)
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

int main()
{
    Node *head = takeInput();
    Node *rev = reverseLL(head);
    traverse(rev);

    return 0;
}