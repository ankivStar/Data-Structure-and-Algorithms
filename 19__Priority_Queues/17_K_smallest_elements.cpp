#include <iostream>
using namespace std;
#include <queue>

void kSmallestElement(int* elements, int size, int k){
    // priority_queue<int, vector<int>, greater<int>> pq; 
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++){
        pair<int, int> p;
        p.first = elements[i];
        p.second = i;
        pq.push(p);
    }

    for (int i = k; i < size; i++){
    
        if (elements[i] < pq.top().first){
            pair<int, int> top = pq.top();

            // swap largest with smaller one;
            int temp = elements[i];
            elements[i] = top.first;
            elements[top.second] = temp;

            pq.pop();
            pair<int, int> p;
            p.first = temp;
            p.second = top.second;
            pq.push(p);           
        }
    }
}

int main(){
    int size;
    cin >> size;
    int elements[size];
    for (int i = 0; i < size; i++){
        cin >> elements[i];
    }
    int k;
    cin >> k;

    kSmallestElement(elements, size, k);

    cout << endl;
    for (int i = 0; i < k; i++){
        cout << elements[i] << endl;
    }
    return 0;
}

/*
input
13
2 12 9 16 10 5 3 20 25 11 1 8 6
4
output (order doesn't matter)
5
3
2
1
*/