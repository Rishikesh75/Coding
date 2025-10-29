#include<iostream>
using namespace std;
void f(int n)
{
    if(n == 0)
    {
        return;
    }
    cout<<n<<"\t";
    f(n-1);
    return;
}
int main()
{
    int n;
    cin>>n;
    f(n);
    return 0;
}