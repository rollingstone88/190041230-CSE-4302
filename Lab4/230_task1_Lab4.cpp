#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
private:
    long ac_no;
    float current_balance,min_balance;
    string name;
    string ac_type;

public:

    BankAccount(long no, float cur, float min, string ac_name, string type)
    {
        ac_no = no;
        current_balance = cur;
        min_balance = min;
        name = ac_name;
        ac_type = type;
    }

    setInfo(long no, float cur, float min, string ac_name, string type)
    {
        ac_no = no;
        current_balance = cur;
        min_balance = min;
        name = ac_name;
        ac_type = type;
    }
    showBalance()
    {
        cout<<"current balance : "<<current_balance<<"\n";
    }

    deposit(float val)
    {
        current_balance += val;
    }

    void withdrawal(float val)
    {
        if((current_balance-val)<min_balance)
        {
            cout<<"Insufficient balance\n";
            return;
        }
        current_balance -= val;
    }
    giveInterest(float percentage = 3)
    {
        float interest;
        interest = current_balance*percentage/100*0.9;
        current_balance += interest;
    }

    void display()
    {
        cout<<"account holder name: "<<name<<"\n";
        cout<<"account number : "<<ac_no<<"\n";
        cout<<"account type : "<<ac_type<<"\n";
        cout<<"current balance : "<<current_balance<<"\n";
        cout<<"minimum balance : "<<min_balance<<"\n";
    }

    ~BankAccount()
    {
        cout<<"Account of Mr. "<<name<<" with account no "<<ac_no<<" is destroyed with a balance BDT "<<current_balance<<"\n";

    }
};

int main()
{
BankAccount a(1234, 5000, 500, "Fairoz Anika","Current");
a.display();
a.deposit(500);
a.display();
a.withdrawal(23000);
a.giveInterest();
}
