//Single Number 2
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n,0);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<=31;i++)
    {
        int count =0;
        for(int j=0;j<arr.size();j++)
        {
            
            if(arr[j] & (1<<i))
            {
                count++;
            }
        }
        if(count %3 == 1)
        {
            ans = ans | (1<<i);
        }
    }
    cout<<ans<<endl;

    return 0;
}