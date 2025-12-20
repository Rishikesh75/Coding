//Fibinoci series
#include<iostream>
#include<vector>
using namespace std;
vector<int>dp;
int Fib(int n)
{
    if(dp[n] == -1)
    {
        if(dp[n-1]==-1)
        {
            dp[n-1] = Fib(n-1);
        }
        if(dp[n-2] == -1)
        {
            dp[n-2] = Fib(n-2);
        }
        dp[n] = dp[n-1] + dp[n-2];
    }
    
    return dp[n];
}
int main()
{
    
    int n;
    cin>>n;
    dp.resize(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    cout<<"value:"<<Fib(n);
    return 0;
}