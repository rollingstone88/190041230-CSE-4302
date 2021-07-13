#include<bits/stdc++.h>
using namespace std;

class Coordinate
{
private:
    float abscissa, ordinate;

public:

    Coordinate():abscissa(0),ordinate(0)
    {

    }

    Coordinate(float x, float y):abscissa(x),ordinate(y)
    {

    }
    float getDistance(Coordinate c)
    {
        float dis;
        dis = sqrt(powl((abscissa - c.abscissa),2) + powl((ordinate - c.ordinate),2));
        return dis;
    }

    float getDistance()
    {
        float dis;
        dis = sqrt(abscissa*abscissa + ordinate*ordinate);
        return dis;
    }

    void move_x(float val)
    {
        abscissa +=val;

    }

    void move_y(float val)
    {
        ordinate += val;
    }

    void move(float val)
    {
        move_x(val);
        move_y(val);
    }

    void display() const
    {
        cout<<"Abscissa  : "<<abscissa<<"     ";
        cout<<"Ordinate  : "<<ordinate<<"\n";
    }

    bool operator > (Coordinate c)
    {
        return getDistance() > c.getDistance();
    }

    bool operator < (Coordinate c)
    {
        return getDistance() < c.getDistance();
    }

    bool operator >= (Coordinate c)
    {
        return getDistance() >= c.getDistance();
    }

    bool operator <= (Coordinate c)
    {
        return getDistance() <= c.getDistance();
    }

    bool operator == (Coordinate c)
    {
        return getDistance() == c.getDistance();
    }

    bool operator != (Coordinate c)
    {
        return getDistance() != c.getDistance();
    }

    void operator ++()
    {
        ++abscissa;
        ++ordinate;
    }
    void operator ++(int)
    {
        abscissa++;
        ordinate++;
    }
    void operator --()
    {
        --abscissa;
        --ordinate;
    }
    void operator --(int)
    {
        abscissa--;
        ordinate--;
    }
    ~Coordinate()
    {

    }
};

int main()
{
    Coordinate a,b(1,1),c(-1,-1),d;
    cout<<"Distance of b = "<<b.getDistance()<<"\n";
    cout<<"Distance between b and c = "<<b.getDistance(c)<<"\n";

    a.move_x(2);
    cout<<"coordinates of a: ";
    a.display();
    if(b == c)
        cout<<" b == c \n";

    if(a < b)
        cout<<"  a<b \n";
    if(a > b)
        cout<<"  a>b\n";
    if(a != c)
        cout<<" a != c \n";

    ++d;
    cout<<"(after ++d) coordinates of d: ";
    d.display();
    d.move_y(2);
    cout<<"(after d.move(_y2)) coordinates of d: ";
    d.display();
    d--;
    cout<<"(after d--) coordinates of d: ";
    d.display();

    d.move(2);
    cout<<"(after d.move(2)) coordinates of d: ";
    d.display();


}
