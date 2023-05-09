#include <iostream>
using namespace std;

void insert(int* heap, int heapSize){
    int childIndex = heapSize;
    while (childIndex > 0){
        int parentIndex = (childIndex-1)/2;
        if (heap[parentIndex] > heap[childIndex]){
            int temp = heap[parentIndex];
            heap[parentIndex] = heap[childIndex];
            heap[childIndex] = temp;
        }else{
            break;
        }
        childIndex = parentIndex;
    }  
}

void removeMin(int* heap, int size){
    int num = heap[0];
    heap[0] = heap[size-1];
    heap[size-1] = num;
    size--;
    int parentIndex = 0;
    int leftChildIndex = 2*parentIndex + 1;
    int rightChildIndex = 2*parentIndex + 2;

    while (leftChildIndex < size){
        int minChildIndex = parentIndex;

        if (rightChildIndex < size and heap[leftChildIndex] > heap[rightChildIndex]){
            minChildIndex = rightChildIndex;
        }else{
            minChildIndex = leftChildIndex;
        }

        if (heap[minChildIndex] < heap[parentIndex]){
            int temp = heap[parentIndex];
            heap[parentIndex] = heap[minChildIndex];
            heap[minChildIndex] = temp;
        }else{
            break;
        }

        parentIndex = minChildIndex;
        leftChildIndex = 2*parentIndex + 1;
        rightChildIndex = 2*parentIndex + 2;
    }
}

void heapSortDescending(int* heap, int size){
    for (int i = 1; i < size; i++){
        insert(heap, i);
    }

    for (int i = size; i > 1; i--){
        removeMin(heap, i);
    }
}

/// Ascending sorting
#include <vector>

void insert1(vector<int>& pq, int heapSize){

	int childIndex = heapSize;
	while (childIndex > 0){
		int parentIndex = (childIndex - 1) / 2;

		if (pq[parentIndex] < pq[childIndex]){
			int temp = pq[parentIndex];
			pq[parentIndex] = pq[childIndex];
			pq[childIndex] = temp;
		}else{
			break;
		}
		childIndex = parentIndex;
	}
}

void removeMax(vector<int>& pq, int heapSize){

	int maxElement = pq[0];
	pq[0] = pq[heapSize - 1];
	pq[heapSize-1] = maxElement;
    heapSize--;
	int parentIndex = 0;
	int leftChildIndex = 2 * parentIndex + 1;
	int rightChildIndex = 2 * parentIndex + 2;

	while (leftChildIndex < heapSize){
		int maxChildIndex = parentIndex;

		//calculating max child index
		if (rightChildIndex < heapSize and pq[leftChildIndex] < pq[rightChildIndex]){
			maxChildIndex = rightChildIndex;
		}else{ 
			maxChildIndex = leftChildIndex;
		}

		if (pq[maxChildIndex] > pq[parentIndex]){
			int temp = pq[maxChildIndex];
			pq[maxChildIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
		}else{
			break;
		}
		parentIndex = maxChildIndex;
		leftChildIndex = 2 * parentIndex + 1;
		rightChildIndex = 2 * parentIndex + 2;
	}
    cout << maxElement << endl;
}
vector<int> heapSortAscending(vector<int>& arr, int n) {
	// Write your code here.
	for (int i = 1; i < n; i++){
		insert1(arr, i);
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
	}

	for (int i = n; i > 1; i--){
		removeMax(arr, i);
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
	}

	return arr;
}

int main(){
    int size;
    cin >> size;

    // int heap[size];
    // for (int i = 0; i < size; i++){
    //     cin >> heap[i];
    // }

    // heapSortDescending(heap, size);
    // for (int i = 0; i < size; i++){
    //     cout << heap[i] << " ";
    // }



    vector<int> heap(size);
    for (int i = 0; i < size; i++){
        cin >> heap[i];
    }
    vector<int> output = heapSortAscending(heap, size);

    for (int i = 0; i < size; i++){
        cout << output[i] << " ";
    }
    return 0;
}

/*
input
6
2 6 8 5 4 3
output
8 6 5 4 3 2
*/