#include<iostream>
#include<vector>
#include<set>
#include <algorithm>
using namespace std;
vector<int>arr;
void Createarr(int n)
{
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
set<vector<int>>finalans;
vector<int>Ans;
void f(int sum,int CurrentIndex)
{
    if(sum ==0)
    {
        sort(Ans.begin(),Ans.end());
        finalans.insert(Ans);
        return;
    }
    if(sum<0 || CurrentIndex == arr.size())
    {
        return;
    }
    Ans.push_back(arr[CurrentIndex]);
    f(sum-arr[CurrentIndex],++CurrentIndex);
    Ans.pop_back();
    f(sum,++CurrentIndex);
}
void Display()
{
    for(auto arr : finalans)
    {
        cout<<"Arr:"<<"\t";
        for(int i : arr)
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
    Createarr(n);
    int sum;
    cin>>sum;
    f(sum,0);
    Display();
    return 0;
}