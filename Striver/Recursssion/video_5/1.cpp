#include<iostream>
#include<vector>
using namespace std;
vector<int>arr;
vector<int>ans;
void Createarr(int n)
{
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
void Display(vector<int>array)
{
    cout<<"arr"<<"\t";
    for(int i=0;i<array.size();i++)
    {
        cout<<array[i]<<"\t";
    }
    cout<<"\n";
}
void f(int CurrentIndex)
{
    if(CurrentIndex == arr.size()-1)
    {
        Display(ans);
        return;
    }
    ans.push_back(arr[CurrentIndex+1]);
    f(CurrentIndex+1);
    ans.pop_back();
    f(CurrentIndex+1);
}
int main()
{
    int n;
    cin>>n;
    Createarr(n);
    f(-1);
    return 0;
}