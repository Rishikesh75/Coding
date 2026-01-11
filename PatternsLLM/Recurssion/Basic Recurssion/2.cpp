//Printing the Name N Times..
#include<iostream>
using namespace std;
int n;
void f(int Currentvalue)
{  
    if(Currentvalue == n)
    {
        return;
    }
    cout<<"Rishi"<<endl;
    f(Currentvalue+1);
}
int main()
{
    cin>>n;
    f(0);
    return 0;
}