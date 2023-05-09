#include <iostream>
using namespace std;
#include "07__static_member.cpp"

int main()
{
    Static s1;
    cout << s1.age << " " << s1.rollNumber << endl;
    cout << Static ::totalStudent << endl;
    return 0;
}