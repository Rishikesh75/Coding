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
vector<int>h;
vector<vector<int>>ans;
void createHash(int n)
{
    h.resize(n);
    for(int i=0;i<n;i++)
    {
        h[i] = 0;
    }
}
void f(int count,vector<int>permutation)
{
    if(count == arr.size())
    {
        ans.push_back(permutation);
        return;
    }
    for(int i=0;i<arr.size();i++)
    {
        if(h[i]==0)
        {
            permutation.push_back(arr[i]);
            h[i]=1;
            f(count+1,permutation);
            permutation.pop_back();
            h[i] = 0;
        }
    }
}
void display()
{
    for(int i=0;i<ans.size();i++)
    {
        cout<<"Ans: "<<"\t";
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
int main()
{
    int n;
    cin>>n;
    createarr(n);
    createHash(n);
    vector<int>sample;
    f(0,sample);
    display();
    return 0;
}