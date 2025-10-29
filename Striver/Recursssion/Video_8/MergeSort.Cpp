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
void Merge(vector<int>arr,int startindex,int midindex,int endindex)
{
    int i_1 = startindex;
    int i_2 = endindex;
    int size = endindex - startindex + 1;
    vector<int>temp;
    while(i_1!=midindex+1 && i_2 !=endindex+1)
    {
        if(arr[i_1]>arr[i_2])
        {
            temp.push_back(arr[i_2]);
            i_2 = i_2 + 1;
        }
        else if(arr[i_1]<arr[i_2])
        {
            temp.push_back(arr[i_1]);
            i_1 = i_1 + 1;
        }
    }
    if(i_1 == midindex + 1)
    {
        while(i_2!=endindex + 1)
        {
            temp.push_back(arr[i_2]);
            i_2 = i_2 + 1;
        }
    }
    if(i_2 == endindex + 1)
    {
        while(i_1!=midindex+1)
        {
            temp.push_back(arr[i_1]);
            i_1 = i_1 + 1;
        }
    }
    Copy(temp,arr,startindex);
}
void Copy(vector<int>&temp,vector<int>&arr,int startindex)
{
    for(int i=0;i<temp.size();i++)
    {
        arr[startindex] = temp[i];
        startindex++;
    }
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