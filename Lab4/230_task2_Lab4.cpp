#include<bits/stdc++.h>
using namespace std;

class Rectangle
{
private:
    float length,width;

public:
    Rectangle(float len = 1, float wid = 1):length(len),width(wid)
    {

    }
    void setData(float len, float wid)
    {
        if(len>= 20 or len<1 or wid>= 20 or wid<1)
        {
            cout<<"Invalid data\n";
            return;
        }
        length = len;
        width = wid;
    }
    float getLength()
    {
        return length;
    }
    float getWidth()
    {
        return width;
    }
    float calcPerimeter()
    {
        float perimeter;
        perimeter = 2*(length + width);
        return perimeter;
    }
    float calcArea()
    {
        float area;
        area = length*width;
        return area;
    }
    float calcDiagonal()
    {
        float diagonal;
        diagonal = sqrt(length*length + width*width);
        return diagonal;
    }
    calcAngle()
    {
        float angle, d;
        d = calcDiagonal();
        angle = acos((float)(length/d));
        return angle;
    }
};

int main()
{
    Rectangle a, b(1,2);
    cout<<a.getLength()<<" "<<a.getWidth()<<"\n";
    cout<<"perimeter: "<<b.calcPerimeter()<<"\n";
    cout<<"area: "<<b.calcArea()<<"\n";
    cout<<"diagonal: "<<b.calcDiagonal()<<"\n";
    cout<<"angle: (in radiun) "<<b.calcAngle()<<"\n";
    a.setData(2,20.5);
    a.setData(0,3);
}
