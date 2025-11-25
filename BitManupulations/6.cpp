//Check if the Number is power of 2;
#include<iostream>
using namespace std;
bool CheckPow2(int n)
{
    if(n == 0)
    {
        return false;
    }
    if(n == 1)
    {
        return true;
    }
    int i=1;
    while(1)
    {
        i = i << 1;
        if(i== n)
        {
            return true;
        }
        else if(n < i)
        {
            return false;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<CheckPow2(n)<<endl;
    return 0;
}