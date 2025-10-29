//Multiple Recurssion Calls
#include<iostream>
using namespace std;
int fibinocci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    return fibinocci(n-1)+fibinocci(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<fibinocci(n)<<endl;
    return 0;
}