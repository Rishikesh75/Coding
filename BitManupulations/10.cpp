//Min no of Bit Flips Requried to Convert the Number
#include<iostream>
using namespace std;
int BitFlips(int number1,int number2)
{
    int count = 0;
    int temp = number1 ^ number2;
    while(temp!=0)
    {
        if(temp & 1 == 1)
        {
            count++;
        }
        temp = temp >> 1;
    }
    return count;
}
int main()
{
    int number1;
    int number2;
    cin>>number1;
    cin>>number2;
    cout<<BitFlips(number1,number2)<<endl;
    return 0;
}