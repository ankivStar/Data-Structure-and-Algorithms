#include <iostream>
using namespace std;
#include "00__Node.cpp"

Node *reverseLL_4(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next1 = current->next;

    while(current != NULL)
    {
        current->next = prev;
        prev = current;
        current = next1;
        if(next1 != NULL)
        {
            next1 = next1->next;
        }
    }

    return prev;
}

int main()
{
    Node *head = takeInput();
    Node *rev = reverseLL_4(head);
    traverse(rev);   
return 0;
}