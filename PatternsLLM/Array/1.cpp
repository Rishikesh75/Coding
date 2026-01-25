#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr = {1,2,3};
    int value = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        value = max(value,arr[i]);
    }
    cout<<value<<endl;
    return 0;
}