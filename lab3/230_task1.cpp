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
    Counter hollow, hello, cnt(4);
    hollow.setIncrementStep(6);
    hollow.increment();
    cout<<"after incrementing once :"<<hollow.getCount()<<"\n";

    hollow.increment();
    cout<<"after incrementing twice :"<<hollow.getCount()<<"\n";
    hollow.resetCount();
    cout<<"after resetting :";
    cout<<hollow.getCount()<<"\n";
    cout<<"Initial count :";
    cout<<hello.getCount()<<"\n";
    hello.setIncrementStep(5);
    hello.increment();
    cout<<"after incrementing once :";
    cout<<hello.getCount()<<"\n";

    cout<<"Initial count :";
    cout<<cnt.getCount()<<"\n";
    cnt.increment();
    cout<<"after incrementing once :"<<cnt.getCount();

}
