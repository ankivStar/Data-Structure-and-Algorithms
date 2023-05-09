#include <iostream>
using namespace std;
#include "D:\Data structure CN\11__Linked_List_2\00__Node.cpp"

class Pair
{
    public :
    Node *head;
    Node *tail;
};

Pair reverseLL(Node *head) // time complexity O(n)
{
    if(head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverseLL(head->next);
    smallAns.tail->next = head;
    smallAns.tail = head;
    head->next = NULL;

    return smallAns;
}

Node *k_reverse(int k, Node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    Node *tail = head;
    int count = 0;
    while (count < k-1 and tail->next != NULL) // to reach kth index everytime
    {
        tail = tail->next;
        count++;
    }
    Node *temp = tail->next;
    tail->next = NULL;

    Pair rev = reverseLL(head); // reversing the k elements
    Node *result = k_reverse(k, temp); // calling recursion on after k elements

    head = rev.head;  // combining rerversed elements with recursion result
    rev.tail->next = result;

    return head;
}

int main()
{
    Node *head = takeInput();
    int k;
    cin >> k;
    head = k_reverse(k, head);
    traverse(head);
    
return 0;
}