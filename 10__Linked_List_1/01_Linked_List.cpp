#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void traverse(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    // statically
    Node n1(1);
    Node *head = &n1;

    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    traverse(head);

    // n1.next = &n2;

    // cout << n1.data << " " << n2.data << endl;

    // // Dynamically
    // Node *n3 = new Node(3);
    // Node *n4 = new Node(4);

    // n2.next = n3;
    // n3->next = n4;

    // cout << n3->data << " " << n4->data << endl;

    return 0;
}
