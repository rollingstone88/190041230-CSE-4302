#include<bits/stdc++.h>
using namespace std;

class Counter
{
private:
    int count, incr_step;

public:
    Counter():count(0)
    {

    }
    Counter(int val):count(0)
    {
        incr_step = val;
    }
    void setIncrementStep(int step_val)
    {
        incr_step = step_val;
    }
    int getCount()
    {
        return count;
    }
    void increment()
    {
        count += incr_step;
    }
    void resetCount()
    {
        count = 0;
    }
};

int main()
{
    Counter h1, h2, cnt(4);

    h1.setIncrementStep(6);
    h1.increment();
    cout<<"after incrementing once :"<<h1.getCount()<<"\n";

    h1.increment();
    cout<<"after incrementing twice :"<<h1.getCount()<<"\n";
    h1.resetCount();
    cout<<"after resetting :";
    cout<<h1.getCount()<<"\n";
    cout<<"Initial count :";
    cout<<h2.getCount()<<"\n";
    h2.setIncrementStep(5);
    h2.increment();
    cout<<"after incrementing once :";
    cout<<h2.getCount()<<"\n";

    cout<<"Initial count :";
    cout<<cnt.getCount()<<"\n";
    cnt.increment();
    cout<<"after incrementing once :"<<cnt.getCount();

}
