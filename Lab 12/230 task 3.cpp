#include <iostream>
using namespace std;
#include <process.h>
const int LIMIT = 100;
template <class t>
class safearay
{
private:
    t arr[LIMIT];
public:
    class out_of_bounds
    {
    public:
        int index;
        out_of_bounds(int i)
        {
            index = i;
        }

    };
    t& operator [](int n)
    {
        if( n< 0 || n>=LIMIT )
        {
           throw out_of_bounds(n);
        }
        return arr[n];
    }
};


int main()
{
    safearay<int>sa1;
    safearay<float>a;
    try{
    for(int j=0; j<LIMIT; j++)
    {
        sa1[j] = j*10;
        a[j] = j*1.2;
    }
    for(int j=0; j<LIMIT; j++)
    {
        int temp = sa1[j];
        cout << "Element of Integer array " << j << " is " << temp << endl;
    }
    for(int j=-1; j<LIMIT; j++)
    {
        float temp = a[j];
        cout << "Element of Float array " << j << " is " << temp << endl;
    }
    }
    catch(safearay<int>::out_of_bounds ob)
    {
        cout << "\nIndex "<<ob.index<<" out of bounds\n";
    }
    catch(safearay<float>::out_of_bounds ob)
    {
        cout << "\nIndex "<<ob.index<<" out of bounds\n";
    }
    return 0;
}

