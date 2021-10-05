#include <iostream>
using namespace std;
#include <process.h> //for exit()
const int LIMIT = 100; //array size
////////////////////////////////////////////////////////////////
template <class t>
class safearay
{
private:
    t arr[LIMIT];
public:
    t& operator [](int n) //note: return by reference
    {
        if( n< 0 || n>=LIMIT )
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[n];
    }
};
////////////////////////////////////////////////////////////////
int main()
{
    safearay<int>sa1;
    safearay<float>a;
    for(int j=0; j<LIMIT; j++)  //insert elements
    {
        sa1[j] = j*10;
        a[j] = j* 1.2; //*left* side of equal sign
    }
    for(int j=0; j<LIMIT; j++) //display elements
    {
        int temp = sa1[j]; //*right* side of equal sign
        cout << "Element of Integer array " << j << " is " << temp << endl;
    }
    for(int j=0; j<LIMIT; j++) //display elements
    {
        float temp = a[j]; //*right* side of equal sign
        cout << "Element of Float array " << j << " is " << temp << endl;
    }
    return 0;
}
