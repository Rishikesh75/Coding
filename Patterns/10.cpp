#include<iostream>
using namespace std;
void pattern_1(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"*"<<"\t";
        }
        cout<<"\n";
    }
}
void pattern_2(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<"*"<<"\t";
        }
        cout<<"\n";
    }
}
int main()
{   
    int n;
    cin>>n;
    pattern_1((n-n/2));
    pattern_2(n/2);
    return 0;
}