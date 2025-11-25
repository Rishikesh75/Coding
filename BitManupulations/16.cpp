#include<iostream>
using namespace std;
void f(int divisor,int divident)
{
    if(divisor == divident) 
    {
        cout<<1<<endl;
        return;
    }
    int ans = 0;
    while(divident >=divisor)
    {
        int count =0;
        while(divident>=(divisor << count + 1))
        {
            count ++;
        }
        ans = ans + (1 << count);
        divident = divident - (divisor * (1<<count));
    }
    cout<<ans<<endl;
}
int main()
{   
    int division;
    int divident;
    cin>>division;
    cin>>divident;
    f(division,divident);
    return 0;
}