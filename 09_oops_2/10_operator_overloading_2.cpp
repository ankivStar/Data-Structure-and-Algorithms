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

    // pre increament;
    //  void operator++()
    //  {
    //      numerator = numerator + denominator;
    //      simplify();
    //  }

    Fraction &operator++()
    {
        numerator = numerator + denominator;
        simplify();

        return *this;
    }

    // post increament
    Fraction operator++(int)
    {
        Fraction fnew(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        fnew.simplify();

        return fnew;
    }

    //+= operator
    Fraction &operator+=(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int sum = (x * numerator) + (y * f2.numerator);

        numerator = sum;
        denominator = lcm;

        simplify();
        return *this;
    }
};

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    // pre increament

    // f1.print();
    // ++f1;
    // f1.print();

    // Fraction f3 = ++f1;
    // f3.print();

    // Fraction f4 = ++(++f1);
    // f4.print();
    // f1.print();

    // post increament

    // f1.print();
    // Fraction f5 = f1++;
    // f5.print();
    // f1.print();

    f1.print();
    f2.print();
    (f1 += f2) += f2;
    f1.print();
    return 0;
}