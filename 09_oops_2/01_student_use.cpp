#include <iostream>
#include <string.h>
using namespace std;

#include "00_shallow_and_deep_copy.cpp"

int main()
{
  char name[] = "abcd";
  Student s1(20,name);
  s1.display();

  name[3] = 'e';
  Student s2(24, name);
  s2.display();

  s1.display();  
return 0;
}