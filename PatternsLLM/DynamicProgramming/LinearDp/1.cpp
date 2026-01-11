#include<iostream>
#include<vector>
using namespace std;
vector<int>dp;
int Fib(int n)
{
    if(n == 1)
    {
        return 0;
    }
    else if(n == 2)
    {
        return 1;
    }
    if(dp[n] == -1)
    {
        dp[n] = Fib(n-1) + Fib(n-2);
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    dp.resize(n+1,-1);
    cout<<Fib(n)<<endl;
    return 0;
}