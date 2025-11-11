//Check ith Bit..
#include<iostream>
using namespace std;
bool Checkithbit(int n,int value)
{
    int temp = 1 << n;
    return temp & value;
}
int main()
{
    int n,value;
    cout<<"Enter the Nth Bit:";
    cin>>n;
    cout<<"Enter the value:";
    cin>>value;
    cout<<Checkithbit(n,value)<<endl;
    return 0;
}