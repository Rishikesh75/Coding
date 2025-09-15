
//Factorial of a number n!
#include<iostream>
using namespace std;
int factorial(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return n*factorial(n-1);
}
int fibinociSequence(int n)
{
    if(n == 1) return 0;
    if(n == 2) return 1;
    return fibinociSequence(n-1) + fibinociSequence(n-2);
}
int sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    return n+sum(n-1);
}
void printnumber1ton(int value,int n)
{
    if(value == n+1)
    {
        cout<<"\n";
        return;
    }
    cout<<value<<"\t";
    value = value+1;
    printnumber1ton(value,n);
}
void printnumbernto1(int n)
{
    if(n == 0)
    {
        cout<<"\n";
        return;
    }
    cout<<n<<"\t";
    printnumbernto1(n-1);
}
bool Checkpalimdorme(string s,int start,int end)
{
    if(start>=end)
    {
        return true;
    }
    if(s[start] != s[end])
    {
        return false;
    }
    start = start + 1;
    end = end -1;
    return Checkpalimdorme(s,start,end);
}
void Reversestring(string &s,int index_1,int index_2)
{
    if(index_1>index_2)
    {
        return;
    }
    char c = s[index_1];
    s[index_1] = s[index_2];
    s[index_2]= c;
    index_1 = index_1 +1;
    index_2 = index_2 - 1;
    Reversestring(s,index_1,index_2);
}
void Digits(int n)
{
    if(n == 0)
    {
        cout<<"\n";
        return;
    }
    int digit = n %10;
    cout<<digit<<"\t";
    n = n/10;
    Digits(n);
}
int main()
{
    int n;
    cout<<"Enter the Number"<<endl;
    cin>>n;
    // cout<<factorial(n)<<endl;
    // cout<<fibinociSequence(n)<<endl;
    // cout<<sum(n)<<endl;
    // printnumber1ton(1,n);
    // printnumbernto1(n);
    // string ans;
    // cin>>ans;
    // cout<<Checkpalimdorme(ans,0,ans.length()-1)<<endl;
    // Reversestring(ans,0,ans.length()-1);
    // cout<<ans<<endl;
    Digits(n);
    return(0);
}