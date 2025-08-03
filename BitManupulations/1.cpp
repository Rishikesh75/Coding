#include<iostream>
#include <cmath>
using namespace std;

string reversestring(string s)
{
    string reversedstring = "";
    for(int i = s.length() - 1; i >= 0; i--)
    {
        reversedstring += s[i];
    }
    return reversedstring;
}

string Convert2Binary(int n)
{
    string temp = "";
    while (1)
    {
        if(n == 1 || n == 0)
        {
            temp = temp + static_cast<char>('0' + n);
            break;
        }
        int remainder = n % 2;
        n = n / 2;
        temp = temp + static_cast<char>('0' + remainder);
    }
    temp = reversestring(temp);
    return temp;
}
int ConvertToDecimal(string s)
{
    int value = 0;
    for(int i=0;i<s.length();i++)
    {
        value += (s[i] - '0') * pow(2, i);
    }
    return value;
}
int BitAndOperation(int a,int b)
{
        return a & b;
}
int BitOrOperation(int a,int b)
{
    return a | b;
}
int XorOperation(int a,int b)
{
    return a^b;
}
int BitshiftOperation(int a,int shift)
{
    int shiftvalue = a << shift;
    return shiftvalue;
}
int SwapNumber(int &a,int &b)
{
     a = a ^ b;
     b = a ^ b;
     a = a ^ b;
}
bool Checkithbitset()
{
    int a,i;
    cout<<"Enter the Value:";
    cin>>a;
    cout<<"Enter the Index:";
    cin>>i;
    int value = 1 << i;
    value = value & a;
    if(value == 0)
    {
        return false;
    }
    return true;
}   
int  Clearithbit()
{
    int a,i;
    cout<<"Enter the Value:";
    cin>>a;
    cout<<"Enter the Index:";
    cin>>i;
    int value = 1 << i;
    value = ~value;
    a = value & a;
    return a;
}
bool power2()
{
    int a;
    cout<<"Enter the Value:";
    cin>>a;
    if ((a & (a - 1)) == 0)
    {
        return true;
    }
    return false;
}
int NBits()
{
    int value;
    cout<<"Enter the Value:";
    cin>>value;
    int count = 0;
    while(value!=0)
    {
        if((value & 1) !=0)
        {
            count = count + 1;
        }
        value = value >> 1;
    }
    return count;
}
int main()
{
    // int a;
    // cout<<"Enter the Number to Convert into Binary:"<<endl;
    // cin>>a;
    // string ans = Convert2Binary(a);
    // cout << "BinaryNumber: " << ans << endl;
    // int value = ConvertToDecimal("1001");
    // cout<< "Decimal Number:"<<value<<endl;
    // int temp1,temp2;
    // cin>>temp1;
    // cin>>temp2;
    // SwapNumber(temp1,temp2);
    // cout<<temp1<<temp2<<endl;
    // cout<<Checkithbitset()<<endl;
    // int value = Clearithbit();
    // cout<<value<<endl;
    // cout<<power2()<<endl;
    cout<<NBits()<<endl;
    return 0;
}
