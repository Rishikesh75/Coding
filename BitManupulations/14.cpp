#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ones = 0;
    int twos = 0;
    int threes = 0;
    for(int i=0;i<n;i++)
    {
        ones = (ones ^ arr[i]) & (~twos);
        twos = (twos ^ arr[i]) & (~ones);
    }
    cout<<ones<<endl;
    return 0;
}