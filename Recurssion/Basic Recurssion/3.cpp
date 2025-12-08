#include<iostream>
using namespace std;
int n;
void f(int currentval)
{
    if(currentval == n)
    {
        return;
    }
    cout<<currentval+1<<"\t";
    f(currentval+1);
}
int main()
{
    cin>>n;
    f(0);
    return 0;
}