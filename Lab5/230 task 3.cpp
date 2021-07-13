#include<bits/stdc++.h>
using namespace std;

class FLOAT
{
private:
    float data;
public:
    FLOAT(float d):data(d)
    {

    }

    FLOAT operator + (FLOAT f1)
    {
        return FLOAT(data + f1.data);
    }

    FLOAT operator - (FLOAT f1)
    {
        return FLOAT(data - f1.data);
    }

    FLOAT operator * (FLOAT f1)
    {
        return FLOAT(data * f1.data);
    }

    FLOAT operator / (FLOAT f1)
    {
        if(f1.data == 0)
        {
            cout<<"Infinity\n";
        }
        else
            return FLOAT(data / f1.data);
    }

    void display() const
    {
        cout<<data<<"\n";
    }

    ~FLOAT()
    {

    }
};

int main()
{
    FLOAT f(1.5),f1(2.3), f2(3.4), f3(0);
    f.display();
    f = f1 + f2;
    f.display();
    f = f1 - f2;
    f.display();
    f = f1 * f2;
    f.display();
    f = f1 / f2;
    f.display();
    f = f1 / f3;
}
