#include <iostream>
using namespace std;

class ComplexNum
{
private :
    int real;
    int imaginary;

public :

    ComplexNum(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void print()
    {
        cout << real <<  " + " << imaginary << "i" << endl;
    }

    void plus(ComplexNum const &c2)
    {
        real = real + c2.real;
        imaginary = imaginary + c2.imaginary;
    }

    void multiply(ComplexNum const &c2)
    {
        real = real * c2.real;
        imaginary = imaginary * c2.imaginary;
    }
};