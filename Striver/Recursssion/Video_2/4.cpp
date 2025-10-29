#include<iostream>
using namespace std;
void f(int n)
{
    if(n==0)
    {
        return;
    }
    f(n-1);
    cout<<n<<endl;
    return;
}
int main()
{
    int n;
    cin>>n;
    f(n);
    return 0;
}