#include<iostream>
#include<vector>
using namespace std;
void create_array(vector<int>&arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
void display_arr(vector<int>arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
int BinarySearch(vector<int>arr,int firstIndex,int lastIndex,int value)
{
    int i = firstIndex+(lastIndex-firstIndex)/2;
    while(firstIndex<=lastIndex)
    {
        if(arr[i] == value)
        {
            return i;
        }
        else if(arr[i]>value)
        {
            lastIndex = i -1;
        }
        else if(arr[i]<value)
        {
            firstIndex = i + 1;
        }
    }
}
int main()
{
    int n;
   int value;
    cin>>n;
    cout<<"Enter the Value"<<endl;
    cin>>value;
    vector<int>v_1(n,0);
    create_array(v_1,n);
    display_arr(v_1,n);
    cout<<BinarySearch(v_1,0,n-1,value)<<endl;
    return(0);
}