//set Nth Bit
#include<iostream>
using namespace std;
int setnthbit(int n,int value)
{   
    int temp = 1 << n;
    value = value | temp;
    return value;
}
int main()
{
    int n,value;
    cout<<"Enter the Nth Bit:";
    cin>>n;
    cout<<"Enter the value:";
    cin>>value;
    cout<<setnthbit(n,value)<<endl;
    return 0;
}