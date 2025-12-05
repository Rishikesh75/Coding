#include<iostream>
#include<vector>
#include<list>
using namespace std;
void CreateArr(int n,vector<list<int>>&arr)
{
    int num;
    for(int i=0;i<n;i++)
    {
        while(1)
        {
            cout<<"Enter the Edges from "<<i;
            cin>>num;
            if(num == -1)
            {
                break;
            }
            arr[i].push_back(num);
        }
    }
}
void display(vector<list<int>>arr)
{
    cout<<"Value:"<<"\t";
    for(auto it = arr.begin();it!=arr.end();it++)
    {
        for(auto i : *it)
        {
            cout<<i<<"\t";
        }
        cout<<"\n";
    }
}
int main()
{
    int n;
    cin>>n;
    vector<list<int>>arr(n);
    CreateArr(n,arr);
    display(arr);
    return 0;
}