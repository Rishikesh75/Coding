#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int a = a ^ b;
    int b = a ^ b;
    int a = a ^ b;
}
int main()
{
    int a;
    int b;
    cin>>a;
    cin>b;
    cout<<a<<b<<endl;
    swap(a,b);
    cout<<a<<b<<endl;

    return 0;
}