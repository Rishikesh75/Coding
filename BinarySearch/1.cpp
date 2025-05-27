#include<iostream>
#include<vector>
using namespace std;
vector<int> create_array()
{
    int n;
    cout<<"Enter the len of array:";
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    return arr;
}
void display(vector<int>&arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
int BinarySearch(vector<int>arr,int value)
{
    int start = 0;
    int end = arr.size()-1;
    int pos =  -1;
    while(1)
    {
        int mid =  start + (end-start)/2;
        if(start == end && arr[start]!=value)
        {
            break;
        }
        else if(arr[mid] == value)
        {
            pos = mid;
            break;
        }
        else if(arr[mid]>value)
        {
            end = mid -1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return pos;
}
void BinarSearchParse(vector<int>arr,int start,int end,int value)
{
    int mid = start + (end-start)/2;
    if(start == end && arr[start]!=value)
    {
        return;
    }
    else if(arr[mid] == value)
    {
        cout<<mid<<endl;
        return;
    }
    else if(arr[mid]>value)
    {
        BinarSearchParse(arr,start,mid-1,value);
        return;
    }
    else
    {
         BinarSearchParse(arr,mid+1,end,value);
         return;
    }
}
int LowerBound(vector<int>arr,int start,int end,int number)
{
    int mid = start + (end- start)/2;
    //cout<<mid<<endl;
    if(start ==end && arr[mid]>number)
    {
        //cout<<"HI"<<endl;
        //cout<<mid<<endl;
        return mid;
    }
    if(arr[mid] == number)
    {
        return mid;
    }
    else if(arr[mid]>number)
    {
        return LowerBound(arr,start,mid,number);
    }
    else if(arr[mid]<number)
    {
        return LowerBound(arr,mid+1,end,number);
    }
}
int UpperBound(vector<int>arr,int start,int end,int number)
{
    int mid = start + (end- start)/2;
    //cout<<mid<<endl;
    cout<<mid<<endl;
    if(start ==end && arr[mid]<number)
    {
        //cout<<"HI"<<endl;
        //cout<<mid<<endl;
        return mid;
    }
    if(arr[mid] == number)
    {
        return mid;
    }
    else if(arr[mid]>number)
    {
        return UpperBound(arr,start,mid-1,number);
    }
    else if(arr[mid]<number)
    {
        return UpperBound(arr,mid,end,number);
    }
}

int main()
{
    vector<int>arr = create_array();
    int Number;
    cout<<"Enter the number to serach:";
    cin>>Number;
    //cout<<BinarySearch(arr,Number)<<endl;
    //BinarSearchParse(arr,0,arr.size()-1,Number);
    //cout<<arr[LowerBound(arr,0,arr.size()-1,Number)]<<endl;;
    cout<<arr[UpperBound(arr,0,arr.size()-1,Number)]<<endl;
    return(0);
}