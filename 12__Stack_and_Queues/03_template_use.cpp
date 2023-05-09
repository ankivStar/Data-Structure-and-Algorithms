#include <iostream>
using namespace std;
#include "03__Template.cpp"

int main()
{
    // both having same data type
     Pair <int ,int > p1;

    p1.setX(10);
    p1.setY(90);

    cout << p1.getX() << " " << p1.getY() << endl;

    //both having different datatype
    Pair<int, double> p2;

    p2.setX(20);
    p2.setY(30.67);

    cout << p2.getX() << " " << p2.getY() << endl;

    //triplet
    Pair<Pair<int, double>, char> p3;

    Pair <int , double> p4;

    p4.setX(40);
    p4.setY(50.897);

    p3.setX(p4);
    p3.setY('r');

    cout << p3.getX().getX() << " " << p3.getX().getY() << " " << p3.getY() << endl;

    return 0;
}