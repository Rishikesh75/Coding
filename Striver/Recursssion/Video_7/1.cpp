//All Kind Of Patterns in Recurssion
#include<iostream>
#include<vector>
using namespace std;
vector<int>arr;
vector<int>ans;
int value;
void Display(vector<int>array)
{
    cout<<"arr"<<"\t";
    for(int i=0;i<array.size();i++)
    {
        cout<<array[i]<<"\t";
    }
    cout<<"\n";
}
void Recurssion(int CurrentIndex,int Sum,vector<int>&ans)
{
    if(CurrentIndex == arr.size()-1)
    {
        if(Sum == value)
        {
            Display(ans);
        }
        return;
    }
    ans.push_back(arr[CurrentIndex+1]);
    Recurssion(CurrentIndex+1,Sum+arr[CurrentIndex+1],ans);
    ans.pop_back();
    Recurssion(CurrentIndex+1,Sum,ans);
}
void Createarr(int n)
{
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<"Enter the Sum:";
    cin>>value;
    Createarr(n);
    Recurssion(-1,0,ans);
    return 0;
}