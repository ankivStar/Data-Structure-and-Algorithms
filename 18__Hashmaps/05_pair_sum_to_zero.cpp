#include <iostream>
using namespace std;
#include <unordered_map>

int pairSumToZero(int *a, int size){
    unordered_map<int, int> pairSum;
    for (int i = 0; i < size; i++){
        pairSum[a[i]]++;
    }

    int count = 0;
    // for (auto i : pairSum){
    //     if(i.first and pairSum.count(-(i.first)) > 0 and pairSum[-i.first] > 0 and i.second > 0){
    //         count += pairSum[-i.first] * pairSum[i.first];
    //         cout << count << endl;
    //         pairSum[i.first] = 0;
    //         pairSum[-i.first] = 0;
    //     }if(i.first==0 and pairSum[i.first]>1)
    //         int zeroFreq = pairSum[i.first];
    //         count += (zeroFreq * (zeroFreq - 1)) / 2;
    //         pairSum[i.first] = 0;
    //     }
    // }
    // return count;


     for (int i = 0; i < size; i++){
        int num = a[i];
        if (num and pairSum.count(-num) > 0 and pairSum[-num] > 0 and pairSum[num] > 0){
            count += pairSum[-num]*pairSum[num];
            pairSum[num] = 0;
            pairSum[-num] = 0;
        }if(num==0 and pairSum[num]>1){
            int zeroFreq = pairSum[num];
            count += (zeroFreq * (zeroFreq - 1)) / 2;
            pairSum[num] = 0;
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << pairSumToZero(a, n) << endl;

    return 0;
}

/*
input
5
2 1 -2 2 3
output
2

input
10
1 2 3 4 5 -5 -6 -7 -8 -1
output
2

input
6
2 1 -2 2 -2 3
output
4

input
16
3 1 3 -4 -1 2 -5 5 -2 -1 3 -2 -4 -2 0 5
output
7

input
14
-4 1 -4 5 5 4 -1 0 5 -5 0 5 -4 3
output
9

input
11
0 2 -4 1 -1 2 -3 1 -2 -1 2
output
7
*/