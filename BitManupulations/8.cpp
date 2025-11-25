//Toggle The ith Bit
#include<iostream>
using namespace std;
int ToggleithBit(int num,int i)
{
    if(num & (1 << i) == 0)
    {
        num = num | (1<< i);
    }
    else if(num & (1 << i) == 1)
    {
        num = num & !(1 << i);
    }
    return num;
}
int main()
{
    int num;
    cin>>num;
    int i;
    cin>>i;
    cout<<"ToggleithBit:"<<ToggleithBit(num,i)<<endl;
    return 0;
}
