#include <iostream>
using namespace std;
#include <map>
#include <unordered_map>

//fun to return length of longest subset whose sum = 0
int lengthOfLongestSubset(int *a, int size){
    unordered_map<int, int> sumIndex;
    int maxLen = 0;
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += a[i];
        if (sumIndex.count(sum)>0) maxLen = max(maxLen, i - sumIndex[sum]);
        else sumIndex[sum] = i;
        if (sum == 0) maxLen = max(maxLen, i + 1);
    }
    return maxLen;
}

int main(){
    int size;
    cin >> size;
    int a[size];
    for (int i = 0; i < size; i++){
        cin >> a[i];
    }
    cout << lengthOfLongestSubset(a, size);
    return 0;
}

/*
input
10
95 -97 -387 -435 -5 -70 897 127 23 284
output
5

input
6
6 1 5 -8 -4 2
output
5

input
18
0 1 37 0 -38 15 24 -40 41 -40 36 -36 20 0 -20 8 46 49
output
15
*/