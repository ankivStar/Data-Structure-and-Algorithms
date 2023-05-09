#include <iostream>
using namespace std;
#include<queue>

void reverse(queue<int> &q){
    if(q.size() == 0 or q.size() == 1){
        return;
    }

    int front = q.front();
    q.pop();

    reverse(q);
    q.push(front);
    
    return;
}

int main()
{
    queue<int> q;
    int n;
    cin >> n;
    int element;
    for (int i = 0; i < n; i++){
        cin >> element;
        q.push(element);
    }

    reverse(q);
    for (int i = 0; i < n; i++){
        cout << q.front() << " ";
        q.pop();
    }
    
return 0;
}