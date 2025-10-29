#include<iostream>
using namespace std;
int n;
void f(int x)
{
    if(x-1== n)
    {
        return;
    }
    cout<<"Rishi"<<"\t";
    f(x+1);
    return;
}
int main()
{
   
    cin>>n;
    f(1);
    return(0);
}