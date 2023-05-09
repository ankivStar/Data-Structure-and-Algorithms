#include <vector>

class PriorityQueue{
    vector<int> pq;

    public :
    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.size() == 0;
    }

    // return the size of priorityQueue -no. of elements present
    int getSize(){
        return pq.size();
    }

    int getMin(){
        if (isEmpty()) return 0;
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);

        //up heapify
        int childIndex = pq.size() - 1;
        while (childIndex > 0){
            int parentIndex = (childIndex - 1) / 2;

            if(pq[childIndex] < pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }else{
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin(){
        if (isEmpty()) return 0;

        int minElement = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        
        int parentIndex = 0;  
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;

        // down-heapify
        while (leftChildIndex < pq.size()){
            int minChildIndex = parentIndex;

            // calculating the index of smallest/min child
            if (rightChildIndex < pq.size()){
                if (pq[leftChildIndex] < pq[rightChildIndex]) minChildIndex = leftChildIndex;
                else minChildIndex = rightChildIndex;
            }
            else{
                minChildIndex = leftChildIndex;
            }

            // swapping parent value with its smallest child
            if (pq[minChildIndex] < pq[parentIndex]){
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[minChildIndex];
                pq[minChildIndex] = temp;
                                
            }else{  // parent is smaller than both of its child
                break;
            }
            parentIndex = minChildIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2;
        }
        return minElement;
    }
};