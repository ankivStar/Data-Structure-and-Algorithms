#include <iostream>
using namespace std;

class Polynomial
{
    int *degCoeff;
    int capacity;

public:
    Polynomial() /// default constructor to initialise degCoeff with 0
    {
        degCoeff = new int[7];
        capacity = 7;

        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = 0;
        }
    }

    Polynomial(Polynomial const &p) // copy constructor for deep copy
    {
        this->degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }

    void operator=(Polynomial const &p) // copy assignment opertor fn. to deep copy
    {
        this->degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }

    void setCoefficient(int deg, int coeff)
    {
        if (deg >= capacity)
        {
            int *pnew = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                pnew[i] = degCoeff[i];
            }

            delete[] degCoeff;
            degCoeff = pnew;
            capacity *= 2;
            setCoefficient(deg, coeff);
        }
        
        else
        {
            degCoeff[deg] = coeff;
        }
    }

    void print() const
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degCoeff[i] > 0 and i != 0)
            {
                cout << " + " << degCoeff[i] << "X^" << i;
            }

            else if (degCoeff[i] < 0)
            {
                cout << degCoeff[i] << "X^" << i;
            }

            else if (i == 0 and degCoeff[i] != 0)
            {
                cout << degCoeff[i] << "X^" << i;
            }
            else
            {
            }
        }

        cout << endl;
    }

    Polynomial operator+(Polynomial const &p) // to perform p3 = p1 + p2
    {
        Polynomial pNew;
        for (int i = 0; i < capacity; i++)
        {
            int sum = this->degCoeff[i] + p.degCoeff[i];
            pNew.setCoefficient(i, sum);
        }

        return pNew;
    }

    Polynomial operator-(Polynomial const &p) // to perform p3 = p1 - p2
    {
        Polynomial pNew;
        for (int i = 0; i < capacity; i++)
        {
            pNew.degCoeff[i] = this->degCoeff[i] - p.degCoeff[i];
        }

        return pNew;
    }
};

int main()
{
    Polynomial p1;

    p1.setCoefficient(0, 3);
    p1.setCoefficient(2, 4);
    p1.setCoefficient(5, -2);

    Polynomial p2;

    p2.setCoefficient(1, -1);
    p2.setCoefficient(2, 1);
    p2.setCoefficient(3, 1);
    p2.setCoefficient(4, 1);

    Polynomial p3 = p1 + p2;

    p1.print();
    p2.print();
    p3.print();

    return 0;
}