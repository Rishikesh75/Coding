#include<iostream>
using namespace std;
int CheckSetBit(int n)
{
    int count = 0;
    while(n!=0)
    {
        if(n & 1 == 1)
        {
            count = count + 1;
        }
        n = n >> 1;
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    cout<<CheckSetBit(n)<<endl;
    return 0;
}