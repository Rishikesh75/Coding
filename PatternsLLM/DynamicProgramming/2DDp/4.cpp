//Cheery Pick problem 
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>CreateGrid(int n)
{
    vector<vector<int>>grid(n,vector<int>(n,0));
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            cin>>grid[i][j];
        }
    }
    return grid;
}
int dfs(int r1,int c1,int r2,vector<vector<vector<int>>>&dp,int n,vector<vector<int>>&grid)
    {
        int c2 = r1 + c1 - r2;
        if(r1 >= n || c1>=n || r2>=n ||c2>=n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
        {
            return INT_MIN;
        }

        if(r1 == n-1 && c1 == n-1)
        {
            return grid[r1][c1];
        }

        if(dp[r1][c1][r2] !=-1)
        {
            return dp[r1][c1][r2];
        }
        
        int Cheries = grid[r1][c1];

        if(r1!=r2 || c1 != c2)
        {
            Cheries = Cheries + grid[r2][c2];
        }

        int best = max( max(dfs(r1 + 1, c1,r2 + 1,dp,n,grid),dfs(r1 + 1, c1,r2,dp,n,grid)),max(dfs(r1,c1 + 1, r2 + 1,dp,n,grid),dfs(r1,c1 + 1, r2,dp,n,grid)));
        if (best == INT_MIN)
            return dp[r1][c1][r2] = INT_MIN;       
        
        return dp[r1][c1][r2] =Cheries + best ;
}

int CherryPick(vector<vector<int>>&grid)
{
    int n = grid.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
    
    int result = dfs(0, 0, 0,dp, n,grid);
    if(result<0)
    {
        return 0;
    }
    return result;
    
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>grid = CreateGrid(n);
    cout<<CherryPick(grid)<<endl;
    return 0;
}