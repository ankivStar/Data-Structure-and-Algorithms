#include <iostream>
using namespace std;
#include "00__Node.cpp"

class Pair
{
    public :
    Node *head;
    Node *tail;
};

Pair reverseLL_2(Node *head) // time complexity O(n)
{
    if(head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverseLL_2(head->next);
    smallAns.tail->next = head;
    smallAns.tail = head;
    head->next = NULL;
    // Pair ans;
    // ans.head = smallAns.head;
    // ans.tail = head;

    return smallAns;
}

Node *reverseLL_2_better(Node *head)
{
    return reverseLL_2(head).head;
}
int main()
{   
    Node *head = takeInput();
    Node *rev = reverseLL_2_better(head);
    traverse(rev);

return 0;
}