//MergeSort Algoritham
#include<iostream>
using namespace std;
vector<int>arr;
void createarr(int n)
{
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
void MergeSort(vector<int>arr,int startindex,int endindex)
{
    if(startindex == endindex)
    {
        return;
    }
    int mid = start + (end - start)/2;
    MergeSort(arr,startindex,mid);
    MergeSort(arr,mid+1,endindex);
    Merge(arr,startindex,mid,endindex);
}
void display()
{
    cout<<"arr:";
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
int main()
{


    return 0;
}