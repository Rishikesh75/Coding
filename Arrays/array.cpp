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
void Array::arrSwap(vector<int> &arr_1, vector<int> &arr_2, int i_1, int i_2)
{
    int temp = arr_1[i_1];
    arr_1[i_1] = arr_2[i_2];
    arr_2[i_2] =temp;
}
void Array::arrCheck(vector<int>&arr,int n)
{
    Array arrObj;
    int index = 0;
    for(int i=1;i<n;i++)
    {
        if(arr[index]>arr[i])
        {
            arrObj.arrSwap(arr,index,i);
            index = i;
        }
    }
}

vector<vector<int>>TwoDArray::createArray(int n,int m)
{
    vector<vector<int>>arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    return arr;
}   