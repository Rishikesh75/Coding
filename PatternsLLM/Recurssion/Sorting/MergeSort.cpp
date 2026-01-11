#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void swap(vector<int>&arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void MergeArray(vector<int>& arr, int start, int mid, int end)
{
    int i_1 = start;
    int i_2 = mid + 1;

    while (i_1 <= mid && i_2 <= end)
    {
        if (arr[i_1] <= arr[i_2])
        {
            i_1++;
        }
        else
        {
            // arr[i_1] > arr[i_2], swap
            int value = arr[i_2];
            int index = i_2;

            // shift right half to the left by one position
            while (index > i_1)
            {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[i_1] = value;

            // adjust indices
            i_1++;
            mid++;
            i_2++;
        }
    }
}
void MergeSort(vector<int>&arr,int start,int end)
{
    if(start == end)
    {
        return;
    }
    int mid = start + (end-start)/2;
    MergeSort(arr,start,mid);
    MergeSort(arr,mid+1,end);
    MergeArray(arr,start,mid,end);
}
vector<int>Createarr(int n)
{
    vector<int>arr(n,0);
    cout<<"Enter the array Elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    return arr;
}
void display(vector<int>arr)
{
    for(auto it = arr.begin();it!=arr.end();it++)
    {
        cout<<*it<<"\t";
    }
    cout<<"\n";
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr = Createarr(n);
    MergeSort(arr,0,arr.size()-1);
    display(arr);
    return(0);
}