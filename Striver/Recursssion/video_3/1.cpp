//parameterized Recurssion
#include<iostream>
using namespace std;
int n;
int sum;
void f(int x,int& sum)
{
    if(x == n)
    {
        return;
    }
    sum = sum + x +1;
    f(x+1,sum);
    return;
}
int main()
{
    cin>>n;
    f(0,sum);
    cout<<sum<<endl;
    return 0;
}