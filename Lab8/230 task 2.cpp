#include<bits/stdc++.h>
using namespace std;

class Staff
{
private:
    int code;
    string name;
protected:
    void whoAmI()const  // This is a dummy function to show the effect of inheritance and access specifier
    {
        cout<<"I am a staff\n";
    }

public:
    Staff(int c, string s):code(c),  name(s)
    {

    }
    set_data(int c, string s)
    {
        code=c;
        name = s;
    }
    string get_name()const
    {
        return name;
    }
    int get_code()const
    {
        return code;
    }

    void display()const
    {
        cout<<"About staff:\nName\tcode\n"<<name<<"\t"<<code<<"\n";
    }

};

class Teacher : public Staff
{
private:
    string subject, publication;


protected:
    void whoAmI()const
    {
        cout<<"I am a teacher - staff\n";
        // cout<<name;    //cannot access private member name
        Staff::whoAmI(); //can access protected members of base class in derived class
        Staff::display(); //can access public members of base class in derived class
    }

public:
    Teacher( string str,int c,string s,string p):Staff(c,str)
    {
        subject = s;
        publication = p;
    }
    void set_data(string s, string p)
    {
        subject = s;
        publication = p;
    }
    string get_subject()const
    {
        return subject;
    }
    string get_publication()const
    {
        return publication;
    }

    void display()const
    {
        cout<<"About teacher:\nName\tcode\tsubject        \tpublication\n"<<get_name()<<"\t"<<get_code()<<"\t"<<subject<<"\t"<<publication<<"\n";
    }
};

class typist : protected Staff
{
private:
    float speed;

protected:
    void whoAmI()const
    {
        cout<<"I am a typist - staff\n";
    }
public:
    typist(string str,int c,float s):Staff(c,str),speed(s)
    {

    }
    void set_speed(float s)
    {
        speed = s;
    }
    float get_speed()const
    {
        return speed;
    }

    void display()const
    {
        cout<<"About typist :\nName\tcode\tspeed\n"<<get_name()<<"\t"<<get_code()<<"\t"<<get_speed()<<"\n";
    }
};

class officer : private Staff
{
private:
    string grade;
public:
    officer(string str, int c, string s):Staff(c,str)
    {
        grade = s;
    }
    void set_grade(string g)
    {
        grade = g;
    }
    string get_grade()const
    {
        return grade;
    }
    void whoAmI()const
    {
        cout<<"I am an officer - staff\n";
    }
    void display()const
    {
        cout<<"About officer:\nName\tcode\tgrade\n"<<get_name()<<"\t"<<get_code()<<"\t"<<grade<<"\n";
    }
};

class regular : public typist
{
private:
    float wage;

public:
    regular(string str, int c, float s, float g):typist(str,c,s),wage(g)
    {

    }
    void set_wage(float w)
    {
        wage = w;
    }
    float get_wage()const
    {
        return wage;
    }
    void whoAmI()const
    {
        cout<<"I am a regular - typist - staff\n";
       // Staff::whoAmI(); // as typist is inherited privately from Staff class protected member whoAmI() is private for typist class hence cannot be accessed from outside of base or derived class definition
        //  cout<<get_name(); // as typist is inherited privately from Staff class public member get_name() is private for typist class hence cannot be accessed from outside of class definition
    }
    void display()const
    {
        cout<<"About regular typist :\nName\tcode\tspeed\twage\n"<<get_name()<<"\t"<<get_code()<<"\t"<<get_speed()<<"\t"<<wage<<"\n";
    }
};

class casual : public typist
{
private:
    float daily_wage;

public:
    casual(string str, int c, float s, float g):typist(str,c,s),daily_wage(g)
    {

    }
    void set_wage(float w)
    {
        daily_wage = w;
    }
    float get_wage()const
    {
        return daily_wage;
    }
    void whoAmI()const
    {
        cout<<"I am a casual - typist - staff\n";
    }
    void display()const
    {
        cout<<"About casual typist :\nName\tcode\tspeed\twage\n"<<get_name()<<"\t"<<get_code()<<"\t"<<get_speed()<<"\t"<<daily_wage<<"\n";
    }
};


int main()
{
    Staff s(1234,"Arik") ;
    s.display();
    Teacher t("Ataur",420,"programming with c++","Tata McGraw Hill");
    t.display();
    officer o("Md. Rashad",222,"First class");
    o.display();
    regular r("Robiul Awal", 333, 85.5,15000);
    r.display();
    casual c("Kawser Ahmed", 345,78.8,10000);
    c.display();
  //  t.Staff::whoAmI(); //cannot access protected members outside base class or derived class for public inheritance
    t.Staff::display();  // can access public members of base class from outside as they are inherited publicly
    typist temp("Kalam",220,1234);
    // temp.Staff::display(); cannot access public members of base class outside base or derived class for protected inheritance as they will be protected members for the derived class
    // temp.Staff::whoAmI();  cannot access protected members of base class outside base or derived class for protected inheritance as they will be protected members for the derived class



}
