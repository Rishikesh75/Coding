//MergeSort Algoritham
//Checking the Commit File
#include<iostream>
#include<vector>
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
void Copy(vector<int>&temp,vector<int>&arr,int startindex)
{
    for(int i=0;i<temp.size();i++)
    {
        arr[startindex] = temp[i];
        startindex++;
    }
}
void Merge(int startindex,int midindex,int endindex)
{
    int i_1 = startindex;
    int i_2 = midindex+1;
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

void MergeSort(int startindex,int endindex)
{
    if(startindex == endindex)
    {
        return;
    }
    int mid = startindex + (endindex - startindex)/2;
    MergeSort(startindex,mid);
    MergeSort(mid+1,endindex);
    Merge(startindex,mid,endindex);
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
    int n;
    cout<<"Enter the Size of the Array:";
    cin>>n;
    createarr(n);
    MergeSort(0,n-1);
    display();
    return 0;
}