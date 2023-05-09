#include <iostream>
using namespace std;

template<typename T>
class Node {
    public :
    T data;
    Node<T> *next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template<typename T>
class QueueUsingLL{

    Node<T> *head;
    Node<T> *tail;
    int size;

    public :

    QueueUsingLL(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    //insert element
    void enqueue(T element){
        Node<T> *newNode = new Node<T>(element);

        if (head == NULL){
          head = newNode;
          tail = newNode;
          size++;
        }
        else{
            tail->next = newNode;
            tail = newNode;
            size++;
        }
    }

    T front(){
        if(isEmpty()){
            cout << "Queue is empty " << endl;
            return 0;
        }

        return head->data;
    }

    T deQueue(){
        if(isEmpty()){
            cout << "Queue is empty " ;
            return 0;
        }

        T temp = head->data;
        head = head->next;
        size--;
        return temp;
    }
};


int main()
{
    QueueUsingLL<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    cout << q.front() << endl;

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;

    cout << q.getSize() << endl;
    
    cout << q.isEmpty() << endl;
return 0;
}