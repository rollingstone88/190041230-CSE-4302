#include<bits/stdc++.h>
using namespace std;

class HospitalStaff
{
private:
    string staffName;
    int ID;
    int age;
public:
    HospitalStaff(string str,int i,int a):staffName(str),ID(i),age(a)
    {

    }
    string getName()
    {
        return staffName;
    }
    int getstaffID()
    {
        return ID;
    }
    int getstaffage()
    {
        return age;
    }
    virtual void staffInfo()=0;  /// In HospitalStaff class staffInfo() is a pure virtual function as it has no definition in the base class HospitalStaff making the base class an abstract class so
    /// no object can be created of the HospitalStaff class. Here pure virtual function is declared by assigning 0 in the declaration.
};

class Doctor : public HospitalStaff
{
private:
    string Specialization;
    string AcademicQualification;
public:
    Doctor(string str,int i,int a, string sp, string ac ):HospitalStaff(str,i,a),Specialization(sp),AcademicQualification(ac)
    {

    }
    string getSpecialization()
    {
        return Specialization;
    }
    string getAcademicQualification()
    {
        return AcademicQualification;
    }
    virtual void Status() /// status function is made virtual as it has different functionalities in derived classes but it has a definition of its own class. This Virtual functions do not make base
    {
        /// class abstract as it has its own definition in the base class
        cout<<"Status: Physician\n";
        cout<<"Specialization: "<<Specialization<<"\nAcademic Qualification:"<<AcademicQualification<<"\n";
    }
    void staffInfo() /// All derived class must redefine pure virtual function of base class otherwise derived class also becomes abstract just like base class.Here the StaffInfo function is
    /// overridden in the derived class Doctor. if pure virtual Function is called without being overridden it will give compilation error
    {
        cout<<"Doctor Info:\nName : "<<getName()<<"\nID : "<<getstaffID()<<"\nAge: "<<getstaffage()<<"\nSpecialization: "<<Specialization<<"\nAcademic Qualification:"<<AcademicQualification<<"\n\n";

    }
};

class Nurse : public HospitalStaff
{
private:
    bool registeredStatus;
public:
    Nurse(string str,int i,int a,bool l):HospitalStaff(str,i,a),registeredStatus(l)
    {

    }

    bool getregisteredStatus()const
    {
        return registeredStatus;
    }

    void staffInfo() ///Here the StaffInfo function is overridden in the derived class Nurse
    {
        cout<<"Nurse Info:\nName : "<<getName()<<"\nID : "<<getstaffID()<<"\nAge: "<<getstaffage()<<"\nstatus: ";
        if(registeredStatus == 1)
            cout<<"Registered Nurse\n\n";
        else
            cout<<"Licensed Practical Nurse\n\n";
    }
};

class Receptionist : public HospitalStaff
{
private:
    int salary;
    int workingHour;
public:
    Receptionist(string str,int i,int a,int sal,int wh):HospitalStaff(str,i,a),salary(sal),workingHour(wh)
    {

    }
    int getSalary()
    {
        return salary;
    }
    int getworkingHour()
    {
        return workingHour;
    }
    void staffInfo() ///Here the StaffInfo function is overridden in the derived class Receptionist
    {
        cout<<"Receptionist Info:\nName : "<<getName()<<"\nID : "<<getstaffID()<<"\nAge: "<<getstaffage()<<"\nsalary: "<<salary<<"\nWorking Hour:"<<workingHour<<"\n\n";

    }

};

class Intern : public Doctor
{
private:
    int internshipYear;
public:
    Intern(string str,int i,int a, string sp, string ac, int year):Doctor(str,i,a,sp,ac),internshipYear(year)
    {

    }

    int getinternshipYear() ///Here the getinternshipYear function is overridden in the derived class Intern
    {
        return internshipYear;
    }
    void Status()
    {
        cout<<"Status: Intern\nInternshipYear: "<<internshipYear<<"\n";
        cout<<"Specialization: "<<getSpecialization()<<"\nAcademic Qualification:"<<getAcademicQualification()<<"\n\n";
    }
    void Specialization_field()
    {

    }
};

int main()
{
/// HospitalStaff h; cannot initialize base class object as abstract class;
    HospitalStaff *s[3]; ///When we refer to a derived class object using a pointer or a reference to the base class,
    ///we can call a virtual function for that object and execute the derived class’s version of the function.
    Doctor *d;
    s[0] = new Doctor("Jamila Rahman",123,25,"Medicine","Master of Medicine (MMed)"); /// can initialize base class object
    s[0]->staffInfo();
    d = new Intern("Amina Rahman",345,25,"Medicine","Bachelor of Medicine (B.Med)",2);
    d->Status();
    s[1] = new Nurse("Ms. Jane",576,22,1);
    s[2] = new Receptionist("Sara",180,23,12000,4);
    s[1]->staffInfo();
    s[2]->staffInfo();
    delete s[0];
    delete s[1];
    delete s[2];
    delete d;
}

