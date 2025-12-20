#include<iostream>
#include<vector>
using namespace std;
vector<int>dp;
int CountWays(int n)
{
    if(n < 0)
    {
        return 0;
    }
    if(dp[n] == -1)
    {
        if(n == 1)
        {
            dp[1] = 1;
        }
        else if(n == 2)
        {
            dp[2] = 2;
        }
        else
        {
            if(dp[n-1] == -1)
            {
                dp[n-1] = CountWays(n-1);
            }
            if(dp[n-2] == -1)
            {
                dp[n-2] = CountWays(n-2);
            }
            dp[n] = dp[n-1] + dp[n-2];
        }
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    dp.resize(n+1,-1);
    cout<<"No of ways:"<<CountWays(n);
    return 0;
}