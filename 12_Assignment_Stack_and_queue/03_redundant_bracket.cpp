#include <iostream>
using namespace std;
#include <stack>

bool redundant(string str){
    stack<char> s;
    for (int i = 0; i < str.length(); i++){
        if(str[i] != ')'){
            s.push(str[i]);
        }
        else{
            int count = 0;
            char c;
            
            while (s.top() != '('){
                c = s.top(); 
                count++;
                s.pop();
            }

            s.pop();
            if(count == 0 or (count == 1 and c >= 97 and c <= 122))
            return true;
        }
    }
    return false;
}

int main()
{
    string str;
    cin >> str;

    cout << redundant(str);
return 0;
}