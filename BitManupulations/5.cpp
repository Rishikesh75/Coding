// Clear ith Bit
#include<iostream>
using namespace std;
void clearithbit(int& num,int i)
{
    num = num & ~(1 << i);
}
int main()
{
    cout<<"Enter the Number:"<<endl;
    int num;
    cin>>num;
    cout<<"Enter the ith Bit:"<<endl;
    int i;
    cin>>i;
    clearithbit(num,i);
    cout<<"After Clearning the ith Bit:"<<num<<endl;
    return 0;
}