#include<iostream>
#include<vector>
using namespace std;
void swap(vector<int>&arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void create_array(vector<int>&arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the value:";
        cin>>arr[i];
    }
    cout<<"\n";
}
void display(vector<int>&arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
//two pointers check
void Bubble_sort(vector<int>&arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr,i,j);
            }
        }
    }
    display(arr,n);
}
int findminindex(vector<int>arr,int startindex,int n)
{
    int temp = startindex;
    for(int i=startindex+1;i<n;i++)
    {
        if(arr[i]<arr[temp])
        {
            temp = i;
        }
    }
    return temp;
}
//select the corresponding min and place at the corresponding Index.
void selectionSort(vector<int>arr,int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        int index = findminindex(arr,i,n);
        swap(arr,index,i);
    }
    display(arr,n);
}
void sortleftarray(vector<int>&arr,int endIndex)
{
    int temp = endIndex;
    for(int i=temp-1;i>=0;i--)
    {
        if(arr[i]>arr[endIndex])
        {
            swap(arr,i,endIndex);
            endIndex = i;
        }
        else if(arr[i]<arr[endIndex])
        {
            break;
        }
    }
}
void insertionSort(vector<int>arr,int n)
{
    for(int i=1;i<n;i++)
    {
        sortleftarray(arr,i);
    }
    display(arr,n);
}
void sort(vector<int>&arr,int arr_2,int lastIndex)
{
    for(int i = arr_2+1;i<=lastIndex;i++)
    {
        if(arr[i]<arr[arr_2])
        {
            swap(arr,i,arr_2);
            arr_2 = i;
        }
        else if(arr[i]>arr[arr_2])
        {
            break;
        }
    }
}
void MergeSortCombine(vector<int>&arr,int startIndex,int mid,int lastIndex)
{
    int arr_1 =  startIndex;
    int arr_2 = mid + 1;
    while(arr_1!=mid+1)
    {   
        if(arr[arr_1]>arr[arr_2])
        {
            swap(arr,arr_1,arr_2);
            sort(arr,arr_2,lastIndex);
        }
        arr_1  = arr_1 + 1;
    }
}
void MergeSort(vector<int>&arr,int startIndex,int lastIndex)
{
    if(startIndex >= lastIndex)
    {
        return;
    }
    int mid = startIndex + (lastIndex - startIndex)/2;
    MergeSort(arr,startIndex,mid);
    MergeSort(arr,mid+1,lastIndex);
    MergeSortCombine(arr,startIndex,mid,lastIndex);
}
int findPos(vector<int>&arr,int startIndex,int endIndex,int pivot)
{
    int i = startIndex;
    int j = endIndex;
    while(1)
    {
        if(j<i)
        {
            swap(arr,startIndex-1,j);
            return j;
        }
        else if(arr[i]<pivot)
        {
            i = i + 1;
        }
        else if(arr[j]>pivot)
        {
            j= j - 1;
        }
        else if(arr[i]>pivot && arr[j]<pivot)
        {
            swap(arr,i,j);
            i = i +1;
            j = j - 1;
        }
    }
}
void QuickSort(vector<int>&arr,int startIndex,int endIndex)
{
    if(startIndex>=endIndex)
    {
        return;
    }
    int Pivot  = arr[startIndex];
    int pos = findPos(arr,startIndex+1,endIndex,Pivot);
    //cout<<pos<<endl;
    QuickSort(arr,startIndex,pos-1);
    QuickSort(arr,pos+1,endIndex);
}
int main()
{
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    vector<int>arr(n,0);
    create_array(arr,n);
    //Bubble_sort(arr,n);
    //selectionSort(arr,n);
    //insertionSort(arr,n);
    //MergeSort(arr,0,n-1);
    QuickSort(arr,0,n-1);
    display(arr,n);
    return(0);
}