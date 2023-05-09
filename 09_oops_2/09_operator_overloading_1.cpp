#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print()
    {
        cout << this->numerator << " / " << denominator << endl;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(numerator, denominator);
        for (int i = 2; i <= j; i++)
        {
            if (numerator % i == 0 and denominator % i == 0)
            {
                gcd = i;
            }
        }

        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }

    Fraction add(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int sum = (x * numerator) + (y * f2.numerator);

        // numerator = sum;
        // denominator = lcm;

        Fraction fnew(sum, lcm);
        fnew.simplify();
        return fnew;
    }

    // operator overloading
    Fraction operator+(Fraction const &f2) const
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int sum = (x * numerator) + (y * f2.numerator);

        Fraction fnew(sum, lcm);
        fnew.simplify();
        return fnew;
    }

    Fraction operator*(Fraction const &f2) const
    {
        int numera = numerator * f2.numerator;
        int denomina = denominator * f2.denominator;

        Fraction fnew(numera, denomina);
        fnew.simplify();
        return fnew;

        fnew.simplify();
    }

    bool operator==(Fraction const &f2) const
    {
        return (numerator == f2.numerator and denominator == f2.denominator);
    }
};

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    Fraction f3 = f1.add(f2);
    Fraction f4 = f1 + f2;
    Fraction f5 = f1 * f2;

    f1.print();
    f2.print();
    f3.print();
    f4.print();
    f5.print();

    if(f1 == f2)
    {
        cout << "Equal" << endl;
    }
    else{
        cout << "Not Equal" << endl;
    }

    return 0;
}