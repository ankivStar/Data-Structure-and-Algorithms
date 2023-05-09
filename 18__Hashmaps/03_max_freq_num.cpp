#include <iostream>
using namespace std;
#include <map>

int max_freq_num(int *a, int size){
    // unordered_map<int, int> hash;
    map<int, int> hash;
    for (int i = 0; i < size; i++){
        hash[a[i]]++;
    }

    int max_count = 0, res = -1;
    for (auto i : hash){
        if (max_count < i.second){
            res = i.first;
            max_count = i.second;
        }
    }

    // int max_count = 0, res = -1;
    // map<int, int> :: iterator it = hash.begin();
    // while (it != hash.end()){
    //     if (max_count < it->second){
    //         res = it->first;
    //         max_count = it->second;
    //     }
    //     it++;
    // }
    return res;
}

int main(){
    int size;
    cin >> size;
    int a[size];
    for (int i = 0; i < size; i++){
        cin >> a[i];
    }
    cout << max_freq_num(a, size);
    return 0;
}

/*
input
13
2 12 2 11 12 2 1 2 2 11 12 2 6
output
2

input
3
1 4 5
output
1
*/