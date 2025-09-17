#include<iostream>
using namespace std;
vector<vector<int>>arr_val;
void swap(vector<int>&arr,int start,int end)
{
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}
void permutations(vector<int>&arr,int start,int end)
{
    if(start == arr.size()-1)
    {
        arr_val.push_back(arr);
        return;
    }
    if(start != -1)
    {
        swap(arr,start,end);
    }
    for(int i=start+1;i<arr.size();i++)
    {
            permutations(arr,start,end)
    }
}
int main()
{


    return 0;
}
