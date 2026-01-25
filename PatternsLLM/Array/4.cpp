#include<bits/stdc++.h>
using namespace std;
void swap(int start,int end,vector<int>&arr)
{
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}
int main()
{
    vector<int>arr = {1,0,1,0,2,2};
    int start = 0;
    int end = arr.size()-1;
    while(start<end)
    {
        if(arr[start]!=0)
        {
            start++;
            continue;
        }
        else if(arr[end] == 0)
        {
            end--;
            continue;
        }
        swap(start,end,arr);
        start++;
        end--;
    }
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<"\t";
    }

    return 0;
}