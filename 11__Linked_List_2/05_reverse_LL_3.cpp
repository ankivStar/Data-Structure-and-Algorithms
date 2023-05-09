#include <iostream>
using namespace std;
#include "00__Node.cpp"

Node *reverseLL_3(Node *head) // time complexity O(n)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *result = reverseLL_3(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;

    return result;
}

int main()
{
    Node *head = takeInput();
    Node *rev = reverseLL_3(head);
    traverse(rev);
return 0;
}