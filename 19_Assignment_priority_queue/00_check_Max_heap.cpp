#include <iostream>
using namespace std;
#include <queue>

bool checkMaxHeap(int* heap, int size){
    int i = 0;
    while (i < size){
        int parentIndex = i;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;
        if (leftChildIndex < size and heap[parentIndex] < heap[leftChildIndex]) return false;
        if (rightChildIndex < size and heap[parentIndex] < heap[rightChildIndex]) return false;
        i++;
    }
    return true;
}

int main(){
    int size;
    cin >> size;
    int heap[size];
    for (int i = 0; i < size; i++){
        cin >> heap[i];
    }

    if(checkMaxHeap(heap, size)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}

/*
input
8
42 20 18 6 14 11 9 4
output
true

input
8
42 20 18 6 14 11 9 8
output
false
*/