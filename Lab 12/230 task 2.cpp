
#include<bits/stdc++.h>
using namespace std;

template <class t>
t amax(t* arr, int sz)
{
    t arraymax = arr[0];
    for(int i=0; i<sz; ++i)
    {
        if(arr[i]>arraymax)
            arraymax = arr[i];
    }
    return arraymax;
}

int main()
{
    int arr1[] = {1,2,3,4,5};
    float arr2 [] = {0.5,1.2,2.3,4.5,5.5};
    long arr3[] = {1L,2L,3L,4L,7L};
    float temp1 = amax(arr2,5);
    cout<<temp1<<endl;
    int temp2 = amax(arr1,5);
    cout<<temp2<<endl;
    long temp3 = amax(arr3,5);
    cout<<temp3<<endl;
}
