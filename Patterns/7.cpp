#include<iostream>
using namespace std;
void pattern(int n)
{
    pair<int,int>value;
    value.first = n-1;
    value.second = n-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=2*(n-1);j++)
        {
            if( j>=value.first && j<=value.second)
            {
                cout<<"*"<<"\t";
            }
            else
            {
                cout<<""<<"\t";
            }
        }
        cout<<"\n";
        value.first = value.first - 1;
        value.second = value.second + 1;
    }
}
int main()
{
    int n;
    cin>>n;
    pattern(n);
    return 0;
}