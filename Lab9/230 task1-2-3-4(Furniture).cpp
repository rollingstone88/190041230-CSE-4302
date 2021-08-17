#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
public:

    Furniture(double p,double d,Material m):price(0),discount(0),madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    double getPrice()const
    {
        return price;
    }
    double getDiscountedPrice()
    {
        double discountedPrice;
        discountedPrice = price - discount;
        return discountedPrice;
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    virtual void productDetails()=0;
};

enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
private:
    BedSize bedsz;
    string productName;
public:
    Bed(double p,double d,Material m, BedSize b):Furniture(p,d,m),bedsz(b),productName("Bed")
    {

    }
    string getBedSize()const
    {
        if(bedsz==BedSize::Single)
            return string("Single");
        else if(bedsz==BedSize::SemiDouble)
            return string("SemiDouble");
        else if(bedsz==BedSize::Double)
            return string("Double");
        else
            return string("");
    }
    void productDetails()
    {
        cout<<"---------------------------------------------\n";
        cout<<"Product Name: "<<productName<<"\nRegular Price: "<<price<<"\nDiscounted Price: "<<getDiscountedPrice()<<"\nMaterial: "<<getMadeof()<<"\nBed Size: "<<getBedSize()<<"\n";
        cout<<"#############################################################################\n\n";
    }
};

enum class SeatNumer {One, Two, Three, Four, Five};

class Sofa:public Furniture
{
private:
    SeatNumer seatno;
    string productName;

public:
    Sofa(double p,double d,Material m,SeatNumer s):Furniture(p,d,m),seatno(s),productName("Sofa")
    {

    }
    string getSeatNumber()const
    {
        if(seatno==SeatNumer::One)
            return string("One");
        else if(seatno==SeatNumer::Two)
            return string("Two");
        else if(seatno==SeatNumer::Three)
            return string("Double");
        else if(seatno==SeatNumer::Four)
            return string("Double");
        else if(seatno==SeatNumer::Five)
            return string("Five");
        else
            return string("");
    }

    void productDetails()
    {
        cout<<"---------------------------------------------\n";
        cout<<"Product Name: "<<productName<<"\nRegular Price: "<<price<<"\nDiscounted Price: "<<getDiscountedPrice()<<"\nMaterial: "<<getMadeof()<<"\nSeat Number: "<<getSeatNumber()<<"\n";
        cout<<"#############################################################################\n\n";
    }
};

enum class ChairCount {Two,Four,Six};

class DiningTable:public Furniture
{
private:
    ChairCount chaircnt;
    string productName;
public:
    DiningTable( double p,double d,Material m,ChairCount c):Furniture(p,d,m),chaircnt(c),productName("DiningTable")
    {

    }
    string getChairCount()const
    {
        if(chaircnt==ChairCount::Two)
            return string("Two");
        else if(chaircnt==ChairCount::Four)
            return string("Four");
        else if(chaircnt==ChairCount::Six)
            return string("Six");
        else
            return string("");
    }
    void productDetails()
    {
        cout<<"---------------------------------------------\n";
        cout<<"Product Name: "<<productName<<"\nRegular Price: "<<price<<"\nDiscounted Price: "<<getDiscountedPrice()<<"\nMaterial: "<<getMadeof()<<"\nChair Count: "<<getChairCount()<<"\n";
        cout<<"#############################################################################\n\n";
    }

};

/**task 4
sort_furniture_discount will sort the array in descending order based on their discount price.
You may need to add some member functions
**/
void sort_furniture_discount(Furniture *furnitures[],int no_of_furnitures)
{
    for(int i=0; i<no_of_furnitures-1; ++i)
    {
        for(int j=i+1; j<no_of_furnitures; ++j)
        {
            double a,b;
            a = furnitures[i]->getDiscountedPrice();
            b = furnitures[j]->getDiscountedPrice();
            if(a<b)
                swap(furnitures[i],furnitures[j]);
        }
    }
}

int main()
{
    Furniture* f_list[100];

    /**
        task 1
        So that following lines can be executed without error
    */
    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SeatNumer::Five);
    f_list[2] = new DiningTable(13000,345,Material::Wood,ChairCount::Four);
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);

    /**task 1 ends here*/

    /**
        task 2
        So that following lines can be executed without error

        task 3 (Modify productDetails)
    */
    f_list[2]->setDiscount(30);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }

    /**task 2 ends here*/
    /**task 3 ends here*/

    /**task 4
    So that following lines can be executed without error
    */
    sort_furniture_discount(f_list,4);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }

    /**task 4 ends here*/

    for(int i=0; i<4; ++i)
    {
        delete f_list[i];
    }

}
