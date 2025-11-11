//Convert to Binary or Deciamal
#include<iostream>
#include<algorithm>
#include <cmath>
using namespace std;
string Convert2Binary(int num)
{
    string ans = "";
    while(num!=0)
    {
        int rem = num % 2;
        ans = ans + char('0' + rem);
        num = num /2 ;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int convert2Decimal(string Binary)
{
    int value = 0;
    int index = 0;
    for(int i=Binary.length()-1;i>=0;i--)
    {
        value = value + int(Binary[i] - '0') * pow(2,index);
        index++;
    }
    return value;
}
// And : &   or : |  Xor : ^ NOT : ~ LeftShift:<< Rightshift: >>
int main()
{
    int num;
    cin>>num;
    cout<<Convert2Binary(num)<<endl;
    cout<<convert2Decimal(Convert2Binary(num))<<endl;
    return 0;
}