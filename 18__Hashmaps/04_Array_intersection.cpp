#include <iostream>
using namespace std;
#include<map>
#include<vector>
#include<unordered_map>

void input(int *a, int size){
    for (int i = 0; i < size; i++){
        cin >> a[i];
    }
}

void arrayIntersection(int *a1,int size1, int *a2, int size2){
    map<int, int> m;
    //unordered_map<int, int> m;
    //vector<int> v;
    for (int i = 0; i < size1; i++){
        m[a1[i]]++;
    }
    for (int i = 0; i < size2; i++){
        if (m.count(a2[i]) > 0 and m[a2[i]] > 0){
            cout << m.find(a2[i])->first << " ";
            m[a2[i]]--;
        }
    }
    cout << endl;
}
int main(){
    int size1;
    cin >> size1;
    int a1[size1];
    input(a1, size1);
    int size2;
    cin >> size2;
    int a2[size2];
    input(a2, size2);

    arrayIntersection(a1, size1, a2, size2);
    return 0;
}

/*
input
6
2 6 8 5 4 3
4 
2 3 4 7
output
2 3 4

input
4
2 6 1 2
5 
1 2 3 4 2
output
1 2 2
*/