#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int>s;
    int arr[10] ;
    vector<int>v(20);


    for(int i=1; i<=20; i+=2)
    {
        s.insert(i);
    }
    for(int i=2,j=0; i<=20; i+=2,++j)
    {
        arr[j] = i;
    }

    merge(arr,arr+10,s.begin(),s.end(),v.begin());
    for(int i=0; i<20; ++i)
        cout<<v[i]<<" ";
}
