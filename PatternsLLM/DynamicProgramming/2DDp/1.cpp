#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
vector<vector<int>>value;
int n,m;
int f(int i,int j)
{
    if(i == n)
    {
        return 0;
    }
    int temp = INT_MIN;
    if(i == -1 && j == -1)
    {
        
        for(int k=0;k!=m;k++)
        {
            temp = max(f(0,k),temp);
        }
        return temp;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    for(int k=0;k!=m;k++)
    {
        if(k == j)
        {
            continue;
        }
        temp = max(value[i][j]+f(i+1,k),temp);
    }
    dp[i][j] = temp;
    return dp[i][j];
}
void createdP(int n,int m)
{
    dp.resize(n);
    value.resize(n);
    for(int i=0;i<n;i++)
    {
        dp[i].resize(m,-1);
        value[i].resize(m,-1);
    }
}
void CreateValue()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>value[i][j];
        }
    }
}
int main()
{
    
    cin>>n;
    cin>>m; 
    createdP(n,m);
    CreateValue();
    cout<<f(-1,-1)<<endl;
    return 0;
}