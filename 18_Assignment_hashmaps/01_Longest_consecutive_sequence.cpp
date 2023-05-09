#include <iostream>
using namespace std;
#include <unordered_map>
#include <map>

pair<int, int> longestConsSubSeq(int a[], int size){
    
    unordered_map<int, bool> subSeq;
    // map<int, bool> subSeq;
    for (int i = 0; i < size; i++){
        subSeq[a[i]] = true;
    }

    unordered_map<int, int> order;
    // map<int, int> order;
    for (int i = 0; i < size; i++){
        order[a[i]] = i;
    }

    int ans = 0;
    pair<int, int> output;
   
    for (auto i : subSeq){
        int low = i.first;
        int high = i.first;
        int count = 1;
        pair<int, int> temp(low, high);

        while (i.second){  
            if (subSeq.count(high+1) > 0 or subSeq.count(low-1) > 0){
                if (subSeq.count(high+1) > 0 and subSeq[high+1]){
                    count++;
                    subSeq[high+1] = false;
                    high = high+1;
                    temp.second = high;
                }
                if (subSeq.count(low-1) > 0 and subSeq[low-1]){
                    count++;
                    subSeq[low-1] = false;
                    low = low - 1;
                    temp.first = low;
                }
            }
            else{
                i.second = false;
            }
        }

        if (count > ans or (count == ans and order[temp.first] < order[output.first])){
            output = temp;
            ans = count;
        }
    }
    return output;
}

int main(){
    int size;
    cin >> size;
    int a[size];
    for (int i = 0; i < size; i++){
        cin >> a[i];
    }

    pair<int, int> output = longestConsSubSeq(a, size);
    cout << output.first << " " << output.second << endl;

    return 0;
}

/*
input
10
9 1 8 6 3 4 2 7 10 15
output(it contain only first and last element of longestConseSubSeq)
6 10

input
13
2 12 9 16 10 5 3 20 25 11 1 8 6
output(longestConseSubSeq = {8 9 10 11 12})
8 12

input
7
3 7 2 1 9 8 41
output(longestConseSubSeq = {1 2 3} and {7 8 9} but Index of 7 is lessthan 1)
7 9

input
7
15 24 23 12 19 11 16
output
15 16
*/