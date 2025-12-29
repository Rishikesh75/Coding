//House Rober
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
int n;
int FindMaxAmount(int index,vector<int>&arr,int FinalIndex)
{
    if(index<0)
    {
        return 0;
    }
    if(index == 0 && FinalIndex == 1)
    {
        return 0;
    }
    if(dp[index]==-1)
    {
        if(index == n-1)
        {
            dp[index] = max(FindMaxAmount(index-2,arr,1)+arr[index],FindMaxAmount(index-1,arr,0));
        }
        else
        {
            dp[index] = max(FindMaxAmount(index-2,arr,FinalIndex)+arr[index],FindMaxAmount(index-1,arr,FinalIndex));
        }
    }
    return dp[index];
}
int main()
{
    cin>>n;
    vector<int>arr = Createarr(n);
    dp.resize(n,-1);
    cout<<FindMaxAmount(n-1,arr,0)<<endl;
    return 0;
}