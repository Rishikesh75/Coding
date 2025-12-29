#include<iostream>
#include<vector>
using namespace std;
vector<int>Es;
vector<int>dp;
int MinEnergy(int n)
{
    if(n < 0)
    {
        return 0;
    }
    if(dp[n] == -1)
    {
        if(n>=2)
        {
            dp[n] = min(MinEnergy(n-2) + Es[n] - Es[n-2],MinEnergy(n-1) + Es[n] - Es[n-1]);
        }
        else if(n == 0)
        {
            dp[0] = 0;
        }
        else if(n ==1)
        {
            dp[1] = Es[1] - Es[0];
        }
        
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    Es.resize(n,-1);
    dp.resize(n,-1);
    for(int i=0;i<n;i++)
    {
        cout<<dp[i]<<"\t";
        cin>>Es[i];
    }
    cout<<MinEnergy(n-1)<<endl;
    return 0;
}