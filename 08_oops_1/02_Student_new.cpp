#include <iostream>
using namespace std;
#include "00_Student.cpp"

int main()
{
    Student s1;
    s1.setAge(20);
    s1.display();

    Student *s2 = new Student;
    s2->setAge(24);
    s2->display();

    return 0;
}