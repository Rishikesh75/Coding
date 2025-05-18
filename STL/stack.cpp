#include<iostream>
#include<stack>
using namespace std;
void create_stack(stack<int> &s_1,int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the value:"<<endl;
        cin>>temp;
        s_1.push(temp);
    }
}
void display_stack(stack<int> s_1)
{
    while (!s_1.empty())
    {
        cout<<s_1.top()<<"\t";
        s_1.pop();
    }
    cout<<"\n";
}
void pushStack(stack<int>s,int value)
{
    s.push(value);
}
void popBack(stack<int>s)
{
    cout<<"Value Has been Removed:"<<s.top()<<endl;
    s.pop();
}
int main()
{
    int n;
    cin>>n;
    stack<int>s;
    create_stack(s,n);
    display_stack(s);
    return(0);
}