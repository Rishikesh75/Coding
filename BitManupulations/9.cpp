#include<iostream>
using namespace std;
int RemoveLastSetBit(int number)
{
    int temp = number;
    int value = 1;
    while(number !=0 && number !=1)
    {
        number = number >> 1;
        value = value << 1;
    }
    return (~value) & temp;
}
int main()
{
    int number;
    cin>>number;
    cout<<RemoveLastSetBit(number)<<endl;
    return 0;
}