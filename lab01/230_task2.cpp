#include<bits/stdc++.h>
using namespace std;

class RationalNumber
{
private:

    int Numerator, Denominator;

public:

    void assign(int _numerator ,int denominator)
    {
        if(denominator == 0)
        {
            cout<<"Undefined\n";
            return;
        }
        Numerator =  numerator;
        Denominator = denominator;
    }
    double convert()
    {
        return (double)Numerator/(double)Denominator;
    }
    void invert()
    {
        if(Numerator  == 0)
        {
            cout<<"Undefined\n";
            return;
        }
        swap(Numerator, Denominator);
    }
    void print()
    {
        cout<<"The Rational Number is "<<Numerator<<"/"<<Denominator<<"\n";
    }

};

int main()
{
    RationalNumber r, p;
    p.assign(3,2);
    p.print();
    cout<<p.convert()<<"\n";

    p.invert();
    cout<<"After inverting  :\n";
    p.print();
    cout<<p.convert()<<"\n";

    r.assign(3,0);
    r.assign(0,3);
    r.invert();

}
