class Intialise
{
public:
    int age;
    const int rollNumber;
    int &x; // age reference variable

    Intialise(int age, int r) : rollNumber(r), age(age), x(this->age)
    {
    }
};