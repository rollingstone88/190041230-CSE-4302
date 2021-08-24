#include<bits/stdc++.h>
using namespace std;

class RacingCar
{
private:
    static int TotalCars;
    const int CarNo;
    double maxSpeed;
    double distance;

public:
    RacingCar():CarNo(++TotalCars) {}
    RacingCar(double speed):CarNo(++TotalCars)
    {
        distance = 0;
        maxSpeed = speed;
    }

    RacingCar(const RacingCar& r):CarNo(++TotalCars) /// constructor increments static member variable TotalCars which keep a count of the total cars. Here we need to write our own copy constructor
    {
        /// because default copy constructor will not increment the static member TotalCars, it will only copy the data members
        /// but here only speed is required to be copied and TotalCars static variable to be incremented then assigned to CarNo so copy constructor will be overloaded
        distance = 0;
        maxSpeed = r.maxSpeed;
    }
    void operator = (const RacingCar& r) /// we need to write our own assignments operator because compiler will not create a default assignment operator
    {
        /// as RacingCar class has a non-static data member CarNo of const type
        distance = 0;
        maxSpeed = r.maxSpeed;
    }

    void advance(double t)
    {
        distance += maxSpeed*t;
    }

    double GetCurDistance()const
    {
        return distance;
    }

    double GetMaxSpeed()const
    {
        return maxSpeed;
    }
    int getcarNo()const
    {
        return CarNo;
    }
};

int RacingCar::TotalCars = 0;

class Track
{
private:
    float tracklength;
    RacingCar* car;                 /// Track class has a pointer to a RacingCar object
    Track(const Track& t);
    Track operator =(const Track& t);

public:
    Track()
    {

    }
    Track(float l):tracklength(l)
    {

    }
    setRacingcarptr(const RacingCar& c)
    {
        *car = c;
    }
    setTrackLength(float f)
    {
        tracklength = f;
    }
};

int main()
{
    RacingCar a(125);
    RacingCar b = a; /// using overloaded copy constructor
    RacingCar c;
    c = a; /// using overloaded assignment operator
    cout<<"car c speed : "<<c.GetMaxSpeed()<<"\nCar No: "<<c.getcarNo()<<"\n";
    cout<<"car b speed : "<<b.GetMaxSpeed()<<"\nCar No: "<<b.getcarNo()<<"\n";

    /**
     To restrict a class from copying from one object to another we need to make the copy constructor and assignment operator private.
     Track t1, t2;
     t1 = t2;
     t2.setRacingcarptr(a);  This will also change the RacingCar pointer of Track object t1. So to restrict copying track objects the copy constructor and assignment operator has been declared
     in the private  section.
     */

}
