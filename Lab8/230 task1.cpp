#include<bits/stdc++.h>
using namespace std;

class Seat
{
private:
    string comfortability;
    bool seat_warmer;
public:
    Seat()
    {

    }
    Seat(string c, bool s):comfortability(c),seat_warmer(s)
    {

    }
    set_data(string c, bool s)
    {
        comfortability = c;
        seat_warmer = s;
    }
    string get_comfortability()const
    {
        return comfortability;
    }

    bool get_seatwarmer()const
    {
        return seat_warmer;
    }
    void display()const
    {
        cout<<"Seat information:\ncomfortability: "<<comfortability<<"\n";
        cout<<"Presence of Seat warmer: ";
        if(seat_warmer)
            cout<<"YES\n\n";
        else
            cout<<"NO\n\n";
    }

};

class Wheel
{
private:
    float radius;
public:
    Wheel(): radius(0)
    {

    }
    Wheel(float r): radius(r)
    {

    }
    void set_radius(float r)
    {
        radius = r;
    }
    float get_radius()const
    {
        return radius;
    }
    void display()const
    {
        cout<<"Wheel information:\nradius: "<<radius<<"\n\n";
    }
};

class Engine
{
private:
    float Max_Fuel_Con_Rate, Max_Energy_Pro_Rate, Avg_RPM;
public:
    Engine( ): Max_Fuel_Con_Rate(0), Max_Energy_Pro_Rate(0), Avg_RPM(0)
    {

    }
    Engine(float con, float pro, float rpm): Max_Fuel_Con_Rate(pro), Max_Energy_Pro_Rate(pro), Avg_RPM(rpm)
    {

    }
    void set_data(float con, float pro, float rpm)
    {
        Max_Fuel_Con_Rate = con;
        Max_Energy_Pro_Rate = pro;
        Avg_RPM = rpm;
    }
    float get_Max_Fuel_Con_Rate()const
    {
        return Max_Fuel_Con_Rate;
    }
    float get_Max_Energy_Pro_Rate()const
    {
        return Max_Energy_Pro_Rate;
    }
    float get_Avg_RPM()const
    {
        return Avg_RPM;
    }
    void display()const
    {
        cout<<"Engine information:\nMaximum Fuel Consumption Rate: " <<Max_Fuel_Con_Rate<<"\nMaximum Energy Prduction Rate: "<<Max_Energy_Pro_Rate<<"\nAverage RPM: "<<Avg_RPM<<"\n\n";
    }

};

class Door
{
private:
    string open_mode;
public:
    Door()
    {
        open_mode = "None";
    }
    Door(string s)
    {
        open_mode = s;
    }
    void set_open_mode(string s)
    {
        open_mode = s;
    }
    string get_open_mode()const
    {
        return open_mode;
    }
    void display()const
    {
        cout<<"Door information:\nOpen mode: "<<open_mode<<"\n";
    }
};

class Truck
{
private:
    Seat s[2];
    Wheel w[6];
    Engine e;
    Door d[2];
    float maximum_acceleration, fuel_capacity, Load_capacity;

public:
    Truck(float max_acc, float f_c, float l_c, string c, bool seat_warm, float r, float mfc, float mep, float avg, string opmode):maximum_acceleration(max_acc), fuel_capacity(f_c), Load_capacity(l_c)
    {
        for(int i=0; i<2; ++i)
        {
            s[i].set_data(c,seat_warm);
        }
        for(int i=0; i<6; ++i)
        {
            w[i].set_radius(r);
        }
         e.set_data(mfc,mep,avg);

        for(int i=0; i<2; ++i)
        {
            d[i].set_open_mode(opmode);
        }
    }

    set_info()
    {
        string str;
        float r,f1,f2,f3;
        bool a;
        cout<<"set seat comfortability: ";
        cin>>str;
        cout<<"set presence of seat warmer: ";
        cin>>a;
        for(int i=0; i<2; ++i)
        {
            s[i].set_data(str,a);
        }
        cout<<"set wheel radius: ";
        cin>>r;
        for(int i=0; i<6; ++i)
        {
            w[i].set_radius(r);
        }
        cout<<"set door open mode: ";
        cin>>str;
        for(int i=0; i<2; ++i)
        {
            d[i].set_open_mode(str);
        }

        cout<<"set engine info: \nMaximum Fuel Consumption Rate: ";
        cin>>f1;
        cout<<"Maximum Energy Prduction Rate: ";
        cin>>f2;
        cout<<"Average RPM: ";
        cin>>f3;
        e.set_data(f1,f2,f3);
    }

    void display()const
    {
        cout<<"Truck info:\n";
        s[0].display();
        w[0].display();
        e.display();
        d[0].display();
        cout<<"maximum acceleration: "<<maximum_acceleration<<"\nfuel_capacity: "<<fuel_capacity<<"\nLoad capacity: "<<Load_capacity<<"\n";
    }
};


int main()
{
    Truck t(1000,5000,400,"Pleasant",1,5.5,122,233,445,"Sideways");
    t.display();
}
