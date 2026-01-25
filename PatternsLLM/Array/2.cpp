#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr = {1,2,3};
    int secondvalue = INT_MIN;
    int firstvalue = arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]<firstvalue && arr[i]>secondvalue)
        {
            secondvalue = arr[i];
        }
        else if(arr[i]>firstvalue)
        {
            secondvalue = firstvalue;
            firstvalue = arr[i];
        }
    }
    cout<<secondvalue<<endl;

    return 0;
}