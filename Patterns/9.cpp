#include<iostream>
using namespace std;
void pattern_1(int n)
{
    pair<int,int>p;
    p.first = n;
    p.second = n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2*n-1;j++)
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
        cout<<"\n";
        p.first = p.first - 1;
        p.second = p.second + 1;
    }
}
void pattern_2(int n)
{
    pair<int,int>p;
    p.first = 1;
    p.second = 2*n-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2*n-1;j++)
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
        cout<<"\n";
        p.first = p.first + 1;
        p.second = p.second - 1;
    }
}   
int main()
{
    int n;
    cin>>n;
    pattern_1(n/2);
    pattern_2(n/2);

    return 0;
}