//MergeSort Without Creating the ExtraSpace
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
void display()
{
    cout<<"arr:"<<"\t";
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
void Movethearr(int startindex,int endindex,int value)
{
    for(int i=endindex;i!=startindex;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[startindex] = value;
}
void Merge(int startindex,int midindex,int endindex)
{   
    int i_1 = startindex;
    int i_2 = midindex+1;
    while(1)
    {
        if(i_1 == midindex+1 || i_2 == endindex + 1)
        {
            break;
        }
        if(arr[i_1]<arr[i_2])
        {
            i_1 = i_1 + 1;
        }
        else if(arr[i_1]>arr[i_2])
        {
            int value = arr[i_2];
            Movethearr(i_1,i_2,value);
            arr[i_1] = value;
            midindex = midindex + 1;
            i_1 = i_1 + 1;
            i_2 = i_2 + 1;
        }
    }
}
void Mergesort(int startindex,int endindex)
{
    if(startindex == endindex) return;
    int midindex = startindex + (endindex - startindex)/2;
    Mergesort(startindex,midindex);
    Mergesort(midindex+1,endindex);
    Merge(startindex,midindex,endindex);
}
int main()
{
    int n;
    cin>>n;
    createarr(n);
    Mergesort(0,n-1);
    display();
    return 0;
}