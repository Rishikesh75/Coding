
/*
------STL Methods----
pos means itertor
V.size()
v.push_back()
v.pop_back()
v.front()
v.back() 
v.clear()
v.empty()
v.begin()
v.end()
sort(v.begin(),v.end())
Reverse(v.begin(),v.end())
v.insert(pos,value);
v.erase(pos)
*/



#include<iostream>
#include<vector>
using namespace std;
void Createarr(vector<int>&arr)
{
    for(auto it = arr.begin();it!=arr.end();it++)
    {
        cin>>*it;
    }
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
    vector<int>arr(n);
    Createarr(arr);
    display(arr);
    return 0;
}