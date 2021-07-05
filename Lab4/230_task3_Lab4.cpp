#include<bits/stdc++.h>
using namespace std;

class employee
{
private:
    string EmpName;
    int ID, Age;
    float Salary;
    string getStatus()
    {
        string s;

        if(Age<=25)
        {
            if(Salary<=20000)
                s = "Low";
            else if(Salary>20000)
                s = "Moderate";
        }
        else if(Age>25)
        {
            if(Salary<=21000)
                s = "Low";

            else if(Salary>21000 and Salary<=600000)
                s = "Moderate";

            else if(Salary>60000)
                s = "High";
        }
        return s;
    }

public:
    FeedInfo()
    {
        cout<<"Enter Employee Name: ";
        cin>>EmpName;
        cout<<"Enter ID: ";
        cin>>ID;
        cout<<"Enter Age : ";
        cin>>Age;
        cout<<"Enter Salary :";
        cin>>Salary;
    }

    ShowInfo()
    {
        cout<<"Employee Name: "<<EmpName<<"\n";
        cout<<"ID: "<<ID<<"\n";
        cout<<"Salary : "<<Salary<<"\n";
        cout<<"Age : "<<Age<<"\n";
        cout<<"status : "<<getStatus()<<" Salaried Person\n";
    }
};

int main()
{
employee a;
a.FeedInfo();
a.ShowInfo();
}
