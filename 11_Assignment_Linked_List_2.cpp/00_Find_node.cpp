#include <iostream>
using namespace std;
#include "D:\Data structure CN\11__Linked_List_2\00__Node.cpp"

int findNode(int num, Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if(temp->data == num)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }

    return -1;
}
int main()
{
    Node *head = takeInput();
    int num;
    cin >> num;

    int node = findNode(num, head);
    cout << node << endl;

return 0;
}