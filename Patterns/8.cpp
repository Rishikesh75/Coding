#include<iostream>
using namespace std;
void pattern(int n)
{
    pair<int,int>p;
    p.first = 0;
    p.second = 2*(n-1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=2*(n-1);j++)
        {
            if(j>=p.first && j<=p.second)
            {
                cout<<"*"<<"\t";
            }
            else
            {
                cout<<""<<"\t";
            }
        }
        p.first = p.first + 1;
        p.second = p.second - 1;
        cout<<"\n";
    }
}
int main()
{
    int n;
    cin>>n;
    pattern(n);
    return 0;
}