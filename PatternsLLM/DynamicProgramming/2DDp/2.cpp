//Count Paths with obstarcles
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>grid;
vector<vector<int>>dp;
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
int Noofpaths(int i,int j,int& n,int& m)
{
    if(i == n || j == m || grid[i][j] == 1)
    {
        return 0;
    }
    else if(i == n-1 && j == m-1)
    {
        return 1;
    }
    if(dp[i][j] == -1)
    {
        dp[i][j] = Noofpaths(i+1,j,n,m)+Noofpaths(i,j+1,n,m);
    }
    return dp[i][j];
}
int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    Init(n,m);
    CreateGrid(n,m);
    cout<<Noofpaths(0,0,n,m)<<endl;
    return 0;
}