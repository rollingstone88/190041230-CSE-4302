#include<bits/stdc++.h>
using namespace std;

class Counter
{
private:
    int count;
    int incr_step;
public:
    Counter():count(0),incr_step(1)
    {

    }

    Counter(int c, int s):count(c),incr_step(s)
    {

    }

    Counter(int c):count(c)
    {

    }

    void setIncrementStep(int step_val)
    {
        if(step_val<0)
        {
            cout<<"step value cannot be negative\n";
            incr_step = 1;
            return;
        }
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

    Counter operator + (Counter a) const
    {
        return Counter(count +  a.count, min(incr_step, a.incr_step));
    }

    Counter operator + (int val) const
    {
        return Counter(count + val, incr_step);
    }

    void operator += (Counter a)
    {
        count += a.count;
    }

    Counter operator ++()
    {
        increment();
        Counter temp(count);
        return temp;
    }

    Counter operator ++(int)
    {
        Counter temp(count);
        increment();
        return temp;
    }

    friend Counter operator + (int val, Counter c);

    ~Counter()
    {

    }

};

Counter operator + (int val, Counter c)
{
    return Counter(val + c.count, c.incr_step);
}


int main()
{
    Counter c1, c2, c3, c4(1,2);

    c1++;
    ++c1;
    cout<<"Count (c1) : "<<c1.getCount()<<"\n";

    cout<<"Count (c2) : "<<c2.getCount()<<"\n";

    c2 += c1;

    cout<<"Count (c2 += c1) : "<<c2.getCount()<<"\nCount (c1) : "<<c1.getCount()<<"\n";

    c3 = c1 + c2;
    cout<<"Count (c3 = c1+c2) : "<<c3.getCount()<<"\n";
    c3 = c2++;
    cout<<"Count (c3 = c2++) : "<<c3.getCount()<<"\n";
    c3 = ++c2;
    cout<<"Count (c3 = ++c2) : "<<c3.getCount()<<"\n";
    cout<<"Count (c4) : "<<c4.getCount()<<"\n";

    c4 = c3+5;
    cout<<"Count (c4 = c3 + 5) : "<<c4.getCount()<<"\n";
    c4 = 5 + c3;
    cout<<"Count (c4 = 5 + c3) : "<<c4.getCount()<<"\n";
    cout<<"Count (c3) : "<<c3.getCount()<<"\n";


}
