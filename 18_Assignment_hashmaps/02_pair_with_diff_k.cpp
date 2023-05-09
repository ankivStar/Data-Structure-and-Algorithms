#include <iostream>
using namespace std;
#include <map>
#include <unordered_map>

int pairWithDiffK(int *a, int size, int k){
    if (size == 0) return 0;

    unordered_map<int, int> elements;

    for(int i = 0; i < size; i++){
        elements[a[i]]++;
    }

    int ans = 0;
    if (k == 0){
        for (auto i : elements){
            int num = i.second-1;
            ans += num * (num + 1) / 2;
        } 
        return ans;
    }

    for (auto i : elements){
        int num = i.first;
        if(elements.count(num-k) > 0) ans += (i.second * elements[num-k]);
        if(elements.count(num+k) > 0) ans += (i.second * elements[num+k]);
        elements[num] = 0;
    }
    return ans;
}

int main(){
    int size;
    cin >> size;
    int a[size];
    for (int i = 0; i < size; i++){
        cin >> a[i];
    }

    int k; 
    cin >> k;
    cout << pairWithDiffK(a, size, k) << endl;
    return 0;
}

/*
input
4
5 1 2 4
3
output
2

input
4
4 4 4 4
0
output
6
*/