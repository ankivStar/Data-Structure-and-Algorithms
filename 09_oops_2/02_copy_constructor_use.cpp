#include <iostream>
#include <string.h>
using namespace std;
#include "02__copy_constructor.cpp"

int main()
{
    char name[] = "abcd";
    Student s1(20, name);
    s1.display();

    Student s2(s1);

    s2.name[0] = 'x';
    s1.display();
    s2.display();
    return 0;
}