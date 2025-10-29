#include<iostream>
using namespace std;
int n;
void f(int x)
{
    if(x == n)
    {
        return;
    }
    cout<<x+1<<"\t";
    f(x+1);
    return;
}
int main()
{
    cin>>n;
    f(0);
    return(0);
}