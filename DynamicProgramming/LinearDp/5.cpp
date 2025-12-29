#include<bits/stdc++.h>
using namespace std;
vector<int> Createarr(int n)
{
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    return arr;
}
vector<int>dp;
int FindMax(int n,vector<int>&arr)
{
    if(n<=0)
    {
        return 0;
    }
    if(dp[n] == -1)
    {
        dp[n] = max(FindMax(n-1,arr),FindMax(n-2,arr) + arr[n]);
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr = Createarr(n);
    dp.resize(n,-1);
    cout<<FindMax(n-1,arr)<<endl;
    return 0;
}