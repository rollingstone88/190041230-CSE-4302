#include<bits/stdc++.h>
using namespace std;

class Medicine
{
private:
    char Name[100], GenericName[100];
    double discountPercent, unitPrice;

public:
    Medicine()
    {
        unitPrice = 0;
        discountPercent = 5;
    }
    void assignName(char* name, char* genericName)
    {
        strcpy(Name,name);
        //GenericName = genericName;
    }

    void assignPrice(double price)
    {
        if(price<0)
        {
            cout<<"Price needs to be non-negative.\n";
            return;
        }
        unitPrice = price;
    }
    void setDiscountPercent(double percent)
    {
        if(percent<0 or percent>45)
        {
            cout<<"discountPercent needs to be within 0-45%\n";
            return;
        }
        discountPercent = percent;
    }
    double getSellingPrice(int nos)
    {

        return nos*unitPrice*(1 - discountPercent/100);
    }
    void display()
    {
        cout<<Name<<" ("<<GenericName<<") has a unit price BDT "<<unitPrice<<" Current discount "<<discountPercent<<"%\n";
    }

};
int f()
{
    char s2[]="Napa";

}

int main()
{
    Medicine one, two, three;
    one.assignName("Napa", "Paracetamol");
    one.assignPrice(0.80);
    one.setDiscountPercent(10);
    one.display();
    cout<<"price of 3 unit of Napa "<<one.getSellingPrice(3)<<"\n";
    two.assignName("Aspirin", "Paracetamol");
    two.assignPrice(2.25);
    two.setDiscountPercent(5);
    two.display();
    cout<<"price of 5 unit of Aspirin "<<two.getSellingPrice(5)<<"\n";
    three.assignPrice(-1);
    three.setDiscountPercent(50);
}
