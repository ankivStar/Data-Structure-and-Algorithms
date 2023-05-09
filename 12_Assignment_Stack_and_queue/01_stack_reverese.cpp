#include <iostream>
using namespace std;
#include<stack>

stack<int> reverse(stack<int> s1, stack<int> s2){
    if(s1.size() == 0 or s1.size() == 1){
        return s1;
    }

    int t = s1.top();
    s1.pop();

    stack<int> result = reverse(s1, s2);
    
    while (result.size() != 0){
        s2.push(result.top());
        result.pop();
        s1.pop();
    }

    s1.push(t);
    while(s2.size() != 0){
        s1.push(s2.top());
        s2.pop();
    }

    return s1;
}
int main()
{
    stack<int> s1;
    int n,element;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> element;
        s1.push(element);
    }
    stack<int> s2;

    s1 = reverse(s1, s2);
    for (int i = 0; i < n; i++){
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
    
return 0;
}