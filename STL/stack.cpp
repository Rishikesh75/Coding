/*
----Stack-----
s.push(val)
s.pop()
s.top()
s.size()
s.empty()
*/

#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int>s;
    s.push(1);
    s.pop();
    if(s.empty())
    {
        cout<<"stack is empty"<<endl;
    }
    cout<<s.top()<<endl;
    return 0;
}