#include "array.h"
#include<iostream>
using namespace std;
vector<int> Array::createArray(int n) {
    vector<int> arr(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    return arr;
}
void Array::displayArr(int n,vector<int>arr)
{
    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
void Array::copyArr(int last_index,vector<int>&arr_from,vector<int>&arr_to,int start_index)
{
    for(int i=start_index;i<=last_index;i++)
    {
        arr_to[i] =arr_from[i];
    }
}   
void Array::arrSwap(vector<int>&arr,int startindex,int lastindex)
{
    int temp = arr[startindex];
    arr[startindex] = arr[lastindex];
    arr[lastindex] = temp;
}