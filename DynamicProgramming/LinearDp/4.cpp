//N-stairs.
#include<bits/stdc++.h>
using namespace std;
vector<int>dp;
vector<int>Height;
int k;
int MinEnergy(int n)
{
    if(n == 0)
    {
        dp[0] = 0;
        return 0;
    }
    if(dp[n] == INT_MAX)
    {
        for(int i=1;i<=k;i++)
        {
            if(n-i>=0)
            {
                dp[n] = min(dp[n],MinEnergy(n-i) + Height[n] - Height[n-i]);
            }
        }
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cin>>k;
    dp.resize(n,INT_MAX);
    Height.resize(n,-1);
    for(int i=0;i<n;i++)
    {
        cin>>Height[i];
    }
    cout<<MinEnergy(n-1)<<endl;
    return 0;
}