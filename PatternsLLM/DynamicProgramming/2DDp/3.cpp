//MinPathSum or MaxpathSum
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>grid;
vector<vector<int>>dp;
int n,m;
void Init(int n,int m)
{
    grid.resize(n);
    dp.resize(n);
    for(int i=0;i<n;i++)
    {
        grid[i].resize(m,0);
        dp[i].resize(m,-1);
    }
}
void CreateGrid(int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
}
int MinimumPathSum(int i,int j)
{
    if(i == n || j == m)
    {
        return INT_MAX;
    }
    if(i == n-1 && j == m-1)
    {
        return grid[i][j];
    }
    if(dp[i][j] == -1)
    {
        dp[i][j] = grid[i][j] + min(MinimumPathSum(i+1,j),MinimumPathSum(i,j+1));
    }
    return dp[i][j];
}
int main()
{
       
    cin>>n;
    cin>>m;
    Init(n,m);
    CreateGrid(n,m);
    cout<<MinimumPathSum(0,0)<<endl;
    return 0;
}