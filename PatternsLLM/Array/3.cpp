#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr = {1,1,1,2,2};
    int value = arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i] == value)
        {
            arr[i] = -1;
            continue;
        }
        value = arr[i];
    }
    for(auto it = arr.begin(); it != arr.end(); )
    {
        if(*it == -1)
            it = arr.erase(it);   // erase returns next valid iterator
        else
            it = it + 1;
    }

    // Optional: print result
    for(int x : arr)
        cout << x << " ";
    return 0;
}