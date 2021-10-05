#include <fstream>
#include <iostream>
#include <typeinfo>
using namespace std;
#include <process.h>
enum furniture_type {tBed, tSofa, tDiningTable};
enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
public:
    Furniture()
    {

    }
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
    static void read(Furniture* arrap[]);
    static void write(Furniture* arrap[]);
    virtual furniture_type get_type();
    virtual void productDetails()=0;
};

enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
private:
    BedSize bedsz;
    string productName;
public:
    Bed()
    {

    }
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
    Sofa()
    {

    }
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
    DiningTable()
    {

    }
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

furniture_type Furniture::get_type()
{
    if( typeid(*this) == typeid(Bed) )
        return tBed;
    else if( typeid(*this)==typeid(Sofa) )
        return tSofa;
    else if( typeid(*this)==typeid(DiningTable) )
        return tDiningTable;
    else
    {
        cerr << "\nBad Furniture type";
        exit(1);
    }
}

void Furniture::write(Furniture* arrap[])
{
    int sz;

    ofstream ouf;
    furniture_type ftype;
    ouf.open("FURNITURE.DAT", ios::trunc | ios::binary);
    if(!ouf)
    {
        cout << "\nCan’t open file\n";
        return;
    }
    for(int j=0; j<4; j++)
    {

        ftype = arrap[j]->get_type();


        ouf.write( (char*)&ftype, sizeof(ftype) );
        switch(ftype)
        {
        case tBed:
            sz=sizeof(Bed);
            break;
        case tSofa:
            sz=sizeof(Sofa);
            break;
        case tDiningTable:
            sz=sizeof(DiningTable);
            break;

        }
        ouf.write( (char*)(arrap[j]), sz );
        if(!ouf)
        {
            cout << "\nCan’t write to file\n";
            return;
        }
    }
}


void Furniture::read(Furniture* arrap[])
{
    int sz;
    furniture_type ftype;
    ifstream inf;
    inf.open("FURNITURE.DAT", ios::binary);
    if(!inf)
    {
        cout << "\nCan’t open file\n";
        return;
    }
    int n = 0;
    while(true)
    {
        inf.read( (char*)&ftype, sizeof(ftype) );
        if( inf.eof() )
            break;
        if(!inf)
        {
            cout << "\nCan’t read type from file\n";
            return;
        }
        switch(ftype)
        {

        case tBed:
            arrap[n] = new Bed;
            sz=sizeof(Bed);
            break;
        case tSofa:
            arrap[n] = new Sofa;
            sz=sizeof(Sofa);
            break;
        case tDiningTable:
            arrap[n] = new DiningTable;
            sz=sizeof(DiningTable);
            break;
        default:
            cout << "\nUnknown type in file\n";
            return;
        }
        inf.read( (char*)arrap[n], sz );
        arrap[n]->productDetails();
        if(!inf)
        {
            cout << "\nCan’t read data from file\n";
            return;
        }
        n++;
    }
    cout << "Reading " << n << " furniture\n";
}

int main()
{
    Furniture* f_list[4];

    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SeatNumer::Five);
    f_list[2] = new DiningTable(13000,345,Material::Wood,ChairCount::Four);
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);

    Furniture::write(f_list);
    Furniture::read(f_list);

    for(int i=0; i<4; ++i)
    {
        delete f_list[i];
    }

}

