#include <vector>
class MaxPriorityQueue{
    vector<int> pq;

    public :
    MaxPriorityQueue(){

    }

    bool isEmpty(){
        return pq.empty();
    }

    int getSize(){
        return pq.size();
    }

    int getMax(){
        if (isEmpty()) return INT_MAX;
        return pq[0];
    }

    void insert(int val){
        pq.push_back(val);

        int childIndex = pq.size() - 1;
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

    int removeMax(){
        if (isEmpty()) return INT_MAX;

        int maxElement = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < pq.size()){
            int maxChildIndex = parentIndex;

            //calculating max child index
            if (rightChildIndex < pq.size() and pq[leftChildIndex] < pq[rightChildIndex]){
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
        return maxElement;
    }
};