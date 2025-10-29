#include<iostream>
using namespace std;
int n;
void f(int x)
{
    if(x == n)
    {
        return;
    }
    f(x+1);
    cout<<x+1<<"\t";
    return;
}
int main()
{
    cin>>n;
    f(0);
    return(0);
}