#include <iostream>
using namespace std;
#include "00_Student.cpp"

int main()
{
    // create object statically
    Student s1;
    Student s2;
    Student s3;

    s1.rollNumber = 101;
    //s1.age = 21;

    cout << "RollNum = " << s1.rollNumber << endl;
    cout << "age = " << s1.getAge() << endl;

    s1.display();

    // create object dynamically
    Student * s4 = new Student;

    (*s4).rollNumber = 201; // or s4 -> rollNumber = 201
    //(*s4).age = 20;

    // cout << "RollNum = " << (*s4).rollNumber << endl;
    //cout << "age = " << (*s4).age << endl;
    
    s4 -> display();
return 0;
}