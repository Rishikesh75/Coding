//Print value 1 to n
#include<iostream>
using namespace std;
void f(int currentVal,int n)
{
    if(currentVal == n+1) return;
    cout<<currentVal<<"\t";
    f(currentVal+1,n);
    return;
}
int main()
{
    int n;
    cin>>n;
    f(1,n);
    return 0;
}