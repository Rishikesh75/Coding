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
    int value = 0;
    for(int i : arr)
    {
        value = value ^ i;
    }
    int rightmost = (value & value-1) ^ value;
    int b1 = 0;
    int b2 = 0;
    for(int i : arr)
    {
        if(i & rightmost)
        {
            b1 =b1 ^ i;
        }
        else
        {
            b2 = b2 ^ i;
        }
    }
    cout<<b1<<b2<<endl;
    return 0;
}