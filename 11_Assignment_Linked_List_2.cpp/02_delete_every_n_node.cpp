#include <iostream>
using namespace std;
#include "D:\Data structure CN\11__Linked_List_2\00__Node.cpp"

Node *deleteEveryNNode(Node *head,int m, int n)
{
    Node *temp1 = head;
    Node *temp2 = NULL;
    int count ;
    while (temp1 != NULL)
    {
        count = 1;
        while(count < m and temp1->next != NULL)
        {
            temp1 = temp1->next;
            count++;
        }

        count = 0;
        temp2 = temp1;
        while(count < n and temp1->next != NULL)
        {
            temp1 = temp1->next;
            count++;
        }
        
        if(m != 0)
        {
            temp2->next = temp1->next;
            temp1 = temp1->next;
        }
        else{
            head = temp1->next;
            temp1 = temp1->next;
        }

    }

    return head;
}

int main()
{
    Node *head = takeInput();
    int m, n;
    cin >> m >> n;
    head = deleteEveryNNode(head, m, n);
    traverse(head);
    
return 0;
}